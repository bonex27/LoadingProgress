//
// Created by Pietro Bonechi on 28/03/23.
//

#include "ResourcesLoader.h"

void ResourcesLoader::registerObserver(Observer *o) {
    observers.push_back(o);
}

void ResourcesLoader::removeObserver(Observer *o) {
    observers.remove(o);
}

void ResourcesLoader::notifyObservers() const {
    for (auto itr = observers.begin(); observers.end() != itr; ++itr) {
        (*itr)->update(loadingStatus);
    }
}

