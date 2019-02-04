//
// Created by dev on 4.2.19.
//

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

    void GenerateHeadlights();

    virtual ~Headlights();
};

#endif //AUTOSERVICE_HEADLIGHTS_H
