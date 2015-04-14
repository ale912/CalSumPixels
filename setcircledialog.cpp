#include "setcircledialog.h"
#include "ui_setcircledialog.h"

SetCircleDialog::SetCircleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetCircleDialog)
{
    ui->setupUi(this);

    connect(ui->lineEditCentreX, SIGNAL(textChanged(QString)), SLOT(setCentre()));
    connect(ui->lineEditCentreY, SIGNAL(textChanged(QString)), SLOT(setCentre()));
    connect(ui->lineEditWidth, SIGNAL(textChanged(QString)), SLOT(setSize()));
    connect(ui->lineEditHeight, SIGNAL(textChanged(QString)), SLOT(setSize()));

    ui->lineEditCentreX->setText("0");
    ui->lineEditCentreY->setText("0");
    ui->lineEditWidth->setText("100");
    ui->lineEditHeight->setText("100");
}

SetCircleDialog::~SetCircleDialog()
{
    delete ui;
}

void SetCircleDialog::setCentre()
{
    emit changeCentre(QPointF(ui->lineEditCentreX->text().toDouble(), ui->lineEditCentreY->text().toDouble()));
}

void SetCircleDialog::setSize()
{
    emit changeSize(ui->lineEditWidth->text().toDouble(), ui->lineEditHeight->text().toDouble());
}
