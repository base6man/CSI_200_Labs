#include <iostream>
#include <vector>
#include "Course.h"
using namespace std;

int main() {
    vector<Course> courseCatalog;
    courseCatalog.push_back(Course("CSCI 200"));
    courseCatalog.push_back(Course("MATH 112", 25));

    for(size_t i = 0; i < 50; i++){
        courseCatalog.at(0).registerStudent();
    }
    courseCatalog.at(1).withdrawStudent();
    courseCatalog.at(1).withdrawStudent();

    for(size_t i = 0; i < courseCatalog.size(); i++){

        cout << courseCatalog.at(i).getTitle() << "\t" << courseCatalog.at(i).getEnrollment() << endl;
    }
    return 0;
}
