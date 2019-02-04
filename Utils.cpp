//
// Created by dev on 4.2.19.
//

#include "Headers/Utils.h"
#include <random>
#include <functional>

using namespace std;

bool Utils::GenerateBool() {
    srand(time(NULL));
    if ((rand() % 2) == 0) {
        return false;
    }
    else
        return true;
}

int Utils::GenerateInt(int border) {
    srand(time(NULL));
    return (rand() % border);
}

//float Utils::GenerateFloat(float border) {
//    srand(time(NULL));
//    return ((rand() % (int)(border * 10)) / 10);
//}
