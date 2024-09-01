#include "course.hpp"


Course::Course(std::string p_name)
{
    this->setName(p_name);
    this->setResponsable(NULL);
    this->setNumberOfClassToGraduate(0);
    this->setMaximumNumberOfStudent(0);
    this->_students.clear();
}

Course::~Course()
{
    ; // should review destructor
}

void Course::assign(Professor* p_professor)
{
    if (this->getResponsable() == NULL)
    {
        this->setResponsable(p_professor);
        std::cout << " Professor Assigned Successfully " << std::endl;
    }
    else
    {
        std::cout << " Professor Already Assigned " << std::endl;
    }
}

void Course::subscribe(Student* p_student)
{
    if (this->setStudent(p_student) == 1)
    {
        std::cout << " Student Subscribed Successfully to this Course " << std::endl;
    }
    else
    {
        std::cout << " Student Already Subscribed to this Course " << std::endl;
    }
}

// Getters
std::string Course::getName()
{
    return this->_name;
}

Professor* Course::getResponsable()
{
    return this->_responsable;
}

std::vector<Student*> Course::getStudents()
{
    return this->_students;
}

int Course::getNumberOfClassToGraduate()
{
    return this->_numberOfClassToGraduate;
}

int Course::getMaximumNumberOfStudent()
{
    return this->_maximumNumberOfStudent;
}

// Setters

void Course::setName(std::string p_name)
{
    this->_name = p_name;
}

void Course::setResponsable(Professor* p_professor)
{
    this->_responsable = p_professor;
}

int Course::setStudent(Student* p_student)
{
    for (std::vector<Student *>::iterator it = this->_students.begin(); it != this->_students.end(); it++)
    {
        if (*it == p_student)
        {
            std::cout << " Student Already Exist " << std::endl;
            return 0;
        }
    }
    this->_students.push_back(p_student);
    std::cout << " Student Added Successfully " << std::endl;
    return 1;
}

void Course::setNumberOfClassToGraduate(int p_numberOfClassToGraduate)
{
    this->_numberOfClassToGraduate = p_numberOfClassToGraduate;
}

void Course::setMaximumNumberOfStudent(int p_maximumNumberOfStudent)
{
    this->_maximumNumberOfStudent = p_maximumNumberOfStudent;
}