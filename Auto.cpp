/**
 * @author Margarita Markova
 * @date 4.2.19
 * @class Auto
 */

#include "Headers/Auto.h"
#include "Headers/Utils.h"
#include "Headers/AutoService.h"
#include <iostream>
#include <map>

using namespace std;

Auto::AutoParts::AutoParts() {}

Auto::AutoParts::~AutoParts() {

}

/**
 * При создании объекта машины автоматически генерируются значения AutoParts
 * @param color
 * @param number
 * @param model
 */
Auto::Auto(const string &color, int number, const string &model) : color(color), number(number), model(model) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< " " << color << " " << number << " " << model << endl;
    this->GenerateStruct();
}

Auto::AutoParts &Auto::getParts() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return parts;
}

const string &Auto::getColor() const {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return color;
}

int Auto::getNumber() const {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return number;
}

const string &Auto::getModel() const {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return model;
}

/**
 * Методы GenerateXXX - генерация рандомных значений для AutoParts
 */
void Auto::GenerateWheel() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    for (int i = 0; i < 4; i++) {
        this->parts.wheel[i].setHeightProtector(Utils::GenerateInt(max_protector_height));
    }
}

void Auto::GenerateSteering() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    this->parts.steering.setBacklash(Utils::GenerateInt(max_backlash));
}

void Auto::GenerateHeadlights() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    this->parts.headlights.setIsClean(Utils::GenerateBool());
}

void Auto::GenerateFuelSystem() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    this->parts.fuel_system.setVolume(Utils::GenerateInt(max_volume));
    this->parts.fuel_system.setIsSealed(Utils::GenerateBool());
}

void Auto::GenerateBrake() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    this->parts.brake.setSkewProcent(Utils::GenerateInt(max_skew));
}

Auto::~Auto() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;

}

void Auto::GenerateStruct() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    this->GenerateSteering();
    this->GenerateHeadlights();
    this->GenerateWheel();
    this->GenerateFuelSystem();
    this->GenerateBrake();
}

/**
 * Получение информации о машине
 */
void Auto::GetCarInfo() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    cout << "Statistics " << endl;
    cout << "Model: " << this->getModel() << endl;
    cout << "Color: " << this->getColor() << endl;
    cout << "Number: " << this->getNumber() << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Wheel height protector: " << this->getParts().wheel[i].getHeightProtector() << endl;
    }
    cout << "Brake skew procent: " << this->getParts().brake.getSkewProcent() << endl;
    cout << "Fuel system is sealed: " << this->getParts().fuel_system.getIsSealed() << " and volume:"<< this->getParts().fuel_system.getVolume()  << endl;
    cout << "Headlights is clean: " << this->getParts().headlights.getIsClean() << endl;
    cout << "Steering backlash: " << this->getParts().steering.getBacklash() << endl;
}

Auto* Auto::getObject() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return this;
}


