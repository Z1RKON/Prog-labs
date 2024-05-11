//ЗАДАЧА 2

// задание1

#include <iostream>
#include <list>
#include <string>

class Queue {
    std::list<std::string> data;

public:

    void enqueue(const std::string& value) {
        data.push_back(value);
    }

    void dequeue() {
        if (!data.empty()) {
            data.pop_front();
        }
    }

    void print() {
        for (const std::string& value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    int sumLength() {
        int sum = 0;
        for (const std::string& value : data) {
            sum += value.length();
        }
        return sum;
    }
};

int main1() {
    setlocale(LC_ALL, "RUS");

    Queue queue;
    queue.enqueue("one");
    queue.enqueue("two");
    queue.enqueue("three");
    queue.enqueue("four");
    queue.print();  // Распечатать содержимое очереди

    queue.dequeue();  // Удалить один элемент из очереди
    queue.enqueue("five");  // Добавить строку «five» в очередь
    queue.print();  // Распечатать очередь еще раз

    std::cout << "Суммарная длина всех строк: " << queue.sumLength() << std::endl;

    return 0;
}



// задание2

class Queue {
    std::list<double> data;

public:
    void enqueue(double value) {
        data.push_back(value);
    }

    void dequeue() {
        if (!data.empty()) {
            data.pop_front();
        }
    }

    void print() {
        for (double value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    double sumNegative() {
        double sum = 0;
        for (double value : data) {
            if (value < 0) {
                sum += value;
            }
        }
        return sum;
    }
};

int main() {
    Queue queue;
    queue.enqueue(-2.1);
    queue.enqueue(1.3);
    queue.enqueue(-1.34);
    queue.enqueue(3.3);
    queue.print();  // Распечатать содержимое очереди

    queue.dequeue();  // Удалить один элемент из очереди
    queue.enqueue(2.9);  // Добавить число 2.9 в очередь
    queue.print();  // Распечатать очередь еще раз

    std::cout << "Сумма отрицательных элементов: " << queue.sumNegative() << std::endl;

    return 0;
}
