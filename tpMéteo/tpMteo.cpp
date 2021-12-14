//*********************************************************************************************
//* Programme : TPMétéo.cpp								Date : 14/12/2021
//*														Dernière MAJ : 14/12/2021
//*--------------------------------------------------------------------------------------------
//*Programmeurs :	CARE Alexandre							Classe : BTSSN2
//*					CAUET Clément
//*					DUVAL Kylian
//*--------------------------------------------------------------------------------------------
//*
//* BUT : Récupérer les données du Velman
//*
//*********************************************************************************************

#include "tpMteo.h"

tpMteo::tpMteo(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	card = K8055Adapter::getInstance();
	card->OpenDevice(0);

	ui.Off->setEnabled(false);
	QSqlDatabase BDD = QSqlDatabase::addDatabase("QMYSQL");
	BDD.setHostName("192.168.65.201");
	BDD.setUserName("user");
	BDD.setPassword("user");
	BDD.setDatabaseName("Velman");

	connectBDD = BDD.open();

	if (connectBDD == true) {
		qDebug() << "BDD : Nouvelle connexion";
	}
	else {
		qDebug() << "BDD: Erreur de connexion";
	}
}

/* Allume le Velman et initialise les valeurs */
void tpMteo::On()
{
	ui.On->setEnabled(false);
	ui.Off->setEnabled(true);

	timerOn();
}

/* Eteint le Velman et reset les valeurs */
void tpMteo::Off()
{
	ui.On->setEnabled(true);
	ui.Off->setEnabled(false);

	timerOff();
}

/* Démarrage de l'échantillonnage */
void tpMteo::timerOn()
{
	timer1 = new QTimer(this);
	QObject::connect(timer1, SIGNAL(timeout()), this, SLOT(getValue()));

	timer2 = new QTimer(this);
	QObject::connect(timer2, SIGNAL(timeout()), this, SLOT(timerOff()));

	timer1->start(1000);
	timer2->start(3000);
}

/* Coupure du timer */
void tpMteo::timerOff()
{
	QObject::disconnect(timer1, SIGNAL(timeout()), this, SLOT(getValue()));
	QObject::disconnect(timer2, SIGNAL(timeout()), this, SLOT(timerOff()));

	ui.On->setEnabled(true);
	ui.Off->setEnabled(false);
}

/* Récupération des valeurs */
void tpMteo::getValue()
{
	QString bruteValue = QString::number(card->ReadAnalogChannel(1));
	if (bruteValue > 0) {
		float valeurBrut = bruteValue.toFloat();
		float tensionValue = (valeurBrut / 255) * 5;
		float tempValue = (tensionValue * 90 / 5) - 30;

		QString tension = QString::number(tensionValue);
		QString temp = QString::number(tempValue);

		QSqlQuery query;
		query.exec("INSERT INTO `meteo`(`valeurBrut`, `tension`, `temperature`) VALUES(" + bruteValue + "," + tension + "," + temp + ")");

		ui.bruteValue->setText(bruteValue);
		ui.tension->setText(tension + " V");
		ui.temp->setText(temp + " °C");
	}
	else {
		ui.bruteValue->setText("NULL");
		ui.temp->setText("NULL");
	}
}

