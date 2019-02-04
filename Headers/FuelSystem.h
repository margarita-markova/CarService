//
// Created by dev on 4.2.19.
//

#ifndef AUTOSERVICE_FUELSYSTEM_H
#define AUTOSERVICE_FUELSYSTEM_H

#include <string>

using namespace std;

class FuelSystem {
private:
    bool isSealed; //герметичность
    int volume;
public:
    FuelSystem();

    int getVolume() const;

    void setVolume(int volume);

    bool isIsSealed() const;

    void setIsSealed(bool isSealed);

    virtual ~FuelSystem();
};

#endif //AUTOSERVICE_FUELSYSTEM_H
