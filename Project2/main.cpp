#include<iostream>
#include"StudentGrades.h"
using namespace std;
int main() {
    int StudentsNumber;
    cout << "Enter number of students ";
    cin >> StudentsNumber;

    StudentGrades students[10];

    for (int i = 0; i < StudentsNumber; i++) {
        cout << "Enter name of student ";
        cin >> students[i].name;
        students[i].numberAssignments = 0;
        students[i].numberQuizzes = 0;
        students[i].numberMidterms = 0;
        addingGrades(students[i]);
    }
    cout << "All Grades" << endl;
    for (int i = 0; i < StudentsNumber; i++) {
        printallGrades(students[i]);
    }

    return 0;
}
