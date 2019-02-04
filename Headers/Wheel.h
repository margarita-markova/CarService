//
// Created by dev on 4.2.19.
//

#ifndef AUTOSERVICE_WHEEL_H
#define AUTOSERVICE_WHEEL_H

#include <string>

using namespace std;

class Wheel {
private:
    float height_protector; //min 1.6 mm
public:
    Wheel();

    float getHeightProtector() const;

    void setHeightProtector(float height_protector);

    void GenerateWheel(); //random values

    void RepareWheel(); //set needed values

    virtual ~Wheel();
};

#endif //AUTOSERVICE_WHEEL_H
