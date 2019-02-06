/**
 * @author Margarita Markova
 * @date 4.2.19
 * @class Steering
 */

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
};

#endif //AUTOSERVICE_STEERING_H
