//
// Created by Pietro Bonechi on 28/03/23.
//

#ifndef LOADINGPROGRESS_SUBJECT_H
#define LOADINGPROGRESS_SUBJECT_H


#include "Observer.h"

class Subject {
protected:
    virtual ~Subject() {};
public:
    virtual void registerObserver( Observer* o ) = 0;
    virtual void removeObserver( Observer* o ) = 0;
    virtual void notifyObservers() const = 0;
};


#endif //LOADINGPROGRESS_SUBJECT_H
