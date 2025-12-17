#define UNIT_TEST
#include "main.cpp"

#include <gtest/gtest.h>
#include <fstream>

TEST(StudentTest, AddStudentIncreasesSize) {
    std::vector<Student> db;
    db.push_back({"Ivan", 20, "CS", 4.5});
    EXPECT_EQ(db.size(), 1);
}

TEST(ReportTest, FileIsCreated) {
    std::vector<Student> db;
    db.push_back({"Anna", 21, "Math", 4.9});

    generateReport(db, "test_report.txt");

    std::ifstream f("test_report.txt");
    EXPECT_TRUE(f.is_open());
}

TEST(ReportTest, ReportContainsStudentName) {
    std::vector<Student> db;
    db.push_back({"Petr", 22, "Physics", 4.2});

    generateReport(db, "test_report2.txt");

    std::ifstream f("test_report2.txt");
    std::string content(
        (std::istreambuf_iterator<char>(f)),
        std::istreambuf_iterator<char>()
    );

    EXPECT_NE(content.find("Petr"), std::string::npos);
}

TEST(ReportTest, EmptyDatabaseCreatesFile) {
    std::vector<Student> db;
    generateReport(db, "empty.txt");

    std::ifstream f("empty.txt");
    EXPECT_TRUE(f.is_open());
}

TEST(ReportTest, MultipleStudentsInReport) {
    std::vector<Student> db{
            {"A", 18, "CS", 4.0},
            {"B", 19, "CS", 4.2}
    };

    generateReport(db, "multi.txt");

    std::ifstream f("multi.txt");
    std::string content(
        (std::istreambuf_iterator<char>(f)),
        std::istreambuf_iterator<char>()
    );

    EXPECT_NE(content.find("A"), std::string::npos);
    EXPECT_NE(content.find("B"), std::string::npos);
}
