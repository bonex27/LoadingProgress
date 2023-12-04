//
// Created by pbone on 04/12/2023.
//

#ifndef LOADINGPROGRESS_FILE_H
#define LOADINGPROGRESS_FILE_H


#include <QString>

class File {
private:
    const QString name;
    const QString path;
    int size;
public:
    File(const QString &name, const QString &path);

    bool operator==(const File &rhs) const;

    bool operator!=(const File &rhs) const;
};


#endif //LOADINGPROGRESS_FILE_H
