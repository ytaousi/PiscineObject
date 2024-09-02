#ifndef STUDENTLIST_HPP
#define STUDENTLIST_HPP

#include "singetons.hpp"

class StudentList //: public Person
{
    private:
        std::vector<Person *> _studentList;
    public:
        StudentList();
        ~StudentList();
        std::vector<Person *> getStudentList();
        Person& getStudent(Person* student);
        int addStudent(Person *student);
        int removeStudent(Person *student);
};

#endif