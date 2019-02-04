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
    class AutoParts {
    public:
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
private:
    AutoParts parts;

    void getStatistics(); //получение общей информации каждого элемента структуры

    //TODO: список элементов для замены или целых

    void GenerateWheel(); //random values

    void GenerateSteering();

    void GenerateHeadlights();

    void GenerateFuelSystem();

    void GenerateBrake();

    Auto(const string &color, int number, const string &model);

    virtual ~Auto();

    const string &getColor() const;

    int getNumber() const;

    const string &getModel() const;

    const AutoParts &getParts() const;

    //void setParts(const AutoParts &parts);

};

#endif //AUTOSERVICE_AUTO_H
