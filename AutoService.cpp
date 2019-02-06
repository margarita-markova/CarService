/**
 * @author Margarita Markova
 * @date 4.2.19
 * @class AutoService
 */


#include <fstream>
#include <iostream>
#include "Headers/AutoService.h"
#include "Headers/Utils.h"

using namespace std;

AutoService::AutoService() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
}

AutoService::~AutoService() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
//    for (auto it = this->clients.begin(); it!=this->clients.end(); it++)
//    delete(it->getObject());
//    this->clients.clear();
//    for (auto it = this->clients.begin(); it!=this->clients.end(); it++)
//        delete(it->getObject());
//    garage_journal.clear();
}

/**
 * xxx_flag - для определения статуса машины.
 * Если с запчастью машины все хорошо, идем мимо.
 * Если она требует ремонта, то мы проверяем наличие деталей. Если они есть - чиним и поднимаем флаг починки.
 * Если деталей нет - поднимаем флаг ожидания.
 * Машины со статусом waiting остаются в списке клиентов, а машины со статусами finished и without_problems.
 * Таким образом, в списке clients остаются только машины, требующие ремонта или проверки.
 * удаляются из списка клиентов. Все машины, прошедшие проверку, независимо от статуса остаются в "журнале" - map<Auto*, status>
 *
 * @return bool
 */
bool AutoService::InspectCar() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    for (auto it = this->clients.begin(); it != clients.end(); it++) {
        int i = 0, waiting_flag = 0, repairing_flag = 0;
        if (it->getParts().wheel[i].getHeightProtector() < min_protector_height) {
            if (CheckDetails()) {
                RepairWheel(it->getObject(), i);
                repairing_flag++;
            } else {
                waiting_flag++;
            }
        }
        if (it->getParts().brake.getSkewProcent() < min_skew) {
            if (CheckDetails()) {
                RepairBrake(it->getObject());
                repairing_flag++;
            } else
                waiting_flag++;
        }
        if (!it->getParts().fuel_system.getIsSealed()) {
            if (CheckDetails()) {
                RepairFuelSystem(it->getObject());
                repairing_flag++;
            } else
                waiting_flag++;
        }
        if (it->getParts().fuel_system.getVolume() <= min_volume) {
            if (CheckDetails()) {
                RepairFuelSystem(it->getObject());
                repairing_flag++;
            } else waiting_flag++;
        }
        if (it->getParts().steering.getBacklash() > min_backlash) {
            if (CheckDetails()) {
                RepairSteering(it->getObject());
                repairing_flag++;
            } else waiting_flag++;
        }
        if (!it->getParts().headlights.getIsClean()) {
            if (CheckDetails()) {
                RepairHeadlights(it->getObject());
                repairing_flag++;
            } else waiting_flag++;
        }
        if (DEBUG_MODE) cout << "rep flag: " << repairing_flag << " wait flag: " << waiting_flag << endl;
        if (waiting_flag > 0) {
            this->garage_journal.insert(pair<Auto*, status>((*it).getObject(), waiting));
        } else if (repairing_flag > 0) {
            this->garage_journal.insert(pair<Auto*, status>((*it).getObject(), finished));
            this->clients.erase(it);
            it--;
        } else {
            this->garage_journal.insert(pair<Auto*, status>((*it).getObject(), without_problems));
            this->clients.erase(it);
            it--;
        }
    }
    if (DEBUG_MODE) cout << garage_journal.size() << endl << clients.size() << endl;
    return true;
}

/**
 * Генерация наличия деталей на складе
 * @return
 */
bool AutoService::CheckDetails() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    setIsDetails(Utils::GenerateBool());
    return getIsDetails();
}

bool AutoService::getIsDetails() const {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return isDetails;
}

void AutoService::setIsDetails(bool isDetails) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< isDetails << endl;
    AutoService::isDetails = isDetails;
}

/**
 * Установка необходимых для колеса параметров (метод ремонта)
 * @param car
 * @param i
 */
void AutoService::RepairWheel(Auto *car, int i) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< i << endl;
    car->getParts().wheel[i].setHeightProtector(Utils::GenerateInt(min_protector_height, max_protector_height));
}

/**
 * Установка необходимых для рулевого управления параметров (метод ремонта)
 * @param car
 */
void AutoService::RepairSteering(Auto *car) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    car->getParts().steering.setBacklash(Utils::GenerateInt(min_backlash, max_backlash));
}

/**
 * Установка необходимых для фар параметров (метод ремонта)
 * @param car
 */
void AutoService::RepairHeadlights(Auto *car) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    car->getParts().headlights.setIsClean(true);
}

/**
 * Установка необходимых для топливной системы параметров (метод ремонта)
 * @param car
 */
void AutoService::RepairFuelSystem(Auto *car) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    car->getParts().fuel_system.setVolume(Utils::GenerateInt(min_volume, max_volume));
    car->getParts().fuel_system.setIsSealed(true);
}

/**
 * Установка необходимых для тормозной системы параметров (метод ремонта)
 * @param car
 */
void AutoService::RepairBrake(Auto *car) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    car->getParts().brake.setSkewProcent(Utils::GenerateInt(min_skew, max_skew));
}

/**
 * Конструктор, принимающий название файла, для того, чтобы загрузить аргументы инициализации (color, model, number)
 * для создания объекта (или объектов) Auto, которые будут помещены в список clients
 * @param filename
 */
AutoService::AutoService(string filename) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< filename << endl;
    fstream src;
    src.open(filename.c_str(), ios::in);
    string word, model, color;
    int number = 0;
    while (src >> word) {
        //if json //TODO: load garage from file
        cout << word << endl;
        try {
            number = atoi(word.c_str());
            cout << "n " << number << endl;
        }
        catch (int e) {

        }
        if(model.empty() && number == 0) {
            model = word;
        }
        else if (color.empty() && number == 0) color = word;
        if (number!=0 && !color.empty() && !model.empty()) {
            Auto * car = new Auto(color, number, model);
            this->clients.push_back(*car);
        }
    }
    src.close();
}

list<Auto> &AutoService::getClients() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return clients;
}

/**
 * Добавление в список клиентов новых авто (с проверкой на наличие в списке waiting-машин)
 * @param clients
 */
void AutoService::setClients(list<Auto> &clients) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    if (!AutoService::clients.empty()) {
        auto it = AutoService::clients.begin();
        AutoService::clients.insert(it, clients.begin(), clients.end());
    }
    else AutoService::clients = clients;
}

/**
 * Получение полной информации о машинах, прошедших проверку
 */
void AutoService::GetJournalNotes() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    cout << "Garage Journal Notes" << endl;
    for (auto it = garage_journal.begin(); it != garage_journal.end(); it++) {
        cout << "********************************" << endl;
        it->first->GetCarInfo();
        switch (it->second) {
            case waiting:
                cout << "Status: waiting details" << endl;
                break;
            case without_problems:
                cout << "Status: without problems, car was inspected" << endl;
                break;
            case finished:
                cout << "Status: car was repaired, finished" << endl;
                break;
            default:
                cout << "Car isn't inspected" << endl;
                break;
        }
        cout << "********************************" << endl;
    }
}

