/**
 * @author Margarita Markova
 * @date 4.2.19
 * @class Headlights
 */

#ifndef AUTOSERVICE_HEADLIGHTS_H
#define AUTOSERVICE_HEADLIGHTS_H

#include <string>

using namespace std;

class Headlights {
private:
    bool isClean;
public:
    Headlights();

    bool getIsClean() const;

    void setIsClean(bool isClean);

    virtual ~Headlights();
};

#endif //AUTOSERVICE_HEADLIGHTS_H
