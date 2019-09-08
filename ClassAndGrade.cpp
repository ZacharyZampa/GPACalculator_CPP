/*
 * Purpose: Create the template for creating a ClassAndGrade object for the 
 * respective course.
 * 
 * Copyright (C) 2019 zackzampa@gmail.com
 */
#include <cstdlib>
#include <string>
#include <iostream>
#include "ClassAndGrade.h"

using namespace std;

ClassAndGrade::~ClassAndGrade() {
}

std::string ClassAndGrade::getClassName() const {
    return className;
}

double ClassAndGrade::getClassGPA() const {
    return classGPA;
}

int ClassAndGrade::getClassCredits() const {
    return classCredits;
}

void ClassAndGrade::setClassName(std::string& name) {
    className = name;
}

void ClassAndGrade::setClassGPA(double gpa) {
    classGPA = gpa;
}

void ClassAndGrade::setClassCredits(int credits) {
    classCredits = credits;
}

std::string ClassAndGrade::toString() const {
    std::string stringed = "" + getClassName() + "\t" +
            std::to_string(getClassGPA()) + "\t" + 
            std::to_string(getClassCredits());
    
    return stringed;
}
