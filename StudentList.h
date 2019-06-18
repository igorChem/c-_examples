
//
//  StudentList.h
//  StudentInformationAnalyzer
//
//  Created by Adam Spindler on 1/4/14.
//  Copyright (c) 2014 Adam Spindler. All rights reserved.
//

#ifndef __StudentInformationAnalyzer__StudentList__
#define __StudentInformationAnalyzer__StudentList__

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <exception>

#include "Student.h"

class StudentList
{
public:
    StudentList(std::string filePath);
    
    Student getValedictorian();
    std::vector<Student> getHonorRollStudents();
    std::vector<Student> getFailingStudents();
    
private:
    std::vector<Student> students;
};

class NoValedictorianException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "StudentList: No Valedictorian";
    }
};

#endif