#include "person.hpp"

#include <iostream>

Person::Person(std::string p_name)
{
    this->_name = p_name;
    this->_currentRoom = nullptr;
}

Person::~Person()
{
    this->_name = "";
    this->_currentRoom = nullptr;
}

Room* Person::room()
{
    return (this->_currentRoom);
}


Student::Student(std::string p_name) : Person(p_name)
{
    std::cout << " Student Construct " << std::endl;
}

Student::~Student()
{
    this->setName("");
    this->_subscribedCourse.clear();
    std::cout << " Student Destruct " << std::endl;
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

Staff::Staff(std::string p_name) : Person(p_name)
{
    ;
}

Staff::~Staff()
{
    this->setName("");
    std::cout << " Staff Destruct " << std::endl;
}

void Staff::sign(Form* p_form)
{
    ;
}

Headmaster::Headmaster(std::string p_name) : Staff(p_name)
{
    ;
}

Headmaster::~Headmaster()
{
    this->setName("");
    this->_formToValidate.clear();
    std::cout << " Headmaster Destruct " << std::endl;
}

void Headmaster::receiveForm(Form* p_form)
{
    ;
}


Secretary::Secretary(std::string p_name) : Staff(p_name)
{
    ;
}

Secretary::~Secretary()
{
    this->setName("");
    std::cout << " Secretary Destruct " << std::endl;
}

Professor::Professor(std::string p_name) : Staff(p_name)
{
    ;
}

Professor::~Professor()
{
    this->setName("");
    std::cout << " Professor Destruct " << std::endl;
}

void Professor::assignCourse(Course* p_course)
{
    ;
}

void Professor::doClass()
{
    ;
}

void Professor::closeCourse()
{
    ;
}