#include "StudentGrades.h"  // Include the header file

int enteringGrades(int grades[]) {
    std::cout << "Enter grades (press 0 to finish)" << std::endl;
    int gradesNumber = 0;
    for (int i = 0; i < maximumGrades; i++) {
        int grade;
        std::cout << "Enter grade ";
        std::cin >> grade;
        if (gradesNumber >= maximumGrades || grade == 0) {
            break;
        }
        grades[gradesNumber++] = grade;
    }
    return gradesNumber;
}

void addingGrades(StudentGrades& student) {
    std::cout << "Enter grades of " << student.name << std::endl;

    std::cout << "Assignments" << std::endl;
    student.numberAssignments = enteringGrades(student.assignments);

    std::cout << "Quizzes" << std::endl;
    student.numberQuizzes = enteringGrades(student.quizzes);

    std::cout << "Midterms" << std::endl;
    student.numberMidterms = enteringGrades(student.midterms);

    std::cout << "Final Exam" << std::endl;
    std::cin >> student.finalexam;
}

void printallGrades(StudentGrades& student) {
    std::cout << "Grades of " << student.name << std::endl;
    std::cout << "Assignments ";
    for (int i = 0; i < student.numberAssignments; i++) {
        std::cout << student.assignments[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Quizzes ";
    for (int i = 0; i < student.numberQuizzes; i++) {
        std::cout << student.quizzes[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Midterms ";
    for (int i = 0; i < student.numberMidterms; i++) {
        std::cout << student.midterms[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Final Exam " << student.finalexam << std::endl;
}
