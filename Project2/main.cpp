#include <iostream>
#include <fstream> // Include the header for file stream operations
#include "StudentGrades.h" // Include the header file
#include "functions.h" // Include the header file containing function declarationsusing namespace std;
#include <limits> // for numeric_limits
#include <cctype> // for std::isdigit
#include <algorithm> // for std::any_of

using namespace std;
int main() {
    int StudentsNumber;
    // Call the function to get validated integer input
    StudentsNumber = getValidIntegerInput("Enter Number of Students: ");

    StudentGrades students[10];

    // Open the output file
    ofstream outFile("grades_output.txt");
    if (!outFile) {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }

    for (int i = 0; i < StudentsNumber; i++) {
        students[i].name = getValidNameInput("Enter Name of Student: ");
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
