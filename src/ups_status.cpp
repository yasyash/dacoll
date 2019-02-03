#include "ups_status.h"
#include "ui_ups_status.h"
#include <nutclient.h>

using namespace nut;


ups_status::ups_status(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ups_status)
{
    ui->setupUi(this);

    try
    {
        // Connection
        Client* client = new TcpClient("localhost", 3493);
        Device mydev = client->getDevice("dummy");
        ui->upsStatusTextEdit->setPlainText(QString::fromStdString(mydev.getDescription() + "\n"));
        Variable var1 = mydev.getVariable("device.model");
        //ui->upsStatusTextEdit->setPlainText(QString::fromStdString( var1.getValue()[0] + + "\n"));
        Variable var2 = mydev.getVariable("outlet.2.voltage");
        ui->upsStatusTextEdit->setPlainText(QString::fromStdString( var1.getValue()[0] +  "\n " + var2.getValue()[0] +  "\n"));
    }
    catch(NutException& ex)
    {
        ui->upsStatusTextEdit->setPlainText(QString::fromStdString( "Unexpected problem : " + ex.str()));
    }

}

ups_status::~ups_status()
{
    delete ui;
}
