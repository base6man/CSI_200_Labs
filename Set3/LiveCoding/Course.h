#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course{
    private:
        int _enrollment;
        std::string _title;
        void checkForNegativeStudents();
    public:
        Course(const std::string TITLE, const int ENROLLMENT);
        Course(const std::string TITLE);
        Course();
        std::string getTitle();
        int getEnrollment();
        void registerStudent();
        void withdrawStudent();
};


#endif