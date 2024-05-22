#include "StudentGrades.h" // Include the header file
#include <fstream> // Include the header for file stream operations
#include <string>
#include <cctype> // for std::isalpha

using namespace std;

int enteringGrades(int grades[], int maxGrades) {
    cout << "Enter grades" << endl;
    int Gradesnumber = 0;
    for (int i = 0; i < maxGrades; i++) {
        int grade;
        cout << "Enter grade ";
        cin >> grade; //need validation
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
    cin >> student.finalexam; //need validation
    cout << student.finalexam << endl; // Print final exam grade to file
}

double printallGrades(const StudentGrades& student, ofstream& outFile) {
    outFile << "Grades of " << student.name << endl;

    int totalAssignments = 0;
    int totalQuizzes = 0;
    int midterm = 0;
    int final = 0;
    outFile << "Assignments ";
    for (int i = 0; i < student.numberAssignments; i++) {
        totalAssignments += student.assignments[i];
        outFile << student.assignments[i] << " ";
    }
    outFile << " (Total: " << totalAssignments << ")" << endl; // Print sum after loop

    outFile << "Quizzes ";
    for (int i = 0; i < student.numberQuizzes; i++) {
        totalQuizzes += student.quizzes[i];
        outFile << student.quizzes[i] << " ";
    }
    outFile << " (Total: " << totalQuizzes << ")" << endl; // Print sum after loop

    outFile << "Midterms ";
    for (int i = 0; i < student.numberMidterms; i++) {
        outFile << student.midterms[i] << " ";
        midterm = student.midterms[i];
    }
    outFile << "Final Exam " << student.finalexam << endl;
    final = student.finalexam;
    int overallgrade = 0;
    overallgrade = totalAssignments + totalQuizzes + midterm + final;
    outFile << "Total Grade = " << overallgrade << "%" << endl;

    return overallgrade;
}

double calculateTotalAverage(const StudentGrades students[], int numStudents) {
    double totalSum = 0.0;
    ofstream outFile("grades_output.txt"); // Open a file for writing
    if (!outFile) {
        cerr << "Error: Unable to open the file." << endl;
        return 0;
    }
    for (int i = 0; i < numStudents; i++) {
        // Call printallGrades to get overall grade of each student
        totalSum += printallGrades(students[i], outFile);
    }
    outFile.close(); // Close the file after writing
    // Calculate average by dividing total sum by number of students
    return totalSum / numStudents;
}
