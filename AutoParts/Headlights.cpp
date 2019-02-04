//
// Created by dev on 4.2.19.
//

#include "../Headers/Headlights.h"
#include "../Headers/Utils.h"

Headlights::Headlights() {}

Headlights::~Headlights() {

}

bool Headlights::getIsClean() const {
    return isClean;
}

void Headlights::setIsClean(bool isClean) {
    Headlights::isClean = isClean;
}

void Headlights::GenerateHeadlights() {
    this->Headlights::setIsClean(Utils::GenerateBool());
}
