#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <fstream>
#include "StudentGrades.h" // Include the header file for the StudentGrades struct

double printallGrades(const StudentGrades& student, std::ofstream& outFile);
double calculateTotalAverage(const StudentGrades students[], int numStudents);

#endif
