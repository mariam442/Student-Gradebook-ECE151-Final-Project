#include <iostream>
#include <fstream>
#include "StudentGrades.h"
#include "functions.h" // Include the header file containing function declarationsusing namespace std;
using namespace std;
int main() {
    int StudentsNumber;
    cout << "Enter number of students ";
    cin >> StudentsNumber; //need validation

    StudentGrades students[10];

    // Open the output file
    ofstream outFile("grades_output.txt");
    if (!outFile) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    for (int i = 0; i < StudentsNumber; i++) {
        cout << "Enter name of student ";
        cin >> students[i].name; //need validation

        students[i].numberAssignments = 0;
        students[i].numberQuizzes = 0;
        students[i].numberMidterms = 0;
        addingGrades(students[i]); // Pass the output file stream to addingGrades
    }
    outFile << "All Grades" << endl;
    for (int i = 0; i < StudentsNumber; i++) {
        printallGrades(students[i], outFile); // Pass the output file stream to printallGrades
    }
    double average = 0;
    average = calculateTotalAverage(students, StudentsNumber); // This function already writes to the file
    outFile << "The Average Grade of the Whole Class is " << average << "%" << endl;

    // Close the output file
    outFile.close();

    cout << "A Grade Report has been generated to grades_output.txt" << endl;
    return 0;
}
