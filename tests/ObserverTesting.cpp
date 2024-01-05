#include "../Interfaces/Observer.h"
#include "../Subject/FileLoader.h"
#include "gtest/gtest.h"




//
// Created by pbone on 05/01/2024.
//
class CountObserver : public Observer {


public:
    CountObserver(int fileToLoad,FileLoader* fl) {
        this->fl = fl;
        fl->registerObserver(this);
        //Aggiunge n file
        for(int i = 0; i< fileToLoad; i++) {
            fl->addFile({std::to_string(i),std::to_string(i)});
        }
    }

    ~CountObserver() override {
        fl->removeObserver(this);
    };
    void startLoading() {
        fl->loadFile();
    }
    void update() override {
        //loadedFile = fl->getLoadedFile();
        if(fl->getLoadedFile()>prevLoadedFile) {
            prevLoadedFile++;
            updateCall++;
        }
    }
    int getUpdateNumberCall() {
        return updateCall;
    }
private:
    FileLoader *fl;
    int updateCall = 0;
    int prevLoadedFile = 0;
};

TEST(Observer, updateCall) {
    FileLoader fl;
    CountObserver co(2,&fl);
    co.startLoading();
    ASSERT_EQ(co.getUpdateNumberCall(),2);
}
