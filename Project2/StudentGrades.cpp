#include "StudentGrades.h" // Include the header file
#include <fstream> // Include the header for file stream operations
#include <string>  // for any string
#include <limits> // for numeric_limits
#include <cctype> // for std::isdigit
#include <algorithm> // for std::any_of

using namespace std;

// Function to get validated integer input
int getValidIntegerInput(const string& prompt) {
    int StudentsNumber;

    // Keep asking for input until a valid integer is entered
    cout << prompt;
    while (!(cin >> StudentsNumber)) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input. Please enter an integer." << endl;
        cout << prompt;
    }

    return StudentsNumber;
}

string getValidNameInput(const string& prompt) {
    string name;

    // Keep asking for input until a non-empty string without numeric characters is entered
    do {
        cout << prompt;
        getline(cin >> ws, name); // Get the entire line

        // Check if the entered string is empty or contains numeric characters
        if (name.empty() || any_of(name.begin(), name.end(), ::isdigit)) {
            cout << "Invalid input. Please enter a non-empty name without numeric characters." << endl;
        }
    } while (name.empty() || any_of(name.begin(), name.end(), ::isdigit));

    return name;
}

int enteringGrades(int grades[], int maxGrades) {
    cout << "Enter Grades" << endl;
    int Gradesnumber = 0;
    for (int i = 0; i < maxGrades; i++) {
        int grade;
        grade = getValidIntegerInput("Enter Grade ");
        grades[Gradesnumber++] = grade;
    }
    return Gradesnumber;
}

void addingGrades(StudentGrades& student) {
    cout << "Enter Grades of " << student.name << endl;

    cout << "Assignments" << endl;
    student.numberAssignments = enteringGrades(student.assignments, 3);

    cout << "Quizzes" << endl;
    student.numberQuizzes = enteringGrades(student.quizzes, 2);

    cout << "Midterm" << endl;
    student.numberMidterms = enteringGrades(student.midterms, 1);

    cout << "Final Exam" << endl;
    student.finalexam = getValidIntegerInput("Enter Grade ");
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
