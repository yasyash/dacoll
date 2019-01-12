#include "connectdialog.h"
#include "ui_connectdialog.h"

connectDialog::connectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::connectDialog)
{
    ui->setupUi(this);
}

connectDialog::~connectDialog()
{
    delete ui;
}

QString connectDialog::serverName() const
{
    return ui->serverName->text();
}

QString connectDialog::dbName() const
{
    return ui->dbName->text();
}
QString connectDialog::uName() const
{
    return ui->uName->text();
}
QString connectDialog::pName() const
{
    return ui->pName->text();
}
int connectDialog::port() const
{
    return ui->portName->text().toInt();
}
