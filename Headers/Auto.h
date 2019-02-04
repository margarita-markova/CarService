//
// Created by dev on 4.2.19.
//

#ifndef AUTOSERVICE_AUTO_H
#define AUTOSERVICE_AUTO_H

#include <string>
#include "Wheel.h"
#include "Brake.h"
#include "FuelSystem.h"
#include "Steering.h"
#include "Headlights.h"

using namespace std;

class Auto {
private:
    string color;
    int number;
    string model;
public:
    struct AutoParts {
        Wheel wheel[4];
        Brake brake;
        FuelSystem fuel_system;
        Steering steering;
        Headlights headlights;
        AutoParts();
        void ConvertToJson();
        void GenerateStructValues();

        //TODO: деструктор для элементов структуры
    };

    void getStatistics(); //получение общей информации каждого элемента структуры

    //TODO: список элементов для замены или целых

    Auto(const string &color, int number, const string &model);

    virtual ~Auto();

    const string &getColor() const;

    void setColor(const string &color);

    int getNumber() const;

    void setNumber(int number);

    const string &getModel() const;

    void setModel(const string &model);

};

#endif //AUTOSERVICE_AUTO_H
