#include <iostream>
#include "StudentGrades.h"  // Include the header file

int main() {
    int studentsNumber;
    std::cout << "Enter number of students ";
    std::cin >> studentsNumber;

    StudentGrades students[10];

    for (int i = 0; i < studentsNumber; i++) {
        std::cout << "Enter name of student ";
        std::cin >> students[i].name;
        students[i].numberAssignments = 0;
        students[i].numberQuizzes = 0;
        students[i].numberMidterms = 0;
        addingGrades(students[i]);
    }
    std::cout << "All Grades" << std::endl;
    for (int i = 0; i < studentsNumber; i++) {
        printallGrades(students[i]);
        std::cout << std::endl;
    }

    return 0;
}
//this is an edit

// Another edit