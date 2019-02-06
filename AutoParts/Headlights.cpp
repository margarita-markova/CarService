/**
 * @author Margarita Markova
 * @date 4.2.19
 * @class Headlights - часть структуры AutoParts. Главный параметр для "ремонта" и отображения состояния - чистота (фар),
 * которая должна быть true
 */

#include "../Headers/Headlights.h"
#include "../Headers/Utils.h"
#include <iostream>

Headlights::Headlights() {}

Headlights::~Headlights() {

}

bool Headlights::getIsClean() const {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return isClean;
}

void Headlights::setIsClean(bool isClean) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    Headlights::isClean = isClean;
}

