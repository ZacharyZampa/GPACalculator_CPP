/* 
 * Copyright (C) 2019 zackzampa@gmail.com
 */

/* 
 * File:   ClassAndGrade.h
 * Author: Zachary Zampa
 *
 * Created on March 1, 2019, 8:02 PM
 * 
 * Purpose: Create the template for creating a ClassAndGrade object for the 
 * respective course.
 * 
 */

#ifndef CLASSANDGRADE_H
#define CLASSANDGRADE_H

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class ClassAndGrade {
    
public: 
    /**
     * The constructor for a course object
     */
    ClassAndGrade() {
        this->classCredits = -1;
        this->classGPA = -1;
        this->className = "";
    }
    
    /**
     * The destructor for a course object
     */
    virtual ~ClassAndGrade();
    
    
    /**
     * Getter
     * @return className 
     */
    virtual std::string getClassName() const;
    
    /**
     * Getter
     * @return classGPA 
     */
    virtual double getClassGPA() const;
    
    /**
     * Getter
     * @return classCredits
     */
    virtual int getClassCredits() const;
    
    /**
     * Setter
     * @param className
     */
    virtual void setClassName(std::string& className);
    
    /**
     * Setter
     * @param className
     */
    virtual void setClassGPA(double classGPA);
    
    /**
     * Setter
     * @param className
     */
    virtual void setClassCredits(int classCredits);
    
    /**
     * Return a string representation of course info
     * @return string of course info
     */
    virtual std::string toString()  const;
    
    friend std::ostream& operator<<(std::ostream& os, const ClassAndGrade p);


private:
    std::string className;
    double classGPA;
    int classCredits;
    
};





#endif /* CLASSANDGRADE_H */

