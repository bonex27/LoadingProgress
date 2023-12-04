//
// Created by pbone on 04/05/2023.
//

#ifndef LOADINGPROGRESS_FILELOADER_H
#define LOADINGPROGRESS_FILELOADER_H

#include <list>
#include <QFileInfo>

#include "Interfaces/Subject.h"
#include "File.h"

class FileLoader : public Subject{

public:
    bool addFile(File f);
    void removeFile(File f);
    int getCurrentLoadingProgress() const{
        return currentLoadingProgress;
    }
    int getLoadedFile() const{
        return loadedFile;
    }
    int getFileToLoadLenght()
    {
        return fileDb.size();
    }
    void loadFile();
private:
    std::list<File> fileDb;
    int currentLoadingProgress{0};
    int loadedFile{0};
};


#endif //LOADINGPROGRESS_FILELOADER_H
