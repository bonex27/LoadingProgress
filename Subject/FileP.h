//
// Created by pbone on 04/12/2023.
//

#ifndef LOADINGPROGRESS_FILEP_H
#define LOADINGPROGRESS_FILEP_H


#include <QString>
#include <string>
#include <utility>
#include <ostream>
class FileP {

public:

    FileP( std::string name,  std::string path): name(name),path(path){}
     std::string getName() const {
         return name;
     }

    std::string getPath() const{
         return path;
     }

    bool operator==(const FileP &rhs) const {
        return rhs.name == this->name;
    }

    bool operator!=(const FileP &rhs) const {
        return rhs.name != this->name;
    }

private:
const std::string name;
const std::string path;
int size;
};


#endif //LOADINGPROGRESS_FILEP_H
