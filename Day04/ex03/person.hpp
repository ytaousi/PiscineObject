#ifndef PERSON_HPP
#define PERSON_HPP

#include "room.hpp"
#include <vector>
#include <string>

# define GRADUATION 7

template <typename T>
class Person
{
    protected:
        T* _person;
        std::string _name;
        std::vector<Room<Course> *> _subscribedCourses;
        Room<Course> *              _currentRoom;
    public:
        Person() {};
        virtual ~Person() {};
        void setName(std::string p_name) {
            this->_name = p_name;
        };
        void setCurrentRoom(Room<Course> * p_room) {
            this->_currentRoom = p_room;
        };
        std::string getName() {
            return this->_name;
        };
        Room<Course> * getCurrentRoom() {
            return this->_currentRoom;
        };
};

class Student : public Person<Student>
{
    private:
        int _isGraduated;
        int _coursesToGraduate;
    public:
        Student() : Person<Student>(){
            this->_isGraduated = 0;
            this->_coursesToGraduate = 0;
        };
        ~Student() {
            this->_name = "";
            this->_currentRoom = NULL;
            this->_subscribedCourses.clear();
            delete this->_person;
        };
        void attendClass(Course * p_classroom) { (void )p_classroom; };
        void graduate(Course * p_course) { (void )p_course; };
};

class Professor : public Person<Professor>
{
    private:
    public:
        Professor() : Person<Professor>(){}
        ~Professor() {
            this->_name = "";
            this->_currentRoom = NULL;
            this->_subscribedCourses.clear();
            delete this->_person;
        };
        void doClass(){};
        void studentNeedToGraduateForm(Student * p_student) {(void)p_student;};
};




template class Person<Professor>;
template class Person<Student>;

#endif