#pragma once
#ifndef STUDENT_GRADES_H
#define STUDENT_GRADES_H

#include <iostream>
#include <string>

const int maximumGrades = 10;

struct StudentGrades {
	std::string name;
	int assignments[maximumGrades];
	int quizzes[maximumGrades];
	int midterms[maximumGrades];
	int numberAssignments;
	int numberQuizzes;
	int numberMidterms;
	int finalexam;
	double overallgrade;
};

int enteringGrades(int grades[], int maxGrades); // This is a decoration for function entering grades
void addingGrades(StudentGrades& student);
double calculateTotalAverage(const StudentGrades students[], int numStudents);
int getValidIntegerInput(const std::string& prompt); // Declaration of getValidIntegerInput function
std::string getValidNameInput(const std::string& prompt);
#endif // STUDENT_GRADES_H


