//
// Created by dev on 4.2.19.
//

#ifndef AUTOSERVICE_AUTOSERVICE_H
#define AUTOSERVICE_AUTOSERVICE_H

#include "Auto.h"
#include <list>
#include <iterator>

enum status {waiting, in_progress, finished};

class AutoService {
private:
    bool isDetails();
    list <Auto> garage;

public:
    AutoService();



    virtual ~AutoService();
};


#endif //AUTOSERVICE_AUTOSERVICE_H
