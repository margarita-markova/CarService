//
// Created by dev on 4.2.19.
//

#include "Headers/Auto.h"
#include "Headers/Utils.h"

//методы замены данных в структуре - это сет

void Auto::AutoParts::ConvertToJson() {
    //TODO: вывод "Конвертировано. Местоположение файла и название. Хотите посмотреть результат Д/н"
}

Auto::AutoParts::AutoParts() {}

Auto::Auto(const string &color, int number, const string &model) : color(color), number(number), model(model) {}

void Auto::getStatistics() {

}

const Auto::AutoParts &Auto::getParts() const {
    return parts;
}

//void Auto::setParts(const Auto::AutoParts &parts) {
//    Auto::parts = parts;
//}

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
        this->parts.wheel[i].setHeightProtector(Utils::GenerateInt(10));
    }
}

void Auto::GenerateSteering() {
    this->parts.steering.setBacklash(Utils::GenerateInt(100));
}

void Auto::GenerateHeadlights() {
    this->parts.headlights.setIsClean(Utils::GenerateBool());
}

void Auto::GenerateFuelSystem() {
    this->parts.fuel_system.setVolume(Utils::GenerateInt(100));
    this->parts.fuel_system.setIsSealed(Utils::GenerateBool());
}

void Auto::GenerateBrake() {
    this->parts.brake.setSkewProcent(Utils::GenerateInt(40));
}

Auto::~Auto() {

}
