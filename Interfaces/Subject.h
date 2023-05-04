//
// Created by Pietro Bonechi on 28/03/23.
//

#ifndef LOADINGPROGRESS_SUBJECT_H
#define LOADINGPROGRESS_SUBJECT_H

#include <list>
#include "Observer.h"

class Subject {


public:
    virtual void registerObserver( Observer* o ) {
        this->observers.push_back(o);
    }
    virtual void removeObserver( Observer* o ) {
        this->observers.push_back(o);
    }
    virtual void notifyObservers(){
        for(const auto o : observers)
        {
            o->update();
        }
    }
    virtual ~Subject() {};
private:
    std::list<Observer*> observers;
};


#endif //LOADINGPROGRESS_SUBJECT_H
