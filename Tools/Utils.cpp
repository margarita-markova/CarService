/**
 * @author Margarita Markova
 * @date 4.2.19
 * @class Utils - вспомогательный класс, предоставляющий статические методы и переменные
 */

#include "../Headers/Utils.h"
#include "../Headers/Auto.h"
#include <random>
#include <functional>
#include <list>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/**
 * Методы GenerateXXX - для генерации рандомного значения определенного типа с определенным диапазоном
 * значений случайных чисел
 */
bool Utils::GenerateBool() {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    return GenerateInt(0, 1);
}

int Utils::GenerateInt(int border) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< " " << border << endl;
    return GenerateInt(0, border);
}

int Utils::GenerateInt(int left, int right) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< " " << left << " " << right << endl;
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(left, right);
    return distribution(rd);
}

/**
 * Dummy Json converter - по условию необходимо поддерживать конвертацию структуры AutoParts в json
 * Метод записывает результат работы в файл, позволяет пользователю просмотреть результат в консоли
 * @param garage - список объектов Auto для получения структур AutoParts
 */
void Utils::ConvertToJson(list<Auto> &garage) {
    if (DEBUG_MODE) cout <<__PRETTY_FUNCTION__<< endl;
    auto it = garage.begin();
    ofstream myfile;
    myfile.open("autoparts.json");
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
    cout << "Конвертировано. Хотите увидеть содержание файла autoparts.json? Введите Y или y, если да" << endl;
    char choice;
    cin >> choice;
    if (choice == 'Y' || choice == 'y') {

        fstream in;
        in.open("autoparts.json");
        string line;
        while (getline(in, line)) {
            cout << line << endl;
        }
        in.close();
    }
}


