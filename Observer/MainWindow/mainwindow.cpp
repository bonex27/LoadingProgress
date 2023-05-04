//
// Created by Pietro Bonechi on 04/04/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_MainWindow.h"

//Todo Check if file just exist and  throw exception if don't select file

MainWindow::MainWindow(FileLoader* fl, QWidget *parent) :
        fl(fl), QMainWindow(parent), ui(new Ui::MainWindow) {
        ui->setupUi(this);
        ui->pbActual->setValue(0);
        ui->pbTotal->setValue(0);
        fl->registerObserver(this);
        connect(ui->btnLoad, SIGNAL(clicked()), this,SLOT(on_loadFileButton_click()));
        connect(ui->btnSelect, SIGNAL(clicked()), this,SLOT(on_selectFileButton_click()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::update() {
    ui->pbActual->setValue(fl->getCurrentLoadingProgress());

}

void MainWindow::on_loadFileButton_click() {
    fl->getCurrentLoadingProgress();
}

void MainWindow::on_selectFileButton_click() {
    //try {
        QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Select files to load"), "",
                                                              tr("Image Files (*.png *.jpg  *.txt)"));
        for (auto file: fileNames) {
            QFileInfo fileInfo(file);
            if(!fl->addFile(fileInfo))
                QMessageBox::warning(this,"Warning", fileInfo.fileName()+" just exist");
        }
//    }
  //  catch(Exce)
}

