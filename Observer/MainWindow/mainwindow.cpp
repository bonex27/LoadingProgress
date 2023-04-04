//
// Created by Pietro Bonechi on 04/04/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->pbActual->setValue(0);
    ui->pbTotal->setValue(0);
}

MainWindow::~MainWindow() {
    delete ui;
}

