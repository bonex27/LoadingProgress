//
// Created by Pietro Bonechi on 28/03/23.
//

#ifndef LOADINGPROGRESS_RESOURCESLOADER_H
#define LOADINGPROGRESS_RESOURCESLOADER_H

#include <list>
#include "Subject.h"
#include <iterator>
class ResourcesLoader: public Subject {
private:

    std::list<Observer *> observers;
    int loadingStatus;

public:
    ResourcesLoader() : loadingStatus(0) {};

    void registerObserver(Observer *o) override;

    void removeObserver(Observer *o) override;

    void notifyObservers() const override;

    void UpdateData(int value) {
        loadingStatus = value;
        notifyObservers();

    }
};



#endif //LOADINGPROGRESS_RESOURCESLOADER_H
