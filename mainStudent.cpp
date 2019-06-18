//
//  mainStudemt.cpp
//  StudentInformationAnalyzer
//
//  Created by Adam Spindler on 1/4/14.
//  Copyright (c) 2014 Adam Spindler. All rights reserved.
//

#include <iostream>
#include <exception>
#include <string>

#include "Student.h"
#include "StudentList.h"

using namespace std;

void printStudent(Student student)
{
    cout << "Name: " << student.getName() << endl;
    cout << "ID: " << student.getId() << endl;
    cout << "GPA: " << student.getGPA() << endl;
    cout << endl;
}

int main(int argc, const char * argv[])
{
    try
    {
        if (argc != 2)
        {
            cout << "Usage: StudentInformationAnalyzer PATH_TO_STUDENT_FILE" << endl;
            return -1;
        }
        
        string path(argv[1]);
        StudentList list(path);
        
        cout << "Valedictorian: " << endl << endl;
        printStudent(list.getValedictorian());
        
        cout << endl << "Honor Role Students: " << endl << endl;
        for (Student s : list.getHonorRollStudents())
            printStudent(s);
        
        cout << endl << "Failing Students: " << endl << endl;
        for (Student s : list.getFailingStudents())
            printStudent(s);
    }
    catch (exception &e)
    {
        cout << "An exception was thrown." << endl;
        cout << "\t" << e.what() << endl;
        
        return -1;
    }
    
    return 0;
}