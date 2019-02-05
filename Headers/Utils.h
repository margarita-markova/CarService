//
// Created by dev on 4.2.19.
//

#ifndef AUTOSERVICE_UTILS_H
#define AUTOSERVICE_UTILS_H


#include <list>
#include "Auto.h"
#include <string>

using namespace std;

class Utils {
public:
    static struct Values {
        int min_backlash = 0;
        int min_skew = 16;
        int min_volume = 8;
        int min_protector_height = 2;
        int max_backlash = 10;
        int max_skew = 40;
        int max_volume = 100;
        int max_protector_height = 10;
    } values;

    static bool GenerateBool();

    static int GenerateInt(int border);

    static int GenerateInt(int left, int right);

    static void ConvertToJson(list<Auto> &garage);

    template <class T>
    static string GetClassName(T &tclass);
};


#endif //AUTOSERVICE_UTILS_H
