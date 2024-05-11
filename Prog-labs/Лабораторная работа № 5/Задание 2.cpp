#include <iostream>
#include <Windows.h>
#include <string>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!Empty()) {
            Dequeue();
        }
    }

    bool Empty() const {
        return front == nullptr;
    }

    void Enqueue(const T& data) {
        Node* newNode = new Node(data);

        if (Empty()) {
            front = newNode;
        }
        else {
            rear->next = newNode;
        }

        rear = newNode;
    }

    void Dequeue() {
        if (Empty()) {
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    T Front() const {
        if (Empty()) {
            std::cout << "Queue is empty" << std::endl;
            return T();
        }

        return front->data;
    }
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int choice;
    do {
        std::cout << "1. Create a queue" << std::endl;
        std::cout << "2. Add an element to the queue" << std::endl;
        std::cout << "3. Remove an element from the queue" << std::endl;
        std::cout << "4. Get the first element of the queue" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Choose an action: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Queue<int> intQueue;
            Queue<std::string> stringQueue;
            std::cout << "Integer queue created" << std::endl;
            std::cout << "String queue created" << std::endl;
            break;
        }
        case 2: {
            Queue<int> intQueue;
            Queue<std::string> stringQueue;
            int value;
            std::string str;
            std::cout << "Enter an integer to add to the integer queue: ";
            std::cin >> value;
            intQueue.Enqueue(value);
            std::cout << "Enter a string to add to the string queue: ";
            std::cin.ignore();
            std::getline(std::cin, str);
            stringQueue.Enqueue(str);
            break;
        }
        case 3: {
            Queue<int> intQueue;
            Queue<std::string> stringQueue;
            intQueue.Dequeue();
            stringQueue.Dequeue();
            break;
        }
        case 4: {
            Queue<int> intQueue;
            Queue<std::string> stringQueue;
            int frontValue;
            std::string frontStr;
            frontValue = intQueue.Front();
            frontStr = stringQueue.Front();
            std::cout << "First element of the integer queue: " << frontValue << std::endl;
            std::cout << "First element of the string queue: " << frontStr << std::endl;
            break;
        }
        case 0: {
            break;
        }
        default: {
            std::cout << "Invalid choice" << std::endl;
        }
        }

    } while (choice != 0);

    return 0;
}