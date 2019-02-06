/**
 * @author Margarita Markova
 * @date 4.2.19
 * @class Brake
 */

#ifndef AUTOSERVICE_BRAKE_H
#define AUTOSERVICE_BRAKE_H

#include <string>

using namespace std;

class Brake {
private:
    int skew_procent; //не менее 16% (процент уклона для стояночной тормозной системы)
public:
    Brake();

    int getSkewProcent();

    void setSkewProcent(int skew_procent);

    virtual ~Brake();
};

#endif //AUTOSERVICE_BRAKE_H
