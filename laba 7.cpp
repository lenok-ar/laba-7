/*******************************
 * Автор: Арестова Е.Е.        *
 * Дата: 12.11.2024            *          
 *******************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 
#include <map>
#include <locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    ifstream lab7;
    lab7.open("C:/Users/User/Desktop/Лаба 7/lab 7.txt");

    map<char, int> bukva;
    map<string, int> paribykv;
    char pered;
    char posle = 0;

    while (lab7.get(pered)) {
        if (isalpha(pered)) {
            pered = tolower(pered);
            bukva[pered]++;

            if (isalpha(posle)) {
                posle = tolower(posle);
                paribykv[string(1, posle) + pered]++;
            }

            posle = pered;
        }
    }

    lab7.close();

    cout << "Частота букв " << endl;
    for (const auto& chastota : bukva) {
        cout << chastota.first << " = " << chastota.second << endl;
    }

    cout << "Частота двухбуквенных сочетаний " << endl;
    for (const auto& chastota : paribykv) {
        if (chastota.second / 2 > 0) {
            cout << chastota.first << " = " << chastota.second / 2 << endl;
        }
    }
    return 0;
}
