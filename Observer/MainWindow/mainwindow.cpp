//
// Created by Pietro Bonechi on 04/04/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(FileLoader* fl, QWidget *parent) :
        fl(fl), QMainWindow(parent), ui(new Ui::MainWindow) {
        ui->setupUi(this);
        ui->lblActual->setText("Actual file");
        ui->lblTotal->setText("Files to load");
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
    ui->pbTotal->setValue(fl->getLoadedFile());
}

void MainWindow::on_loadFileButton_click() {
    if(fl->getFileToLoadLenght() > 0){
        ui->pbActual->setMaximum(4);
        ui->pbTotal->setMaximum(fl->getFileToLoadLenght());
        fl->loadFile();
    }
    else
        QMessageBox::warning(this,"Warning", "You need to select one or more file");


}

void MainWindow::on_selectFileButton_click() {

        QList<QUrl> fileNames = QFileDialog::getOpenFileUrls(this, tr("Select files to load"), QUrl(),
                                                              tr("Image Files (*.png *.jpg  *.txt)"));
        for (auto file: fileNames) {

            if(!fl->addFile(File(file.fileName(),file.path())))
                QMessageBox::warning(this,"Warning", file.fileName()+" just loaded");
        }

}

