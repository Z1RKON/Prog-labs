//ЗАДАЧА 1

#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("a.txt");

    if (!file.is_open()) {
        std::cerr << "File could not be opened!" << std::endl;
        return 1;
    }

    double num;
    int zeroCount = 0;
    double sumNegatives = 0.0;

    while (file >> num) {
        if (num == 0) {
            zeroCount++;
        }
        else if (num < 0) {
            sumNegatives += num;
        }
    }

    file.close();

    std::cout << "Number of zero elements: " << zeroCount << std::endl;
    std::cout << "Sum of negative elements: " << sumNegatives << std::endl;

    return 0;
}