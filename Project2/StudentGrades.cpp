#include "StudentGrades.h"  // Include the header file
using namespace std;

int enteringGrades(int grades[]) {
    cout << "Enter grades (press 0 to finish)" << std::endl;
    int gradesNumber = 0;
    for (int i = 0; i < maximumGrades; i++) {
        int grade;
        cout << "Enter grade ";
        cin >> grade;
        if (gradesNumber >= maximumGrades || grade == 0) {
            break;
        }
        grades[gradesNumber++] = grade;
    }
    return gradesNumber;
}

void addingGrades(StudentGrades& student) {
    cout << "Enter grades of " << student.name << endl;

    cout << "Assignments" << endl;
    student.numberAssignments = enteringGrades(student.assignments);

    cout << "Quizzes" << endl;
    student.numberQuizzes = enteringGrades(student.quizzes);

    cout << "Midterms" << endl;
    student.numberMidterms = enteringGrades(student.midterms);

    cout << "Final Exam" << endl;
    cin >> student.finalexam;
}

void printallGrades(StudentGrades& student) {
    cout << "Grades of " << student.name << endl;
    cout << "Assignments ";
    for (int i = 0; i < student.numberAssignments; i++) {
        cout << student.assignments[i] << " ";
    }
    cout <<endl;

    cout << "Quizzes ";
    for (int i = 0; i < student.numberQuizzes; i++) {
        cout << student.quizzes[i] << " ";
    }
    cout << endl;

    cout << "Midterms ";
    for (int i = 0; i < student.numberMidterms; i++) {
        cout << student.midterms[i] << " ";
    }
    cout << endl;

    cout << "Final Exam " << student.finalexam << endl;
}
