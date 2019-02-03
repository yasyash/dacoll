#ifndef UPS_STATUS_H
#define UPS_STATUS_H

#include <QWidget>

namespace Ui {
class ups_status;
}

class ups_status : public QWidget
{
    Q_OBJECT

public:
    explicit ups_status(QWidget *parent = nullptr);
    ~ups_status();

private:
    Ui::ups_status *ui;
};

#endif // UPS_STATUS_H
