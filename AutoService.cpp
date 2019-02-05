//
// Created by dev on 4.2.19.
//

#include "Headers/AutoService.h"
#include "Headers/Utils.h"

using namespace std;

AutoService::AutoService() {}

AutoService::~AutoService() {

}

void AutoService::InspectCar() {
    for (auto it = this->clients.begin(); it != clients.end(); it++) {
        int i = 0, waiting_flag = 0, repairing_flag = 0;
        this->garage_journal.insert(pair<Auto, status>((*it), in_progress));
        if (it->getParts().wheel[i].getHeightProtector() < Utils::values.min_protector_height) {
            if (CheckDetails()) {
                RepairWheel(*it, i);
                repairing_flag++;
            } else
                waiting_flag++;
        }
        if (it->getParts().brake.getSkewProcent() < Utils::values.min_skew) {
            if (CheckDetails()) {
                RepairBrake(*it);
                repairing_flag++;
            } else
                waiting_flag++;
        }
        if (!it->getParts().fuel_system.getIsSealed()) {
            if (CheckDetails()) {
                RepairFuelSystem(*it);
                repairing_flag++;
            } else
                waiting_flag++;
        }
        if (it->getParts().fuel_system.getVolume() <= Utils::values.min_volume) {
            if (CheckDetails()) {
                RepairFuelSystem(*it);
                repairing_flag++;
            } else waiting_flag++;
        }
        if (it->getParts().steering.getBacklash() > Utils::values.min_backlash) {
            if (CheckDetails()) {
                RepairSteering(*it);
                repairing_flag++;
            } else waiting_flag++;
        }
        if (!it->getParts().headlights.getIsClean()) {
            if (CheckDetails()) {
                RepairHeadlights(*it);
                repairing_flag++;
            } else waiting_flag++;
        }
        if (waiting_flag > 0) {
            this->garage_journal.insert(pair<Auto, status>((*it), waiting));
        } else if (repairing_flag > 0) {
            this->garage_journal.insert(pair<Auto, status>((*it), finished));
        } else {
            this->garage_journal.insert(pair<Auto, status>((*it), without_problems));
        }
    }
    this->clients.clear();
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

void AutoService::RepairWheel(Auto &car, int i) {
    car.getParts().wheel[i].setHeightProtector(Utils::GenerateInt(Utils::values.min_protector_height, Utils::values.max_protector_height));
}

void AutoService::RepairSteering(Auto &car) {
    car.getParts().steering.setBacklash(Utils::GenerateInt(Utils::values.min_backlash, Utils::values.max_backlash));
}

void AutoService::RepairHeadlights(Auto &car) {
    car.getParts().headlights.setIsClean(true);
}

void AutoService::RepairFuelSystem(Auto &car) {
    car.getParts().fuel_system.setVolume(Utils::GenerateInt(Utils::values.min_volume, Utils::values.max_volume));
    car.getParts().fuel_system.setIsSealed(true);
}

void AutoService::RepairBrake(Auto &car) {
    car.getParts().brake.setSkewProcent(Utils::GenerateInt(Utils::values.min_skew, Utils::values.max_skew));
}
