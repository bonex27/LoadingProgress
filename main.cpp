
#include <QApplication>

#include "Observer/MainWindow/mainwindow.h"


int main(int argc, char *argv[]) {
        FileLoader f;

        QApplication a(argc, argv);
        MainWindow w(&f);
        w.show();
        return QApplication::exec();
    }