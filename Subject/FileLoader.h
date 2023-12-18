//
// Created by pbone on 04/05/2023.
//

#ifndef LOADINGPROGRESS_FILELOADER_H
#define LOADINGPROGRESS_FILELOADER_H

#include <list>
#include <string>
#include "../Interfaces/Subject.h"
#include "FileP.h"

class FileLoader : public Subject{

public:
    bool addFile(const FileP& f);
    bool removeFile(const std::string& name);
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
    std::list<FileP> fileDb;
    int currentLoadingProgress{0};
    int loadedFile{0};
};


#endif //LOADINGPROGRESS_FILELOADER_H
