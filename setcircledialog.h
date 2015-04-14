#ifndef SETCIRCLEDIALOG_H
#define SETCIRCLEDIALOG_H

#include <QDialog>

namespace Ui {
class SetCircleDialog;
}

class SetCircleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetCircleDialog(QWidget *parent = 0);
    ~SetCircleDialog();

private:
    Ui::SetCircleDialog *ui;

private slots:
    void setCentre();
    void setSize();

signals:
    void changeCentre(const QPointF &point);
    void changeSize(qreal w, qreal h);
};

#endif // SETCIRCLEDIALOG_H
