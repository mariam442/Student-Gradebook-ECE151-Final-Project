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

    int totalAssignments = 0;
    int totalQuizzes = 0;
    int midterm = 0;
    int final = 0;
    cout << "Assignments ";
    for (int i = 0; i < student.numberAssignments; i++) {
        totalAssignments += student.assignments[i];
        cout << student.assignments[i] << " ";
    }
    cout << " (Total: " << totalAssignments << ")" << endl; // Print sum after loop

    cout << "Quizzes ";
    for (int i = 0; i < student.numberQuizzes; i++) {
        totalQuizzes += student.quizzes[i];
        cout << student.quizzes[i] << " ";
    }
    cout << " (Total: " << totalQuizzes << ")" << endl; // Print sum after loop

    cout << "Midterms ";
    for (int i = 0; i < student.numberMidterms; i++) {
        cout << student.midterms[i] << " ";
        midterm = student.midterms[i];
    }
    cout << "Final Exam " << student.finalexam << endl;
    final = student.finalexam;
    cout <<"Total Grade = " << totalAssignments + totalQuizzes + midterm + final<<"%"<<endl;
}
