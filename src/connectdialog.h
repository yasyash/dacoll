#ifndef CONNECTDIALOG_H
#define CONNECTDIALOG_H

#include <QDialog>

namespace Ui {
class connectDialog;
}

class connectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit connectDialog(QWidget *parent = nullptr);
    ~connectDialog();

    QString serverName()const;
    QString dbName() const;
    QString uName() const;
    QString pName() const;
    int port() const;

private slots:
    void on_okButton_clicked() { accept(); }
    void on_cancelButton_clicked() { reject(); }

private:
    Ui::connectDialog *ui;
};

#endif // CONNECTDIALOG_H
