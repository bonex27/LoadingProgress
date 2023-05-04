//
// Created by Pietro Bonechi on 04/04/23.
//

#ifndef LOADINGPROGRESS_MAINWINDOW_H
#define LOADINGPROGRESS_MAINWINDOW_H

#include <QMainWindow>
#include "Subject/FileLoader.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public Observer {
Q_OBJECT

public:
    explicit MainWindow(FileLoader* il, QWidget *parent = nullptr);

    void update() override;

    ~MainWindow() override;
private slots:
    void on_loadFileButton_click();
    void on_selectFileButton_click();
private:
    Ui::MainWindow *ui;
    FileLoader *fl;
};


#endif //LOADINGPROGRESS_MAINWINDOW_H
