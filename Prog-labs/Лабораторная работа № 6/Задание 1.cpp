#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

class Train {
public:
    Train(int number, const std::string& destination, int departureTime)
        : number(number), destination(destination), departureTime(departureTime) {}

    int getNumber() const { return number; }
    const std::string& getDestination() const { return destination; }
    int getDepartureTime() const { return departureTime; }

private:
    int number;
    std::string destination;
    int departureTime;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Train> trains;

    while (true) {
        int choice;
        std::cout << "Выберите функцию:" << std::endl;
        std::cout << "1. Ввод данных" << std::endl;
        std::cout << "2. Вывод сведений по всем поездам" << std::endl;
        std::cout << "3. Вывод сведений по поезду с заданным номером" << std::endl;
        std::cout << "4. Вывод сведений по поездам, следующим до заданной станции назначения" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cin >> choice;

        if (choice == 1) {
            trains.clear();
            int number;
            std::string destination;
            int departureTime;

            while (true) {
                std::cout << "Введите данные о поезде (номер, станция назначения, время отправления), или 0 для окончания ввода:" << std::endl;
                std::cin >> number;
                if (number == 0) {
                    break;
                }
                std::cin.ignore();
                std::getline(std::cin, destination);
                std::cin >> departureTime;
                trains.push_back(Train(number, destination, departureTime));
            }
        }
        else if (choice == 2) {
            if (trains.empty()) {
                std::cout << "Нет данных о поездах." << std::endl;
            }
            else {
                std::cout << "Сведения о поездах:" << std::endl;
                for (const Train& train : trains) {
                    std::cout << "Номер поезда: " << train.getNumber() << ", станция назначения: " << train.getDestination()
                        << ", время отправления: " << train.getDepartureTime() << std::endl;
                }
            }
        }
        else if (choice == 3) {
            if (trains.empty()) {
                std::cout << "Нет данных о поездах." << std::endl;
            }
            else {
                int number;
                std::cout << "Введите номер поезда:" << std::endl;
                std::cin >> number;
                bool found = false;
                for (const Train& train : trains) {
                    if (train.getNumber() == number) {
                        std::cout << "Сведения о поезде:" << std::endl;
                        std::cout << "Номер поезда: " << train.getNumber() << ", станция назначения: " << train.getDestination()
                            << ", время отправления: " << train.getDepartureTime() << std::endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "Поезд с номером " << number << " не найден." << std::endl;
                }
            }
        }
        else if (choice == 4) {
            if (trains.empty()) {
                std::cout << "Нет данных о поездах." << std::endl;
            }
            else {
                std::string destination;
                std::cout << "Введите станцию назначения:" << std::endl;
                std::cin.ignore();
                std::getline(std::cin, destination);
                bool found = false;
                for (const Train& train : trains) {
                    if (train.getDestination() == destination) {
                        std::cout << "Сведения о поезде:" << std::endl;
                        std::cout << "Номер поезда: " << train.getNumber() << ", станция назначения: " << train.getDestination()
                            << ", время отправления: " << train.getDepartureTime() << std::endl;
                        found = true;
                    }
                }
                if (!found) {
                    std::cout << "Поезды, следующие до станции " << destination << ", не найдены." << std::endl;
                }
            }
        }
        else if (choice == 5) {
            break;
        }
        else {
            std::cout << "Неверный выбор." << std::endl;
        }
    }

    return 0;
}