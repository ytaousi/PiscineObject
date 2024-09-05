#ifndef COURSE_HPP
#define COURSE_HPP

#include "person.hpp"
#include <iostream>
#include <vector>
#include <string>

class Course
{
    private:
        std::string _name;
        Professor* _responsable;
        std::vector<Student*> _students;
        int _numberOfClassToGraduate;
        int _maximumNumberOfStudent;
    public:
        Course(std::string p_name);
        ~Course();
        void assign(Professor* p_professor);
        void subscribe(Student* p_student);
};

#endif