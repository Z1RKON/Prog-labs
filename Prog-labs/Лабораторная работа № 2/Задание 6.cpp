//ЗАДАЧА 6

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("f.txt");
    if (!inputFile.is_open()) {
        cout << "Не удалось открыть исходный файл!" << endl;
        return 1;
    }

    ofstream outputFile("g.txt");
    if (!outputFile.is_open()) {
        cout << "Не удалось открыть новый файл!" << endl;
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();

    cout << "Копия файла успешно создана!" << endl;

    return 0;
}