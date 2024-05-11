#include <iostream>
#include <string>
#include <new>
#include <Windows.h>

template <typename T>
class Queue {
public:
    Queue(size_t capacity) : capacity(capacity), size(0), data(new T[capacity]) {}
    ~Queue() { delete[] data; }

    void enqueue(const T& value) {
        if (size == capacity) {
            throw std::bad_alloc();
        }
        data[size++] = value;
    }

    bool dequeue(T& value) {
        if (size == 0) {
            return false;
        }
        value = data[0];
        for (size_t i = 0; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
        return true;
    }

    bool isEmpty() const {
        return size == 0;
    }

private:
    size_t capacity;
    size_t size;
    T* data;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        Queue<int> queueInt(5);
        Queue<double> queueDouble(3);
        Queue<std::string> queueString(2);

        queueInt.enqueue(1);
        queueInt.enqueue(2);
        queueInt.enqueue(3);
        queueInt.enqueue(4);
        queueInt.enqueue(5);

        queueDouble.enqueue(1.1);
        queueDouble.enqueue(2.2);
        queueDouble.enqueue(3.3);

        queueString.enqueue("Hello");
        queueString.enqueue("World");

        int valueInt;
        while (!queueInt.isEmpty()) {
            queueInt.dequeue(valueInt);
            std::cout << valueInt << " ";
        }
        std::cout << std::endl;

        double valueDouble;
        while (!queueDouble.isEmpty()) {
            queueDouble.dequeue(valueDouble);
            std::cout << valueDouble << " ";
        }
        std::cout << std::endl;

        std::string valueString;
        while (!queueString.isEmpty()) {
            queueString.dequeue(valueString);
            std::cout << valueString << " ";
        }
        std::cout << std::endl;

        Queue<int> queueIntTooBig(2);
        queueIntTooBig.enqueue(1);
        queueIntTooBig.enqueue(2);
        queueIntTooBig.enqueue(3);

    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Ошибка выделения памяти: " << e.what() << std::endl;
    }

    return 0;
}