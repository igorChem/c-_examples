//
//  Student.h
//  StudentInformationAnalyzer
//
//  Created by Adam Spindler on 1/4/14.
//  Copyright (c) 2014 Adam Spindler. All rights reserved.
//

#ifndef __StudentInformationAnalyzer__Student__
#define __StudentInformationAnalyzer__Student__

#include <string>
#include <sstream>

class Student
{
public:
    Student(std::string studentInformation);
    
    std::string getFirstName();
    std::string getLastName();
    std::string getName();
    int getId();
    double getGPA();
    
private:
    std::string firstName;
    std::string lastName;
    int id;
    double gpa;
};

#endif