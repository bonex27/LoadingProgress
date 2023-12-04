//
// Created by pbone on 04/05/2023.
//

#include <thread>
#include "FileLoader.h"

void FileLoader::removeFile(File f) {
    //fileDb.remove(f);
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
bool FileLoader::addFile(const File f) {
    std::list<File>::iterator findIter = std::find(fileDb.begin(), fileDb.end(), f);
    if(findIter != fileDb.end())
        return false;
    fileDb.push_back(f);
    return true;
}
/**
 * This function simulate files loading and update the current file loading status and  files waiting to be loaded
**/
void FileLoader::loadFile() {

    loadedFile = 0;
    for(int i = 0; i < fileDb.size() ; i++)
    {
        currentLoadingProgress = 0;
        notifyObservers();
        for(int j = 0; j < 4 ; j++)
        {
            std::this_thread::sleep_for (std::chrono::seconds(2));
            currentLoadingProgress++;
            notifyObservers();
        }
        notifyObservers();

        std::this_thread::sleep_for (std::chrono::seconds(1));
        loadedFile++;
        notifyObservers();
    }
    fileDb.clear();
}
