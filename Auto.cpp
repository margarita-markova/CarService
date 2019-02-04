//
// Created by dev on 4.2.19.
//

#include "Headers/Auto.h"

//методы замены данных в структуре - это сет

void Auto::AutoParts::ConvertToJson() {
    //TODO: вывод "Конвертировано. Местоположение файла и название. Хотите посмотреть результат Д/н"
}

Auto::AutoParts::AutoParts() {
   GenerateStructValues();
}

Auto::Auto(const string &color, int number, const string &model) : color(color), number(number), model(model) {
 AutoParts auto_parts;
}

void Auto::getStatistics() {

}

const string &Auto::getColor() const {
    return color;
}

void Auto::setColor(const string &color) {
    Auto::color = color;
}

int Auto::getNumber() const {
    return number;
}

void Auto::setNumber(int number) {
    Auto::number = number;
}

const string &Auto::getModel() const {
    return model;
}

void Auto::setModel(const string &model) {
    Auto::model = model;
}

Auto::~Auto() {

}

void Auto::AutoParts::GenerateStructValues() {

    for (int i = 0; i < 4; i++) {
        this->wheel[i].GenerateWheel();
    }
    this->headlights.GenerateHeadlights();
    this->fuel_system.GenerateFuel();
    this->steering.GenerateSteering();
    this->brake.GenerateBrake();
}
