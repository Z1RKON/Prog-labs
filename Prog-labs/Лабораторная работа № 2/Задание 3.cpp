//ЗАДАЧА 3

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cout << "Не удалось открыть входной файл!" << endl;
        return 1;
    }

    ofstream upperFile("upper.txt");
    if (!upperFile.is_open()) {
        cout << "Не удалось открыть файл для больших букв!" << endl;
        return 1;
    }

    ofstream lowerFile("lower.txt");
    if (!lowerFile.is_open()) {
        cout << "Не удалось открыть файл для малых букв!" << endl;
        return 1;
    }

    int digitCount = 0;

    char ch;
    while (inputFile.get(ch)) {
        if (isupper(ch)) {
            upperFile.put(ch);
        }
        else if (islower(ch)) {
            lowerFile.put(ch);
        }
        else if (isdigit(ch)) {
            digitCount++;
        }
    }

    inputFile.close();
    upperFile.close();
    lowerFile.close();

    cout << "Количество цифр: " << digitCount << endl;

    return 0;
