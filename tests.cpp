#define UNIT_TEST
#include "main.cpp"

#include <gtest/gtest.h>
#include <fstream>
#include <sstream>

std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// ---------- ТЕСТЫ ----------

// 1. Отчёт создаётся
TEST(ReportTest, FileIsCreated) {
    std::vector<Student> db = {
        {"Ivan", 20, "CS", 4.5}
    };

    generateReport(db, "test_report.txt");

    std::ifstream file("test_report.txt");
    EXPECT_TRUE(file.is_open());
}

// 2. Отчёт НЕ пустой
TEST(ReportTest, ReportIsNotEmpty) {
    std::vector<Student> db = {
        {"Ivan", 20, "CS", 4.5}
    };

    generateReport(db, "test_report2.txt");

    std::string content = readFile("test_report2.txt");
    EXPECT_FALSE(content.empty());
}

// 3. Все поля студента записываются корректно
TEST(ReportTest, ReportContainsAllStudentFields) {
    Student s{"Anna", 21, "Math", 4.9};
    std::vector<Student> db = {s};

    generateReport(db, "test_report3.txt");
    std::string content = readFile("test_report3.txt");

    EXPECT_NE(content.find("Anna"), std::string::npos);
    EXPECT_NE(content.find("21"), std::string::npos);
    EXPECT_NE(content.find("Math"), std::string::npos);
    EXPECT_NE(content.find("4.9"), std::string::npos);
}

// 4. В отчёте несколько студентов
TEST(ReportTest, MultipleStudentsWrittenCorrectly) {
    std::vector<Student> db = {
        {"A", 18, "CS", 4.0},
        {"B", 19, "Math", 4.1}
    };

    generateReport(db, "test_report4.txt");
    std::string content = readFile("test_report4.txt");

    EXPECT_NE(content.find("A"), std::string::npos);
    EXPECT_NE(content.find("B"), std::string::npos);
}

// 5. Пустая база данных — файл всё равно создаётся
TEST(ReportTest, EmptyDatabaseCreatesValidReport) {
    std::vector<Student> db;

    generateReport(db, "test_report5.txt");
    std::string content = readFile("test_report5.txt");

    EXPECT_NE(content.find("ОТЧЕТ"), std::string::npos);
}

// 6. Формат отчёта не нарушен
TEST(ReportTest, ReportHasCorrectHeaderAndSeparators) {
    std::vector<Student> db = {
        {"Ivan", 20, "CS", 4.5}
    };

    generateReport(db, "test_report6.txt");
    std::string content = readFile("test_report6.txt");

    EXPECT_NE(content.find("ОТЧЕТ ПО СТУДЕНТАМ"), std::string::npos);
    EXPECT_NE(content.find("------------------------"), std::string::npos);
}
