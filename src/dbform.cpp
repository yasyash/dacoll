#include "dbform.h"
#include "ui_dbform.h"
#include "connectdialog.h"

Q_LOGGING_CATEGORY(QT_QM_ASCII_DB, "qm_ascii_db.tst")


dbForm::dbForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dbForm)
{

    ui->setupUi(this);

    connect( ui->connectButton, SIGNAL( clicked() ), this, SLOT( onConnectDB() ) );          //connect to table
    // connect( ui->applyButton, SIGNAL( clicked() ),
    //      this->model, SLOT( this->model->submitAll() ) );     //apply changes to table


}

dbForm::~dbForm()
{
    delete ui;
    //query->finish();
    //query->~QSqlQuery();
    // delete query;
    //conn->close();
    //conn->~QSqlDatabase();
    //delete  conn;
}

void dbForm::onConnectDB(void)
{
    QSqlRecord rec;

    if (!conn.isOpen())
    {
        connectDialog dialog(this);

        if (dialog.exec() != QDialog::Accepted)
            return;

        conn = QSqlDatabase::addDatabase("QPSQL");
        conn.setHostName(dialog.serverName());
        conn.setDatabaseName(dialog.dbName());
        conn.setUserName(dialog.uName());
        conn.setPassword(dialog.pName());
        bool status = conn.open();

        if (!status)
        {
            qCDebug(QT_QM_ASCII_DB) <<"err =" << conn.lastError().text();

            emit on_msg_err(conn.lastError().text());
            return;
        }
        //query = new QSqlQuery(conn);
        //query->exec("select * from equipments where is_present = true and measure_class = data");
        //rec = query->record();

        QSqlTableModel *model = new CustomModel(ui->tableView, conn);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->setTable(conn.driver()->escapeIdentifier("equipments", QSqlDriver::TableName));
        model->setFilter("measure_class = 'data'");
        model->select();
        if (model->lastError().type() != QSqlError::NoError)
        {
            qCDebug(QT_QM_ASCII_DB) <<"err =" <<  model->lastError().text();

            emit on_msg_err( model->lastError().text());
            return;
        }

        ui->tableView->setModel(model);
        ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        connect(ui->applyButton, SIGNAL( clicked()),model, SLOT( submitAll() ));

        emit(on_conn_send_main(&conn));
        qCDebug(QT_QM_ASCII_DB) <<"con =" << status << " query = " << rec.count();
    } else {


    }
}
