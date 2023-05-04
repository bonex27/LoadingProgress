//
// Created by pbone on 04/05/2023.
//

#include "FileLoader.h"

void FileLoader::removeFile(QFileInfo f) {
    fileDb.remove(f);
    /*for(auto file : fileDb)
    {
        if(file.fileName() == f.fileName())
        {
            i=fileDb.erase(i);
            loadedFile++;
        }
        else
            i++;
    }*/
}

void FileLoader::loadFile(QFileInfo f) {

    fileDb.push_back(f);

}
