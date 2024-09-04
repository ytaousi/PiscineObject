#include "studentList.hpp"

StudentList* StudentList::_instance = NULL;

StudentList* StudentList::getInstance()
{
    if (_instance == NULL)
    {
        _instance = new StudentList();
    }
    return _instance;
}

std::vector<Person *> StudentList::getStudentList()
{
    return this->_studentList;
}

Person* StudentList::getStudent(Person* student)
{
    for (size_t i = 0; i < _studentList.size(); i++)
    {
        if (_studentList[i] == student)
        {
            return _studentList[i];
        }
    }
    std::cout << " Student Not Found " << std::endl;
    return NULL;
}

int StudentList::removeStudent(Person *student)
{
    for (std::vector<Person *>::iterator it; it != _studentList.end(); it++) {
        if (*it == student) {
            _studentList.erase(it);
           return 0;
        }
    }
    std::cout << " Student Not Found " << std::endl;
    return 1;
}

int StudentList::addStudent(Person *student)
{
    for (std::vector<Person *>::iterator it = _studentList.begin() ; it != _studentList.end(); it++)
    {
        if (*it == student)
        {
            std::cout << " Student Already Exists " << std::endl;
            return 1;
        }
    }
    this->_studentList.push_back(student);
    return 0;
}