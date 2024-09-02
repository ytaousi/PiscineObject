#include "studentList.hpp"

std::vector<Person *> StudentList::getStudentList()
{
    return this->_studentList;
}

Person& StudentList::getStudent(Person* student)
{
    for (std::vector<Person *>::iterator it; it != _studentList.end(); it++) {
        if (*it == student)
            return **it;
    }
    std::cout << " Student Not Found " << std::endl;
}

int StudentList::removeStudent(Person *student)
{
    for (std::vector<Person *>::iterator it; it != _studentList.end(); it++) {
        if (*it == student) {
            _studentList.erase(it);
            std::cout << " Student Removed " << std::endl;
           return 0;
        }
    }
    std::cout << " Student Not Found " << std::endl;
    return 1;
}

int StudentList::addStudent(Person *student)
{
    for (std::vector<Person *>::iterator it; it != _studentList.end(); it++)
    {
        if (*it == student)
        {
            std::cout << " Student Already Exists " << std::endl;
            return 1;
        }
    }
    this->_studentList.push_back(student);
    std::cout << " Student Added Successfully " << std::endl;
    return 0;
}