//ЗАДАЧА 4

#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("numbers.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    int num, count = 0;
    long long sum = 0;

    while (inputFile >> num) {
        if (num > 0 && count % 2 == 0) {
            sum += num;
            count++;
        }
        count++;
    }

    if (count == 0) {
        std::cout << "No positive numbers on even positions found in the file" << std::endl;
    }
    else {
        float average = static_cast<float>(sum) / (count / 2);
        std::cout << "Average of positive numbers on even positions: " << average << std::endl;
    }

    inputFile.close();

    return 0;
}
