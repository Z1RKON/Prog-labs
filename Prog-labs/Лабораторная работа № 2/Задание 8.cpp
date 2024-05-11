#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

struct FootballPlayer {
    std::string surname;
    std::string position;
    int age;
    int gamesPlayed;
};

void writeToBinaryFile(const std::string& filename, const FootballPlayer& player) {
    std::ofstream outFile(filename, std::ios::binary | std::ios::app);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<const char*>(&player), sizeof(FootballPlayer));
        outFile.close();
        std::cout << "Информация о футболисте записана в файл" << std::endl;
    }
    else {
        std::cout << "Ошибка при открытии файла" << std::endl;
    }
}

void readFromBinaryFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile.is_open()) {
        FootballPlayer player;
        while (inFile.read(reinterpret_cast<char*>(&player), sizeof(FootballPlayer))) {
            std::cout << "Фамилия: " << player.surname << std::endl;
            std::cout << "Амплуа: " << player.position << std::endl;
            std::cout << "Возраст: " << player.age << std::endl;
            std::cout << "Количество игр: " << player.gamesPlayed << std::endl;
            std::cout << "--------------------------------" << std::endl;
        }
        inFile.close();
    }
    else {
        std::cout << "Ошибка при открытии файла" << std::endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FootballPlayer player;
    std::string filename = "football_players.bin";

    std::cout << "Введите информацию о футболисте:" << std::endl;
    std::cout << "Фамилия: ";
    std::cin.ignore();
    std::getline(std::cin, player.surname);
    std::cout << "Амплуа: ";
    std::getline(std::cin, player.position);
    std::cout << "Возраст: ";
    std::cin >> player.age;
    std::cout << "Количество игр: ";
    std::cin >> player.gamesPlayed;

    writeToBinaryFile(filename, player);
    readFromBinaryFile(filename);

    return 0;
}