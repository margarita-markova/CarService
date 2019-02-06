//
// Created by dev on 4.2.19.
//

#ifndef AUTOSERVICE_AUTOSERVICE_H
#define AUTOSERVICE_AUTOSERVICE_H

#include "Auto.h"
#include <list>
#include <iterator>
#include <map>

enum status {without_problems, waiting, in_progress, finished};

class AutoService {
private:
    bool isDetails;
    list <Auto> clients;
    map<Auto*, status> garage_journal;

protected:
    bool getIsDetails() const;

    void setIsDetails(bool isDetails);

public:

    AutoService();

    void InspectCar();

    bool CheckDetails();

    void RepairWheel(Auto &car, int num);

    void RepairSteering(Auto &car);

    void RepairHeadlights(Auto &car);

    void RepairFuelSystem(Auto &car);

    void RepairBrake(Auto &car);

    virtual ~AutoService();
};


#endif //AUTOSERVICE_AUTOSERVICE_H
