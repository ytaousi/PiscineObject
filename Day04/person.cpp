#include "person.hpp"

Person::Person(std::string p_name)
{
    this->setName(p_name);
    this->setCurrentRoom(NULL);
}

Person::~Person()
{
    ; // should review destructor
}

// Getters
std::string Person::getName()
{
    return this->_name;
}

Room* Person::getCurrentRoom()
{
    return this->_currentRoom;
}

// Setters
void Person::setName(std::string p_name)
{
    this->_name = p_name;
}

void Person::setCurrentRoom(Room* p_room)
{
    this->_currentRoom = p_room;
}


Student::Student(std::string p_name) : Person(p_name)
{
    ;
}

Student::~Student()
{
    ; // should review destructor
}

void Student::attendClass(Classroom* p_classroom)
{
    ;
}

void Student::exitClass()
{
    ;
}

void Student::graduate(Course* p_course)
{
    ;
}

std::vector<Course *> Student::getSubscribedCourse()
{
    return this->_subscribedCourse;
}

int Student::subscribeCourse(Course* p_course)
{
    for (std::vector<Course *>::iterator it = this->_subscribedCourse.begin(); it != this->_subscribedCourse.end(); it++)
    {
        if (*it == p_course)
        {
            std::cout << " Student Already Subscribed to this Course " << std::endl;
            return 0;
        }
    }
    this->_subscribedCourse.push_back(p_course);
    std::cout << " Student Subscribed Successfully to this Course " << std::endl;
    return 1;
}