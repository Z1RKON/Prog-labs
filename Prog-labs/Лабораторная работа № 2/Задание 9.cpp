#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    vector<int> numbers;
    int num;

    cout << "Введите целые числа (для завершения введите -1):" << endl;
    while (true) {
        cin >> num;
        if (num == -1) break;
        numbers.push_back(num);
    }

    ofstream file("numbers.bin", ios::binary);
    for (int i = 0; i < numbers.size(); i++) {
        file.write((char*)&numbers[i], sizeof(int));
    }
    file.close();

    ifstream file2("numbers.bin", ios::binary);
    vector<int> updatedNumbers;
    while (file2.read((char*)&num, sizeof(int))) {
        updatedNumbers.push_back(num * 2);
    }
    file2.close();

    cout << "Числа до изменения в файле:" << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "Числа после изменения в файле:" << endl;
    for (int i = 0; i < updatedNumbers.size(); i++) {
        cout << updatedNumbers[i] << " ";
    }
    cout << endl;

    return 0;
}




