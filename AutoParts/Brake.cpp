//
// Created by dev on 4.2.19.
//

#include "../Headers/Brake.h"
#include "../Headers/Utils.h"

Brake::Brake() {}

Brake::~Brake() {

}

int Brake::getSkewProcent() {
    return skew_procent;
}

void Brake::setSkewProcent(int skew_procent) {
    Brake::skew_procent = skew_procent;
}
