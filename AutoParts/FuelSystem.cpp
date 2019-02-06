/**
 * @author Margarita Markova
 * @date 4.2.19
 * @class FuelSystem - часть структуры AutoParts. Главные параметры для "ремонта" и отображения состояния - герметичность и объем бака,
 * которые должны быть, соответственно, (условно) true и не менее значения static-переменной min_xxx
 */

#include "../Headers/FuelSystem.h"
#include "../Headers/Utils.h"
#include <iostream>

FuelSystem::FuelSystem() {}

FuelSystem::~FuelSystem() {

}

bool FuelSystem::getIsSealed() const {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return isSealed;
}

void FuelSystem::setIsSealed(bool isSealed) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    FuelSystem::isSealed = isSealed;
}

int FuelSystem::getVolume() const {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return volume;
}

void FuelSystem::setVolume(int volume) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    FuelSystem::volume = volume;
}

