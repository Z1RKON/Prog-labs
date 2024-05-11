#include <iostream>
#include <fstream>
#include <string>

class CFile {
protected:
    std::fstream file;

public:
    CFile(const std::string& filename) {
        file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
    }

    ~CFile() {
        file.close();
    }

    bool Open(const std::string& filename) {
        file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
        return file.is_open();
    }

    void Close() {
        file.close();
    }

    void Seek(long offset, int origin) {
        file.seekg(offset, origin);
    }

    long GetPosition() {
        return file.tellg();
    }

    long GetLength() {
        file.seekg(0, std::ios::end);
        long length = file.tellg();
        file.seekg(0, std::ios::beg);
        return length;
    }

    void Read(void* buffer, size_t size) {
        file.read((char*)buffer, size);
    }

    void Write(const void* buffer, size_t size) {
        file.write((const char*)buffer, size);
    }
};

class CMyDataFile : public CFile {
private:
    struct Header {
        int magicNumber;
        int dataSize;
    };

public:
    CMyDataFile(const std::string& filename) : CFile(filename) {
        if (Open(filename)) {
            Header header;
            Read(&header, sizeof(Header));

            if (header.magicNumber == 0x12345678) {
                Seek(sizeof(Header), std::ios::beg);
            }
            else {
                // Ошибка - некорректный заголовок
                Close();
            }
        }
    }

    ~CMyDataFile() {
        Close();
    }

    void WriteData(const void* data, size_t size) {
        Header header = { 0x12345678, size };
        Write(&header, sizeof(Header));
        Write(data, size);
    }

    void ReadData(void* data, size_t size) {
        Header header;
        Read(&header, sizeof(Header));

        if (header.magicNumber == 0x12345678) {
            Seek(sizeof(Header), std::ios::beg);
            Read(data, size);
        }
        else {
            // Ошибка - некорректный заголовок
        }
    }
};

int main() {

    CMyDataFile myDataFile("mydatafile.dat");
    setlocale(LC_ALL, "Russian");
    // Меню для демонстрации работы с классами
    int choice;
    do {
        std::cout << "1. Открыть файл" << std::endl;
        std::cout << "2. Закрыть файл" << std::endl;
        std::cout << "3. Переместиться в файле" << std::endl;
        std::cout << "4. Прочитать данные" << std::endl;
        std::cout << "5. Записать данные" << std::endl;
        std::cout << "6. Получить текущую позицию" << std::endl;
        std::cout << "7. Получить длину файла" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string filename;
            std::cout << "Введите имя файла: ";
            std::cin >> filename;
            myDataFile.Open(filename);
            break;
        }
        case 2: {
            myDataFile.Close();
            break;
        }
        case 3: {
            long offset;
            int origin;
            std::cout << "Введите смещение и начальную точку (0 - начало, 1 - текущая, 2 - конец): ";
            std::cin >> offset >> origin;
            myDataFile.Seek(offset, origin);
            break;
        }
        case 4: {
            void* buffer = new char[100];
            myDataFile.ReadData(buffer, 100);
            std::cout << "Прочитанные данные: " << (char*)buffer << std::endl;
            delete[] buffer;
            break;
        }
        case 5: {
            char* data = new char[100];
            std::cout << "Введите данные для записи: ";
            std::cin >> data;
            myDataFile.WriteData(data, strlen(data) + 1);
            delete[] data;
            break;
        }
        case 6: {
            std::cout << "Текущая позиция: " << myDataFile.GetPosition() << std::endl;
            break;
        }
        case 7: {
            std::cout << "Длина файла: " << myDataFile.GetLength() << std::endl;
            break;
        }
        case 0: {
            break;
        }
        default: {
            std::cout << "Неверный выбор" << std::endl;
        }
        }

    } while (choice != 0);

    return 0;