#include <iostream>
#include <list>
#include <zconf.h>
#include "Headers/Utils.h"
#include "Headers/Auto.h"
#include "Headers/AutoService.h"

int main() {
    //TODO: menu
    list<Auto> garage;
    Auto * car = new Auto("green", 2233, "BMV");
    Auto * car1 = new Auto("green", 2253, "Toyota");
    Auto * car2 = new Auto("blue", 2243, "Ford");
    Auto * car3 = new Auto("white", 2153, "Fiat");
    Auto * car4 = new Auto("green", 1253, "Jeely");
    Auto * car5 = new Auto("red", 777, "Mersedes");
    for (int i = 0; i < 4; i++) {
        car1->getParts().wheel[i].setHeightProtector(3);
    }
    car1->getParts().brake.setSkewProcent(30);
    car1->getParts().fuel_system.setIsSealed(1);
    car1->getParts().fuel_system.setVolume(20);
    car1->getParts().headlights.setIsClean(1);
    car1->getParts().steering.setBacklash(4);
    garage.push_front(*car);
    garage.push_back(*car1);
    garage.push_back(*car2);
    garage.push_back(*car3);
    garage.push_back(*car4);
    garage.push_back(*car5);
//    cout << "Cars info" << endl;
//    for(auto it = garage.begin(); it != garage.end(); it++) {
//        cout << "--------------" << endl;
//        it->GetCarInfo();
//        cout << "--------------" << endl;
//    }
    AutoService * service = new AutoService();
    service->setClients(garage);
    if (service->InspectCar()) {
    service->GetJournalNotes();
    }

   // Utils::ConvertToJson(garage);
   // string t = typeid(car->getParts().wheel[1]).name();
   // cout << t.substr(1, t.size()-1);
   // cout << typeid(car->getParts().wheel[1]).name();
    return 0;
}