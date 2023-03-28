//
// Created by Pietro Bonechi on 28/03/23.
//
#include <iostream>
#include "Logger.h"

void Logger::update(int percentage) {
    status = percentage;
    display();
}
void Logger::display(){
    std::cout << status << "%";
}
