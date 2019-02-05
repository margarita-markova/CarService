//
// Created by dev on 4.2.19.
//

#include "../Headers/Utils.h"
#include "../Headers/Auto.h"
#include <random>
#include <functional>
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

bool Utils::GenerateBool() { //date chet nechet
    time_t timer;
    time(&timer);
    return timer % 2 == 0 ? false : true;
}

int Utils::GenerateInt(int border) {
    srand(time(NULL));
    return (rand() % border);
}

int Utils::GenerateInt(int left, int right) {
    srand(time(NULL));
    return (rand() % right + left);
}

void Utils::ConvertToJson(list<Auto> &garage) {
    auto it = garage.begin();
    ofstream myfile;
    myfile.open("json.txt");
    myfile << "{ \n";
   while (it != garage.end()) {
       myfile << "\t{ \n";
       for (int i = 0; i < 4; i++) {
           myfile << "\t\t \"wheel\" : { \n";
           myfile << "\t\t\t \"protector_height\" : " << it->getParts().wheel[i].getHeightProtector() << "\n";
           myfile << "\t\t } \n";
       }
       myfile << "\t\t \"brake\" : { \n";
       myfile << "\t\t\t \"skew_procent\" : " << it->getParts().brake.getSkewProcent() << "\n";
       myfile << "\t\t } \n";
       myfile << "\t\t \"steering\" : { \n";
       myfile << "\t\t\t \"backlash\" : " << it->getParts().steering.getBacklash() << "\n";
       myfile << "\t\t } \n";
       myfile << "\t\t \"headlights\" : { \n";
       myfile << "\t\t\t \"is_clean\" : " << it->getParts().headlights.getIsClean() << "\n";
       myfile << "\t\t } \n";
       myfile << "\t\t \"fuel_system\" : { \n";
       myfile << "\t\t\t \"volume\" : " << it->getParts().fuel_system.getVolume() << "\n";
       myfile << "\t\t\t \"is_sealed\" : " << it->getParts().fuel_system.getIsSealed() << "\n";
       myfile << "\t\t } \n";
       myfile << "\t} \n";
       // }
       ++it;
   }
    myfile << "}";
    myfile.close();
    fstream in;
    in.open("json.txt");
    string line;
    while(getline(in, line)) {
        cout << line << endl;
    }
    in.close();
}

template<class T>
string Utils::GetClassName(T &tclass) {
    string class_name = typeid(tclass).name();
    return class_name;//class_name.substr(1, class_name.size()-1);
}


