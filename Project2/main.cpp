#include <iostream>
#include "StudentGrades.h"  // Include the header file
using namespace std;
int main() {
    int studentsNumber;
    cout << "Enter number of students ";
    cin >> studentsNumber;

    StudentGrades students[10];

    for (int i = 0; i < studentsNumber; i++) {
        cout << "Enter name of student ";
        cin >> students[i].name;
        students[i].numberAssignments = 0;
        students[i].numberQuizzes = 0;
        students[i].numberMidterms = 0;
        addingGrades(students[i]);
    }
    cout << "All Grades" << std::endl;
    for (int i = 0; i < studentsNumber; i++) {
        printallGrades(students[i]);
        cout <<endl;
    }

    return 0;
}
//this is an edit

// Another edit