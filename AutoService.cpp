//
// Created by dev on 4.2.19.
//

#include <fstream>
#include <iostream>
#include "Headers/AutoService.h"
#include "Headers/Utils.h"

using namespace std;

AutoService::AutoService() {}

AutoService::~AutoService() {

}

bool AutoService::InspectCar() {
    for (auto it = this->clients.begin(); it != clients.end(); this->clients.pop_front(), it = this->clients.begin()) {
        int i = 0, waiting_flag = 0, repairing_flag = 0;
        //this->garage_journal.insert(pair<Auto*, status>((*it).getObject(), in_progress));
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
        cout << "rep flag: " << repairing_flag << " wait flag: " << waiting_flag << endl;
        if (waiting_flag > 0) {
            this->garage_journal.insert(pair<Auto*, status>((*it).getObject(), waiting));
            //this->clients.push_back((*it).getObject()); //push back, pop front
        } else if (repairing_flag > 0) {
            this->garage_journal.insert(pair<Auto*, status>((*it).getObject(), finished));
//            this->clients.pop_front();
//            it = this->clients.begin();
        } else {
            this->garage_journal.insert(pair<Auto*, status>((*it).getObject(), without_problems));
//            this->clients.pop_front();
//            it = this->clients.begin();
        }
    }
    cout << garage_journal.size();
    return true;
   // this->clients.clear();
}

bool AutoService::CheckDetails() {
    setIsDetails(Utils::GenerateBool());
    return getIsDetails();
}


bool AutoService::getIsDetails() const {
    return isDetails;
}

void AutoService::setIsDetails(bool isDetails) {
    AutoService::isDetails = isDetails;
}

void AutoService::RepairWheel(Auto *car, int i) {
    car->getParts().wheel[i].setHeightProtector(Utils::GenerateInt(min_protector_height, max_protector_height));
}

void AutoService::RepairSteering(Auto *car) {
    car->getParts().steering.setBacklash(Utils::GenerateInt(min_backlash, max_backlash));
}

void AutoService::RepairHeadlights(Auto *car) {
    car->getParts().headlights.setIsClean(true);
}

void AutoService::RepairFuelSystem(Auto *car) {
    car->getParts().fuel_system.setVolume(Utils::GenerateInt(min_volume, max_volume));
    car->getParts().fuel_system.setIsSealed(true);
}

void AutoService::RepairBrake(Auto *car) {
    car->getParts().brake.setSkewProcent(Utils::GenerateInt(min_skew, max_skew));
}

AutoService::AutoService(char *filename) {
    fstream src;
    src.open(filename, ios::in);
    string word;
    while (src >> word) {
        //if json //TODO: load garage from file
        //if file with words
    }
}

list<Auto> &AutoService::getClients() {
    return clients;
}

void AutoService::setClients(list<Auto> &clients) {
    if (!AutoService::clients.empty()) {
        auto it = AutoService::clients.begin();
        AutoService::clients.insert(it, clients.begin(), clients.end());
    }
    else AutoService::clients = clients;
}

void AutoService::GetJournalNotes() {
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
            case in_progress:
                cout << "Status: car is inspecting, in progress" << endl;
                break;
            default:
                cout << "Car isn't inspected" << endl;
                break;
        }
        cout << "********************************" << endl;
    }
}

