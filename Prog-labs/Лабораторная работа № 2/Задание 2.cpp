//ЗАДАЧА 2

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::ifstream input("a.txt");
    std::ofstream output("a2.txt");

    if (!input.is_open() || !output.is_open()) {
        std::cout << "Error opening files." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(input, line)) {
        std::stringstream ss(line);
        std::vector<double> numbers;
        double num;

        while (ss >> num) {
            numbers.push_back(num);
        }

        for (size_t i = 0; i < numbers.size(); ++i) {
            if (numbers[i] != 0) {
                output << numbers[i] / 5.0 << " ";
            }
        }
        output << std::endl;
    }

    std::cout << "Non-zero numbers divided by 5 have been written to a2.txt." << std::endl;

    input.close();
    output.close();

    return 0;

