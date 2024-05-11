//ЗАДАЧА 4

// задание1

#include <iostream>
#include <list>

using namespace std;

int main() {
    // Создать линейный однонаправленный список из целых чисел
    list<int> myList;
    myList.push_back(1);
    myList.push_back(-2);
    myList.push_back(3);
    myList.push_back(-4);
    myList.push_back(5);

    // Вставить число 10 после каждого элемента с отрицательным значением
    list<int>::iterator it;
    for (it = myList.begin(); it != myList.end(); it++) {
        if (*it < 0) {
            it = myList.insert(++it, 10);
        }
    }

    // Вывести список
    for (it = myList.begin(); it != myList.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}



// задание2

#include <iostream>
#include <list>

using namespace std;

int main1() {
    // Создать линейный однонаправленный список из целых чисел
    list<int> myList{ 1, 3, 5, 7, 9, 12, 15, 17, 19 };

    // Найти первый элемент большего 10
    auto it = find_if(myList.begin(), myList.end(), [](int n) { return n > 10; });

    // Если такой элемент найден
    if (it != myList.end()) {
        // Вставить число 12 после него
        myList.insert(++it, 12);
    }

    // Вывести список
    for (int num : myList) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
