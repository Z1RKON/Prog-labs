//ЗАДАЧА 5

// задание1

#include <iostream>
#include <list>

int main() {
    std::list<double> numbers = { 1.2, -2, 3.4, 5.6, -2, 7.8, 9.0 }; // Ваш список чисел
    auto it = numbers.begin();
    while (it != numbers.end()) {
        if (*it == -2 && it != numbers.begin()) {
            it = numbers.erase(--it);
        }
        else {
            ++it;
        }
    }
    numbers.push_back(33); // Добавляем 33 в конец списка

    // Выводим список
    for (const auto& num : numbers) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}




// задание2

#include <iostream>
#include <list>

using namespace std;

int main() {
    // Создать линейный двунаправленный список из целых чисел
    list<int> myList = { 1, -2, 3, -4, 5, -6, 7, -8, 9, -10 };

    // Вставить в список число 25 перед каждым элементом с положительным значением
    for (list<int>::iterator it = myList.begin(); it != myList.end(); it++) {
        if (*it > 0) {
            it = myList.insert(it, 25);
            it++;
        }
    }

    // Удалить из списка все отрицательные числа
    myList.remove_if([](int n) { return n < 0; });

    // Вывести список
    for (int n : myList) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}