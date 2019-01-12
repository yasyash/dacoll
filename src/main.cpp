/*
 * main.cpp - main file for Modbus Data Fetcher
 *
 * Copyright (c) 2018-2019 Yaroslav Shkliar, ILIT.RU
 *
 * This file is part of Modbus Data Fetcher
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */


#include <QApplication>
#include "mainwindow.h"

MainWindow * globalMainWin = NULL;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

    QApplication::setOrganizationName( "Research Lab of IT" );
    QApplication::setOrganizationDomain( "ilit.ru" );
    QApplication::setApplicationName( "MODBUS_DATA_COLLECTOR" );

	MainWindow w;
	w.show();

	globalMainWin = &w;

	return a.exec();
}
