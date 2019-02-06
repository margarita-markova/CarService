/**
 * @author Margarita Markova
 * @date 4.2.19
 *
 * @mainpage В методе main - тестовый пример работы автосервиса.
 * Структура проекта базируется на "Has-A Relationship", а именно - композиции и агрегации. В автосервисе имеются авто,
 * в авто имеются автозапчасти, что выражено наличием соответствующих полей (или структур) внутри классов
 */

#include <iostream>
#include <list>
#include <zconf.h>
#include "Headers/Utils.h"
#include "Headers/Auto.h"
#include "Headers/AutoService.h"

int main() {

    /**
    * Cоздается несколько объектов-автомобилей класса Auto
    */
    Auto * car = new Auto("green", 2233, "BMV");
    Auto * car1 = new Auto("green", 2253, "Toyota");
    Auto * car2 = new Auto("blue", 2243, "Ford");
    Auto * car3 = new Auto("white", 2153, "Fiat");
    Auto * car4 = new Auto("green", 1253, "Jeely");
    Auto * car5 = new Auto("red", 777, "Mersedes");

    /**
    * Для того, чтобы передать автомобиль в автосервис, необходимо создать список с авто.
    * В список garage пушим созданные объекты автомобиля
    */
    list<Auto> garage;
    garage.push_front(*car);
    garage.push_back(*car1);
    garage.push_back(*car2);
    garage.push_back(*car3);
    garage.push_back(*car4);
    garage.push_back(*car5);

    /**
    * Автомобили отправляются на проверку, исходный список очищается. В консоль - вывод журнала автосервиса с данными
    * о машине и ее статусе в автосервисе
    */
    AutoService * service = new AutoService();
    service->setClients(garage);
    if (service->InspectCar()) {
    service->GetJournalNotes();
    }
    garage.clear();

    /**
    * Машины со статусом waiting продолжают ремонтироваться вместе с поступившими в автосервис машинами, не проходившими
    * проверку, после вызова InspectCar()
    */
    Auto * car6 = new Auto("green", 1453, "Jeely");
    Auto * car7 = new Auto("red", 7776, "Mersedes");
    garage.push_back(*car6);
    garage.push_back(*car7);
    service->setClients(garage);
    if (service->InspectCar()) {
        service->GetJournalNotes();
    }
    //TODO: use destructors
    delete(service);
    delete(car, car1, car2, car3, car4, car7, car6, car5);
   // Utils::ConvertToJson(garage);
   // AutoService * service = new AutoService("miu.txt");
    return 0;
}