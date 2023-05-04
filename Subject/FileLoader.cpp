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
/**
 *Insert file to load inside "db"
 * @param f file to be add
 * @return false if just exist
 * */
bool FileLoader::addFile(QFileInfo f) {

    std::list<QFileInfo>::iterator findIter = std::find(fileDb.begin(), fileDb.end(), f);
    if(findIter != fileDb.end())
        return false;
    fileDb.push_back(f);
    return true;
}
