/*
 * Copyright (C) 2019 zackzampa@gmail.com
 */

/* 
 * File:   GPACalculator.cpp
 * Author: Zachary Zampa
 *
 * Created on March 1, 2019, 7:47 PM
 * 
 * Requires GPAList.cpp, GPAList.h, and ClassAndGrade.cpp
 * 
 * Purpose: Create a GPA calculator based on courses and their respective info
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>

#include "GPAList.h"
#include "ClassAndGrade.h"

using namespace std;






/**
 * Convert the letter grade to GPA Scale (based off Miami University)
 * @param letter string of letter grade
 * @return double; grade in GPA form
 */
double letterToGPA(std::string letter) {
    double classGPA = -1.0;

    if (letter == "A") {
        classGPA = 4.0;
    }
    else if (letter == "A-") {
        classGPA = 3.70;
    }
    else if (letter == "B+") {
        classGPA = 3.30;
    }
    else if (letter == "B") {
        classGPA = 3.00;
    }
    else if (letter == "B-") {
        classGPA = 2.70;
    }
    else if (letter == "C+") {
        classGPA = 2.30;
    }
    else if (letter == "C") {
        classGPA = 2.00;
    }
    else if (letter == "C-") {
        classGPA = 1.70;
    }
    else if (letter == "D+") {
        classGPA = 1.30;
    }
    else if (letter == "D") {
        classGPA = 1.00;
    }
    else if (letter == "D-") {
        classGPA = 0.70;
    }
    else if (letter == "F") {
        classGPA = 0;
    }
    else {
        std::cout << "Error: Please enter valid letter grade. " << std::endl;
    }

    return classGPA;
}


/**
 * Display the menu for the user
 * @return char; return char of which menu choice (uppercase)
 */
char menu() {
    std::cout << "\n\n\t===============================" << std::endl;
    std::cout << "\tGPA Calculator Application" << std::endl;
    std::cout << "\tDeveloped by: Zachary Zampa " << std::endl;
    std::cout << "\tDate: 12/20/2018" << std::endl;
    std::cout << "\t===============================" << std::endl;
    std::cout << "\tA. Add a Class to the Calculation List" << std::endl;
    std::cout << "\tB. List Classes in the Calculation List" << std::endl;
    std::cout << "\tC. Caculate the Overall GPA" << std::endl;
    std::cout << "\tD. Save the Class List to a File" << std::endl;
    std::cout << "\tE. Import Existing .txt File" << std::endl;
    std::cout << "\tX. Exit" << std::endl;
    std::cout << std::endl << std::endl;
    std::cout << "Option:" << std::endl;
        
    char letter;
    std::cin >> letter;
    return std::toupper(letter);
}


/**
 * Read in course info from keyboard and construct object
 * @return ClassAndGrade object created
 */
ClassAndGrade readCourseInfoFromKeyboard() {
    std::string className = "";
    double classGPA = -1.0;
    int classCredits = -1;

    do {
        std::cout << "Enter the class name: ";
        std::getline(std::cin, className);
    } while (className == "");

    do {
        std::cout << "Enter the letter grade: ";
        std::string letter;
        std::cin >> letter;
        classGPA = letterToGPA(letter);
    } while (classGPA == -1.0);

    do {
        std::cout << "Enter how may credits the class was: ";
        if (std::cin >> classCredits) {
        } else {
            std::cout << "Error: Please enter a valid credit number. \n";
        }
    } while (classCredits == -1);

    ClassAndGrade newCourse;
    newCourse.setClassName(className);
    newCourse.setClassGPA(classGPA);
    newCourse.setClassCredits(classCredits);

    std::cout << className + " added to course list" << std::endl;
    return newCourse; // return info of added class
}



void menuSelector(char userMenuChoice, GPAList courseList) {
    switch (userMenuChoice) {
        case 'A':
        {
            // method call to add course
            courseList.addCourse(readCourseInfoFromKeyboard());
            break;
        }
        case 'B':
        {
            // method call to list courses
            courseList.listCourses();
            break;
        }
        case 'C':
        {
            // method call to calculate overall GPA
            std::cout.precision(4);  // set precision of std::cout numbers to 4
            std::cout << "Cumulative GPA: " << courseList.getGPA() << std::endl;
            break;
        }
        case 'D':
        {
            std::cout << "What would you like to name the file: ";
            std:string fileName = "";
            std::cin >> fileName;
            fileName = fileName = ".txt";

            courseList.saveToFile(fileName);
            std::cout << "File saved as " + fileName;
            break;
        }
        case 'E':
        {            
            std::cout << "What .txt file would you like to import: ";
            std::string fileImportName = "";
            std::cin >> fileImportName;
            courseList.pullFromFile(fileImportName);
            std::cout << "File imported to program";
            break;
        }
        case 'X':
        {
            // confirm exit
            std::cout << "\nAre you sure (Yes/No)";
            std::string answer;
            std::cin >> answer;
            for (auto & c: answer) c = toupper(c);
            if (answer == "YES") {
                exit(0); //Code for exit - 0 for normal exit
            }
        }
        default: 
        {   
            std::cout << "Invalid Option";
            break;
        }
    }
}


/*
 * 
 */
int main(int argc, char** argv) {
    
    GPAList courseList;  // create a course list
    bool exit = false;  // application exit check
    
    while(!exit) {
        char userMenuChoice = menu();
        menuSelector(userMenuChoice, courseList);
        
    }
    
    
    return 0;
}






