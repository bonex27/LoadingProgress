//
// Created by Pietro Bonechi on 28/03/23.
//

#ifndef LOADINGPROGRESS_OBSERVER_H
#define LOADINGPROGRESS_OBSERVER_H


class Observer {

protected:
    virtual ~Observer() {};
public:
    virtual void update() = 0;
};



#endif //LOADINGPROGRESS_OBSERVER_H
