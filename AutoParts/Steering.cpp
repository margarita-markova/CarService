/**
 * @author Margarita Markova
 * @date 4.2.19
 * @class Steering - часть структуры AutoParts. Главный параметр для "ремонта" и отображения состояния - люфт,
 * который должен быть (условно) не более значения static-переменной min_xxx
 */


#include "../Headers/Steering.h"
#include "../Headers/Utils.h"
#include <iostream>

Steering::Steering() {}

Steering::~Steering() {

}

int Steering::getBacklash() const {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return backlash;
}

void Steering::setBacklash(int backlash) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    Steering::backlash = backlash;
}


