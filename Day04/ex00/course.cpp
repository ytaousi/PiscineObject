#include "course.hpp"

#include <iostream>

Course::Course(std::string p_name)
{
    this->_name = p_name;
    this->_responsable = NULL;
    this->_numberOfClassToGraduate = 10;
    this->_maximumNumberOfStudent = 10;
}

Course::~Course()
{
    this->_students.clear();
    this->_name.clear();
    this->_responsable = NULL;
    this->_numberOfClassToGraduate = 0;
    this->_maximumNumberOfStudent = 0;
}

void Course::assign(Professor* p_professor)
{
    this->_responsable = p_professor;
}


void Course::subscribe(Student* p_student)
{
    if (this->_students.size() < (size_t)this->_maximumNumberOfStudent)
    {
        this->_students.push_back(p_student);
    }
    else
        std::cout << " Course Full " << std::endl;
}