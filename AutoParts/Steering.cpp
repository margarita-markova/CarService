//
// Created by dev on 4.2.19.
//


#include "../Headers/Steering.h"
#include "../Headers/Utils.h"

Steering::Steering() {}

Steering::~Steering() {

}

int Steering::getBacklash() const {
    return backlash;
}

void Steering::setBacklash(int backlash) {
    Steering::backlash = backlash;
}


