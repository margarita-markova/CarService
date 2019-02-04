//
// Created by dev on 4.2.19.
//

#ifndef AUTOSERVICE_STEERING_H
#define AUTOSERVICE_STEERING_H

#include <string>

using namespace std;

class Steering {
private:
    int backlash; //люфт
public:
    Steering();

    virtual ~Steering();

    int getBacklash() const;

    void setBacklash(int backlash);

    void GenerateSteering();
};

#endif //AUTOSERVICE_STEERING_H
