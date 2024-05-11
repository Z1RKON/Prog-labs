#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class Прямоугольник {
public:
    int x1, y1, x2, y2;

    Прямоугольник() {
        x1 = y1 = x2 = y2 = 0;
    }

    Прямоугольник(int x1, int y1, int x2, int y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }

    ~Прямоугольник() {
        cout << "Объект Прямоугольник уничтожен!" << endl;
    }

    bool isSquare() {
        return x1 == x2 && y1 == y2;
    }

    void draw(HDC hdc) {
        HBRUSH brush = CreateSolidBrush(RGB(0, 255, 0));
        SelectObject(hdc, brush);
        Rectangle(hdc, x1, y1, x2, y2);

        DeleteObject(brush);
    }

    string getInfo() {
        return "Прямоугольник: (" + to_string(x1) + ", " + to_string(y1) + "), (" + to_string(x2) + ", " + to_string(y2) + ")";
    }
};

int main() {
    Прямоугольник прямоугольник1(10, 10, 20, 20);

    int x1, y1, x2, y2;
    cout << "Введите координаты прямоугольника (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    Прямоугольник прямоугольник2(x1, y1, x2, y2);

    cout << "Информация об объекте 1:\n" << прямоугольник1.getInfo() << endl;
    cout << "Является ли прямоугольник квадратом? " << (прямоугольник1.isSquare() ? "Да" : "Нет") << endl;

    cout << "\nИнформация об объекте 2:\n" << прямоугольник2.getInfo() << endl;
    cout << "Является ли прямоугольник квадратом? " << (прямоугольник2.isSquare() ? "Да" : "Нет") << endl;

    HDC hdc = GetDC(GetConsoleWindow());
    прямоугольник1.draw(hdc);
    прямоугольник2.draw(hdc);
    ReleaseDC(GetConsoleWindow(), hdc);

    return 0;
}