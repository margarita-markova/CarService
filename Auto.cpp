//
// Created by dev on 4.2.19.
//

#include "Headers/Auto.h"
#include "Headers/Utils.h"
#include "Headers/AutoService.h"
#include <iostream>
#include <map>

using namespace std;

//методы замены данных в структуре - это сет

Auto::AutoParts::AutoParts() {}

Auto::AutoParts::~AutoParts() {

}

Auto::Auto(const string &color, int number, const string &model) : color(color), number(number), model(model) {}

Auto::AutoParts &Auto::getParts() {
    return parts;
}

const string &Auto::getColor() const {
    return color;
}

int Auto::getNumber() const {
    return number;
}

const string &Auto::getModel() const {
    return model;
}

void Auto::GenerateWheel() {
    for (int i = 0; i < 4; i++) {
        this->parts.wheel[i].setHeightProtector(Utils::GenerateInt(Utils::values.max_protector_height));
    }
}

void Auto::GenerateSteering() {
    this->parts.steering.setBacklash(Utils::GenerateInt(Utils::values.max_backlash));
}

void Auto::GenerateHeadlights() {
    this->parts.headlights.setIsClean(Utils::GenerateBool());
}

void Auto::GenerateFuelSystem() {
    this->parts.fuel_system.setVolume(Utils::GenerateInt(Utils::values.max_volume));
    this->parts.fuel_system.setIsSealed(Utils::GenerateBool());
}

void Auto::GenerateBrake() {
    this->parts.brake.setSkewProcent(Utils::GenerateInt(Utils::values.max_skew));
}

Auto::~Auto() {

}

void Auto::GenerateStruct() {
    this->GenerateSteering();
    this->GenerateHeadlights();
    this->GenerateWheel();
    this->GenerateFuelSystem();
    this->GenerateBrake();
}

void Auto::GetCarInfo() {
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
