//
// Created by dev on 4.2.19.
//

#include "../Headers/Wheel.h"
#include "../Headers/Utils.h"

Wheel::Wheel() {}

Wheel::~Wheel() {

}

float Wheel::getHeightProtector() const {
    return height_protector;
}

void Wheel::setHeightProtector(float height_protector) {
    Wheel::height_protector = height_protector;
}

void Wheel::GenerateWheel() {
    this->setHeightProtector(Utils::GenerateInt(10));
}

void Wheel::RepareWheel() {

}
