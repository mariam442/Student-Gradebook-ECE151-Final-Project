#include "StudentGrades.h" // Include the header file

using namespace std;

int enteringGrades(int grades[], int maxGrades) {
    cout << "Enter grades" << endl;
    int Gradesnumber = 0;
    for (int i = 0; i < maxGrades; i++) {
        int grade;
        cout << "Enter grade ";
        cin >> grade;
        if (grade == 0) {
            break;
        }
        grades[Gradesnumber++] = grade;
    }
    return Gradesnumber;
}

void addingGrades(StudentGrades& student) {
    cout << "Enter grades of " << student.name << endl;

    cout << "Assignments" << endl;
    student.numberAssignments = enteringGrades(student.assignments, 3);

    cout << "Quizzes" << endl;
    student.numberQuizzes = enteringGrades(student.quizzes, 2);

    cout << "Midterms" << endl;
    student.numberMidterms = enteringGrades(student.midterms, 1);

    cout << "Final Exam" << endl;
    cin >> student.finalexam;
}

void printallGrades(const StudentGrades& student) {
    cout << "Grades of " << student.name << endl;
    cout << "Assignments ";
    for (int i = 0; i < student.numberAssignments; i++) {
        cout << student.assignments[i] << " ";
    }
    cout << endl;

    cout << "Quizzes ";
    for (int i = 0; i < student.numberQuizzes; i++) {
        cout << student.quizzes[i] << " ";
    }
    cout << "Midterms ";
    for (int i = 0; i < student.numberMidterms; i++) {
        cout << student.midterms[i] << " ";
    }
    cout << "Final Exam " << student.finalexam << endl;
}
