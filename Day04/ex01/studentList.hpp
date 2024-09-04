#ifndef STUDENTLIST_HPP
#define STUDENTLIST_HPP

#include "person.hpp"

class StudentList
{
    private:
        std::vector<Person *> _studentList;
    protected:
        StudentList() {};
        static StudentList* _instance;

    public:
        static StudentList* getInstance();
        std::vector<Person *> getStudentList();
        Person* getStudent(Person* student);
        int addStudent(Person *student);
        int removeStudent(Person *student);
        virtual ~StudentList() {
            std::cout << "StudentList instance destroyed." << std::endl;
            this->_studentList.clear();
        };
};

#endif