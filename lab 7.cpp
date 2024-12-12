#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 
#include <map>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    ifstream lab7;  
    lab7.open("lab 7.txt");

    map<char, int> bukva; 
    map<string, int> parabykv;   
    char prevCh = '\0'; 
    char a;

    while (lab7.get(a)) { 
        if (isalpha(a)) {
            a = tolower(a); 
            bukva[a]++;
            
            if (prevCh) {
                parabykv[string(1, prevCh) + a]++;
            }
            prevCh = a;
        }
    }

    lab7.close(); 

    cout << "Частота букв:" << endl;
    for (const auto& entry : bukva) {
        cout << entry.first << ": " << entry.second << endl;
    }

    cout << "\nЧастота двухбуквенных сочетаний:" << endl;
    for (const auto& entry : parabykv) {
        cout << entry.first << ": " << entry.second << endl;
    }

    return 0;
}
