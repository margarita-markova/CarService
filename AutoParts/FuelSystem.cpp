//
// Created by dev on 4.2.19.
//

#include "../Headers/FuelSystem.h"
#include "../Headers/Utils.h"

FuelSystem::FuelSystem() {}

FuelSystem::~FuelSystem() {

}

bool FuelSystem::isIsSealed() const {
    return isSealed;
}

void FuelSystem::setIsSealed(bool isSealed) {
    FuelSystem::isSealed = isSealed;
}

int FuelSystem::getVolume() const {
    return volume;
}

void FuelSystem::setVolume(int volume) {
    FuelSystem::volume = volume;
}

