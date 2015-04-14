#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QFileDialog>
#include "workspace.h"
#include "setcircledialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    WorkSpace* _workSpace;
    SetCircleDialog* _setCircleDialog;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void showSetCircleDialog();
    void openFile();
};

#endif // MAINWINDOW_H
