//
// Created by dev on 4.2.19.
//

#ifndef AUTOSERVICE_WHEEL_H
#define AUTOSERVICE_WHEEL_H

#include <string>
//#include "ThorSerialize/JsonThor.h"

using namespace std;

class Wheel {
private:
    float height_protector; //min 1.6 mm
public:
    Wheel();

    float getHeightProtector();

    void setHeightProtector(float height_protector);

    virtual ~Wheel();
};

#endif //AUTOSERVICE_WHEEL_H
