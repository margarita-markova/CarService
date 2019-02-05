#include <iostream>
#include <list>
#include "Headers/Utils.h"
#include "Headers/Auto.h"

int main() {
    //TODO: menu
    list<Auto> garage;
    Auto * car = new Auto("green", 2233, "BMV");
    Auto * car1 = new Auto("green", 2253, "Toyota");
    car->GenerateStruct();
    car1->GenerateStruct();
    garage.push_front(*car);
    garage.push_back(*car1);
    //car->getStatistics();
    //&car = *car;
    //cout << Utils::GetClassName((*car).getParts().brake);

   // Utils::ConvertToJson(garage);
   // string t = typeid(car->getParts().wheel[1]).name();
   // cout << t.substr(1, t.size()-1);
   // cout << typeid(car->getParts().wheel[1]).name();
    return 0;
}