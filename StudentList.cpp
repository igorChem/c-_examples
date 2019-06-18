//
//  StudentList.cpp
//  StudentInformationAnalyzer
//
//  Created by Adam Spindler on 1/4/14.
//  Copyright (c) 2014 Adam Spindler. All rights reserved.
//

#include "StudentList.h"

#define FAILING_GRADE 65
#define HONORROLE_GRADE 90

using namespace std;

StudentList::StudentList(string filePath)
{
    ifstream studentFile(filePath);
    
    string lineContents;
    while (!studentFile.eof())
    {
        getline(studentFile, lineContents);
        
        
        Student s(lineContents);
        students.push_back(s);
    }
    studentFile.close();
    
    sort(students.begin(), students.end(), [](Student &s1, Student &s2)
    										{
                                                return s1.getGPA() > s2.getGPA();
                                            });
}

Student StudentList::getValedictorian()
{
    if (students.size() == 0 || students.at(0).getGPA() < FAILING_GRADE)
        throw NoValedictorianException();
    return students.at(0);
}

vector<Student> StudentList::getHonorRollStudents()
{
    vector<Student> toReturn;
    for (Student s : students)
    {
        if (s.getGPA() < HONORROLE_GRADE)
            break;
        else
        	toReturn.push_back(s);
    }
    
    return toReturn;
}

vector<Student> StudentList::getFailingStudents()
{
    vector<Student> toReturn;
    for (vector<Student>::reverse_iterator iter = students.rbegin(); iter < students.rend(); iter++)
    {
        if (iter->getGPA() >= FAILING_GRADE)
            break;
        else
            toReturn.push_back(*iter);
    }
    
    return toReturn;
}