#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _workSpace = new WorkSpace;
    QScrollArea* scrollArea = new QScrollArea;
    //scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(_workSpace);
    setCentralWidget(scrollArea);

    _setCircleDialog = new SetCircleDialog(this);
    connect(_setCircleDialog, SIGNAL(changeCentre(QPointF)), _workSpace, SLOT(setCircleCentre(QPointF)));
    connect(_setCircleDialog, SIGNAL(changeSize(qreal,qreal)), _workSpace, SLOT(setCircleSize(qreal,qreal)));

    connect(ui->actionSetCircle, SIGNAL(triggered()), SLOT(showSetCircleDialog()));
    connect(ui->actionCreateMask, SIGNAL(triggered()), _workSpace, SLOT(createMask()));
    connect(ui->actionOpenFile, SIGNAL(triggered()), SLOT(openFile()));
    connect(ui->actionStart, SIGNAL(triggered()), _workSpace, SLOT(start()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showSetCircleDialog()
{
    _setCircleDialog->show();
    _setCircleDialog->raise();
    _setCircleDialog->activateWindow();
}

void MainWindow::openFile()
{
    QStringList files = QFileDialog::getOpenFileNames(0);
    files.sort();
    _workSpace->setPixmap(files);
}
