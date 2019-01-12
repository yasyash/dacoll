#ifndef DBFORM_H
#define DBFORM_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class dbForm;
}

class dbForm : public QWidget
{
    Q_OBJECT

public:
    explicit dbForm(QWidget *parent = nullptr);
    ~dbForm();

signals:
    void on_msg_err  ( const QString& );

private slots:
    void onConnectDB(void);

private:
    Ui::dbForm *ui;
    QSqlDatabase conn;
    QSqlTableModel *model;
    QSqlQuery *query;

};


class CustomModel: public QSqlTableModel
{
    Q_OBJECT
public:
    explicit CustomModel(QObject *parent = nullptr, QSqlDatabase db = QSqlDatabase())
        : QSqlTableModel(parent, db) {}

    QVariant data(const QModelIndex &idx, int role) const override
    {
        if (role == Qt::BackgroundRole && isDirty(idx))
            return QBrush(QColor(Qt::yellow));
        return QSqlTableModel::data(idx, role);
    }
};
#endif // DBFORM_H
