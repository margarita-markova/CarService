#include <iostream>
#include "Headers/Utils.h"

int main() {
    //TODO: menu
    for (int i=0; i < 1000; i++) {
        bool h = Utils::GenerateBool();
        int r = Utils::GenerateInt(23);
       // float z = Utils::GenerateFloat(2.658);
        std::cout << h  << " " << r  <<  std::endl;
    }
    return 0;
}