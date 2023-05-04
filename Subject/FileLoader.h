//
// Created by pbone on 04/05/2023.
//

#ifndef LOADINGPROGRESS_FILELOADER_H
#define LOADINGPROGRESS_FILELOADER_H

#include <list>
#include <QFileInfo>

#include "Interfaces/Subject.h"

class FileLoader : public Subject{

public:
    void loadFile(QFileInfo f);
    void removeFile(QFileInfo f);
    int getCurrentLoadingProgress() const{
        return currentLoadingProgress;
    }
private:
    std::list<QFileInfo> fileDb;
    int currentLoadingProgress{0};
    int loadedFile{0};
};


#endif //LOADINGPROGRESS_FILELOADER_H
