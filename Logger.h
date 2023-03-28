//
// Created by Pietro Bonechi on 28/03/23.
//

#ifndef LOADINGPROGRESS_LOGGER_H
#define LOADINGPROGRESS_LOGGER_H


#include "Observer.h"
#include "Subject.h"

class Logger : public  Observer{
private:
    Subject* loadingStatus;
    int status;
    void display();

public:
    Logger(Subject* loadingStatus): loadingStatus(loadingStatus), status(0){
        loadingStatus->registerObserver(this);
    }
    ~Logger(){
        loadingStatus->removeObserver(this);
    }
    void update(int percentage) override;
};


#endif //LOADINGPROGRESS_LOGGER_H
