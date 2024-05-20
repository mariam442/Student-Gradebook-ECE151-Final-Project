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
};

int enteringGrades(int grades[], int maxGrades);
void addingGrades(StudentGrades& student);
void printallGrades(const StudentGrades& student); // Pass by reference to avoid unnecessary copying

#endif // STUDENT_GRADES_H
