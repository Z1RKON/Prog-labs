//ЗАДАЧА 1

#include <iostream>
#include <queue>
#include <stack>


using namespace std;

// задание1
void countPositiveElements(queue<int> q) {
    setlocale(LC_ALL, "RUS");
    int count = 0;

    while (!q.empty()) {
        int front = q.front();
        if (front > 0) {
            count++;
        }
        q.pop();
    }

    cout << "Количество положительных элементов: " << count << endl;
}

void displayQueue(queue<int> q) {
    setlocale(LC_ALL, "RUS");
    cout << "Очередь: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// задание2
struct Mountain {
    string name;
    int height;
};

void addMountain(stack<Mountain>& s, string name, int height) {
    Mountain m;
    m.name = name;
    m.height = height;
    s.push(m);
}

void displayStack(stack<Mountain> s) {
    setlocale(LC_ALL, "RUS");
    cout << "Стек гор:\n";
    while (!s.empty()) {
        Mountain m = s.top();
        cout << "Гора: " << m.name << ", Высота: " << m.height << endl;
        s.pop();
    }
}

float averageMountainHeight(stack<Mountain> s) {
    int totalHeight = 0;
    int count = 0;

    while (!s.empty()) {
        Mountain m = s.top();
        totalHeight += m.height;
        count++;
        s.pop();
    }

    return (float)totalHeight / count;
}

int main() {
    setlocale(LC_ALL, "RUS");
    // задание1
    queue<int> q;
    q.push(3);
    q.push(-5);
    q.push(7);
    q.push(-2);

    countPositiveElements(q);
    displayQueue(q);

    // задание2
    stack<Mountain> mountains;

    addMountain(mountains, "Everest", 8849);
    addMountain(mountains, "K2", 8611);

    displayStack(mountains);

    float averageHeight = averageMountainHeight(mountains);
    cout << "Средняя высота гор: " << averageHeight << endl;

    return 0;
}
