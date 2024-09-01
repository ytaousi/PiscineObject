#ifndef STUDENTLIST_HPP
#define STUDENTLIST_HPP

#include "singetons.hpp"

class StudentList : public Person
{
    private:
        std::vector<Person *> _studentList;
    public:
        StudentList();
        ~StudentList();
        std::vector<Person *> getStudentList() {
            return this->_studentList;
        };
        Person& getStudent(Person* student) {
            for (std::vector<Person *>::iterator it; it != _studentList.end(); it++) {
                if (*it == student) {
                    return **it;
                }
            }
            std::cout << " Student Not Found " << std::endl;
        };
        void addStudent(Person *student) {
            _studentList.push_back(student);
        };
        void removeStudent(Person *student) {
            for (std::vector<Person *>::iterator it; it != _studentList.end(); it++) {
                if (*it == student) {
                    _studentList.erase(it);
                    std::cout << " Student Removed " << std::endl;
                    return;
                }
            }
            std::cout << " Student Not Found " << std::endl;
        };
};

#endif