/*
 * Copyright (C) 2019 zackzampa@gmail.com
 */

/* 
 * File:   GPAList.h
 * Author: Zachary Zampa
 * 
 * Purpose: Compile the list of courses and their info
 *
 * Created on March 1, 2019, 7:52 PM
 */

#ifndef GPALIST_H
#define GPALIST_H

#include <cstdlib>
#include <string>
#include "ClassAndGrade.h"
using namespace std;

class GPAList {
    
public: 
    /**
     * GPA List Constructor for a GPAList object
     */
    GPAList();
    
    /**
     * The destructor for a GPAList object
     */
    virtual ~GPAList();
    
    /**
     * Add a course to the GPAList
     * @param course ClassAndGrade object.
     */
    virtual void addCourse(ClassAndGrade course);
    
    /**
     * List all of the courses in a GPAList object
     */
    virtual void listCourses();
    
    /**
     * Calculate the total GPA of classes in a GPAList
     * @return double; the GPA of all courses
     */
    virtual double getGPA();
    
    /**
     * Save all courses to a file
     * @param fileName name of file to save to
     */
    virtual void saveToFile(std::string fileName);
    
    /**
     * Load in courses from a file
     * @param fileName
     */
    virtual void pullFromFile(std::string fileName);
    
    
};




#endif /* GPALIST_H */

