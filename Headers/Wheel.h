/**
 * @author Margarita Markova
 * @date 4.2.19
 * @class Wheel
 */

#ifndef AUTOSERVICE_WHEEL_H
#define AUTOSERVICE_WHEEL_H

#include <string>

using namespace std;

class Wheel {
private:
    int height_protector;
public:
    Wheel();

    int getHeightProtector();

    void setHeightProtector(int height_protector);

    virtual ~Wheel();
};

#endif //AUTOSERVICE_WHEEL_H
