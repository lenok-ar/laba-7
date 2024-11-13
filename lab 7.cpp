#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 
#include <map>
#include <locale>

// подключаем библиотеку
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    ifstream lab7;  // создаём объект класса ifstream
    lab7.open("lab 7.txt");
    // открываем файл

    map<char, int> bukva; // Частота букв
    map<string, int> parabykv;   // Частота пар букв
    char prevCh = '\0'; // Для хранения предыдущего символа
    char a;

    while (lab7.get(a)) { // Считываем текст из файла
        if (isalpha(a)) {
            a = tolower(a); // Приводим к нижнему регистру
            bukva[a]++; // Увеличиваем частоту буквы

            // Считаем пару, если предыдущий символ не нулевой
            if (prevCh) {
                parabykv[string(1, prevCh) + a]++;
            }
            prevCh = a; // Обновляем предыдущий символ
        }
    }

    lab7.close(); // Закрываем файл

    // Вывод частоты букв
    cout << "Частота букв:" << endl;
    for (const auto& entry : bukva) {
        cout << entry.first << ": " << entry.second << endl;
    }

    // Вывод частоты двухбуквенных сочетаний
    cout << "\nЧастота двухбуквенных сочетаний:" << endl;
    for (const auto& entry : parabykv) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
