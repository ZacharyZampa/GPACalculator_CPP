/*
 * Purpose: Compile the list of courses and their info
 * 
 * Copyright (C) 2019 zackzampa@gmail.com
 */


#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>
#include "GPAList.h"
#include "ClassAndGrade.h"

using namespace std;
std::vector<ClassAndGrade> classes;


GPAList::GPAList() {}

GPAList::~GPAList() {}


void GPAList::addCourse(ClassAndGrade course) {
    classes.push_back(course);
}


void GPAList::listCourses() {
    if(classes.size() == 0) {
        std::cout << "No courses added yet.";
    } else {
        std::cout << "Classes added to the calculation list: " << std::endl;
        for(auto course : classes) {
            std::cout << course.toString() << std::endl;
        }
    }
}


double GPAList::getGPA() {
    double GPA = 0.0;
    int creditTotal  = 0;
    
    for(auto course : classes) {
        GPA += course.getClassGPA() * course.getClassCredits();
        creditTotal += course.getClassCredits();
    }
    
    GPA = GPA / creditTotal;
    
    return GPA;
}


void GPAList::saveToFile(std::string& fileName) {
    try {
        std::ofstream outFile(fileName);
        
        // calculate the GPA 
        double GPA = getGPA();
        
        // print file header
//        outfile.precision(4);  // set precision of ofstream numbers to 4
        outFile << "Cumulative GPA: " << GPA << std::endl
                << "Course\tGPA\tCredits" << std::endl;
        
        for (auto course : classes) {
            outFile << course.toString() << std::endl;
        }
    } catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}


void GPAList::pullFromFile(std::string& fileName) {
    try {
        std::ifstream inFile(fileName);
       
        std::string className;
        std::string delim = "\t";
        std::string line;
        double classGPA;
        int classCredits;
        
        // skip header line
        std::getline(inFile, line);
        std::getline(inFile, line);
        
        while (inFile >> className >> classGPA >> classCredits) {
            
            ClassAndGrade newCourse;
            newCourse.setClassName(className);
            newCourse.setClassGPA(classGPA);
            newCourse.setClassCredits(classCredits);
            classes.push_back(newCourse);
        }
    } catch (const std::exception& e) {
        e.what();
    }
}


