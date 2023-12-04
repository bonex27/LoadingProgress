//
// Created by pbone on 04/12/2023.
//

#include "File.h"

File::File(const QString &name, const QString &path) : name(name), path(path) {}

bool File::operator==(const File &rhs) const {
    return name == rhs.name &&
           path == rhs.path;
}

bool File::operator!=(const File &rhs) const {
    return !(rhs == *this);
}
