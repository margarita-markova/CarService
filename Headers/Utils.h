/**
 * @author Margarita Markova
 * @date 4.2.19
 * @class Utils
 */

#ifndef AUTOSERVICE_UTILS_H
#define AUTOSERVICE_UTILS_H


#include <list>
#include "Auto.h"
#include <string>

using namespace std;

static int min_backlash = 0;
static int min_skew = 16;
static int min_volume = 8;
static int min_protector_height = 2;
static int max_backlash = 10;
static int max_skew = 40;
static int max_volume = 100;
static int max_protector_height = 10;

static bool DEBUG_MODE = true;

class Utils {
public:

    static bool GenerateBool();

    static int GenerateInt(int border);

    static int GenerateInt(int left, int right);

    static void ConvertToJson(list<Auto> &garage);

    template <class T>
    static string GetClassName(T &tclass);
};


#endif //AUTOSERVICE_UTILS_H
