#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_tpMteo.h"
#include "K8055Adapter.h"
#include <QTimer>
#include <windows.h>
#include <qdebug.h>
#include <QSqlDatabase>
#include <QtSql/QtSql>
#include <QSqlQuery>
#include <QtSql>


class tpMteo : public QMainWindow
{
    Q_OBJECT

public:
    tpMteo(QWidget *parent = Q_NULLPTR);

public slots:
	void On();
	void Off();
	void timerOn();
	void timerOff();
	void getValue();

private:
    Ui::tpMteoClass ui;
	
	K8055Adapter * card;
	QTimer *timer1;
	QTimer *timer2;
	bool connectBDD;

};
