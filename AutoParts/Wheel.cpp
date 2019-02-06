/**
 * @author Margarita Markova
 * @date 4.2.19
 * @class Wheel - часть структуры AutoParts. Главный параметр для "ремонта" и отображения состояния - высота протектора,
 * которая должна быть (условно) не менее значения static-переменной min_xxx
 */
#include "../Headers/Wheel.h"
#include "../Headers/Utils.h"
#include <iostream>

Wheel::Wheel() {}

Wheel::~Wheel() {

}

int Wheel::getHeightProtector() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return height_protector;
}

void Wheel::setHeightProtector(int height_protector) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< " " << height_protector << endl;
    Wheel::height_protector = height_protector;
}
