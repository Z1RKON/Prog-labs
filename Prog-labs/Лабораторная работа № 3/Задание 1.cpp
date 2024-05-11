#include <iostream>
#include <string>

using namespace std;

class Движение {
public:
    double скорость;
    int время;

    Движение(double скорость, int время) {
        this->скорость = скорость;
        this->время = время;
    }

    string getInfo() {
        return "Скорость: " + to_string(скорость) + " м/с, Время: " + to_string(время) + " мин";
    }

    double getDistance() {
        return скорость * время * 60;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    double скорость;
    int время;
    cout << "Введите скорость (м/с): ";
    cin >> скорость;
    cout << "Введите время (мин): ";
    cin >> время;
    Движение движение(скорость, время);

    cout << "Информация об объекте:\n" << движение.getInfo() << endl;
    cout << "Пройденное расстояние: " << движение.getDistance() << " м" << endl;

    return 0;