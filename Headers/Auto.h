//
// Created by dev on 4.2.19.
//

#ifndef AUTOSERVICE_AUTO_H
#define AUTOSERVICE_AUTO_H

#include <string>
#include <list>
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
protected:
    struct AutoParts {
        Wheel wheel[4];
        Brake brake;
        FuelSystem fuel_system;
        Steering steering;
        Headlights headlights;

        AutoParts();

        ~AutoParts();
    };
private:
    AutoParts parts;
public:
    Auto* getObject();

    void GetCarInfo();

    void GenerateWheel(); //random values

    void GenerateSteering();

    void GenerateHeadlights();

    void GenerateFuelSystem();

    void GenerateBrake();

    void GenerateStruct();

    Auto(const string &color, int number, const string &model);

    virtual ~Auto();

    const string &getColor() const;

    int getNumber() const;

    const string &getModel() const;

    AutoParts &getParts();

};

#endif //AUTOSERVICE_AUTO_H
