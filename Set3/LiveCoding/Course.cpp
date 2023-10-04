#include "Course.h"
#include <string>
#include <iostream>

using namespace std;

Course::Course(const string TITLE, const int ENROLLMENT){
    _title = TITLE;
    _enrollment = ENROLLMENT;
    checkForNegativeStudents();
}

Course::Course(const string TITLE){
    _title = TITLE;
    _enrollment = 0;
}

Course::Course(){
    _title = "No title";
    _enrollment = 0;
}

string Course::getTitle(){
    return _title;
}

int Course::getEnrollment(){
    return _enrollment;
}

void Course::registerStudent(){
    _enrollment++;
}

void Course::withdrawStudent(){
    _enrollment--;
    checkForNegativeStudents();
}

void Course::checkForNegativeStudents(){
    if(_enrollment < 0) {
        cerr << "Cannot have negative students in a class!" << endl;
        _enrollment = 0;
    }
}