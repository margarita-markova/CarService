/**
 * @author Margarita Markova
 * @date 4.2.19
 *
 * @class Brake - часть структуры AutoParts. Главный параметр для "ремонта" и отображения состояния - процент уклона
 * (кот. должна выдерживать стояночная тормозная система...),
 * которая должна быть (условно) не менее значения static-переменной min_xxx
 */

#include "../Headers/Brake.h"
#include "../Headers/Utils.h"
#include <iostream>

Brake::Brake() {}

Brake::~Brake() {

}

int Brake::getSkewProcent() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return skew_procent;
}

void Brake::setSkewProcent(int skew_procent) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    Brake::skew_procent = skew_procent;
}
