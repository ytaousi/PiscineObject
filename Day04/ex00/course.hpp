#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
#include <vector>
#include <iostream>

class Student;
class Professor;

class Course
{
    private:
        std::string             _name;
        Professor*              _responsable;
        std::vector<Student*>   _students;
        int                     _numberOfClassToGraduate;
        int                     _maximumNumberOfStudent;
    public:
        Course(std::string p_name);
        void assign(Professor* p_professor);
        void subscribe(Student* p_student);
        std::string getName();
        Professor* getResponsable();
        std::vector<Student*> getStudents();
        int getNumberOfClassToGraduate();
        int getMaximumNumberOfStudent();
        void setName(std::string p_name);
        void setResponsable(Professor* p_professor);
        int  setStudent(Student* p_student);
        void setNumberOfClassToGraduate(int p_numberOfClassToGraduate);
        void setMaximumNumberOfStudent(int p_maximumNumberOfStudent);
        ~Course();
};

#endif