#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#ifdef _WIN32
#include <windows.h>
#endif

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;
};

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    std::cout << "Список студентов:\n";
    for (const Student& student : database) {
        std::cout << "Имя: " << student.name << "\n";
        std::cout << "Возраст: " << student.age << "\n";
        std::cout << "Специальность: " << student.major << "\n";
        std::cout << "Средний балл: " << student.gpa << "\n\n";
    }
}

// Функция для создания отчета и сохранения его в файл
void generateReport(const std::vector<Student>& database,
                    const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла для записи\n";
        return;
    }

    file << "ОТЧЕТ ПО СТУДЕНТАМ\n";
    file << "------------------------\n";

    for (const Student& student : database) {
        file << "Имя: " << student.name << "\n";
        file << "Возраст: " << student.age << "\n";
        file << "Специальность: " << student.major << "\n";
        file << "Средний балл: " << student.gpa << "\n";
        file << "------------------------\n";
    }

    file.close();
    std::cout << "Отчет сохранен" << filename << "\n";
}
#ifndef UNIT_TEST
int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Сохранить отчет в файл\n";
        std::cout << "0. Выход\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 3:
                generateReport(database, "students_report.txt");
                break;
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
#endif