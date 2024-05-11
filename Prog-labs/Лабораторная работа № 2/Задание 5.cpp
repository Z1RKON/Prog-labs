//ЗАДАЧА 5

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Owner {
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string postal_index;
    std::string country;
    std::string region;
    std::string district;
    std::string city;
    std::string street;
    int house;
    int apartment;
    std::string phone_number;
};

int main() {
    std::ifstream file("owners.txt");
    std::vector<Owner> owners;

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            Owner owner;
            iss >> owner.surname >> owner.name >> owner.patronymic
                >> owner.postal_index >> owner.country >> owner.region
                >> owner.district >> owner.city >> owner.street
                >> owner.house >> owner.apartment >> owner.phone_number;

            if (owner.phone_number.substr(0, 3) == "720") {
                owners.push_back(owner);
            }
        }
        file.close();

        std::ofstream output_file("720_numbers.txt");
        if (output_file.is_open()) {
            for (const Owner& owner : owners) {
                output_file << owner.surname << " " << owner.name << " " << owner.patronymic << " "
                    << owner.postal_index << " " << owner.country << " " << owner.region << " "
                    << owner.district << " " << owner.city << " " << owner.street << " "
                    << owner.house << " " << owner.apartment << " " << owner.phone_number << std::endl;
            }
            output_file.close();
            std::cout << "Owners with phone numbers starting with 720 have been saved to 720_numbers.txt" << std::endl;
        }
        else {
            std::cout << "Unable to create output file" << std::endl;
        }
    }
    else {
        std::cout << "Unable to open file!" << std::endl;
    }

    return 0;
}