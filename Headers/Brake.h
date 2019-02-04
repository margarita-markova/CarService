//
// Created by dev on 4.2.19.
//

#ifndef AUTOSERVICE_BRAKE_H
#define AUTOSERVICE_BRAKE_H

#include <string>

using namespace std;

class Brake {
private:
    int skew_procent; //не менее 16% (процент уклона для стояночной тормозной системы)
public:
    Brake();

    int getSkewProcent() const;

    void setSkewProcent(int skew_procent);

    void GenerateBrake();

    virtual ~Brake();
};

#endif //AUTOSERVICE_BRAKE_H
