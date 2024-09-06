#include "person.hpp"

#include <iostream>

Person::Person(std::string p_name)
{
    this->_name = p_name;
    this->_currentRoom = NULL;
}

Person::~Person()
{
    this->_name = "";
    this->_currentRoom = NULL;
}

Room* Person::room()
{
    return (this->_currentRoom);
}

void Person::setName(std::string p_name)
{
    this->_name = p_name;
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
    (void)p_classroom;
    std::cout << " Student attendClass function called" << std::endl;
}


void Student::exitClass()
{
    std::cout << " Student exitClass function called" << std::endl;
}

void Student::graduate(Course* p_course)
{
    (void)p_course;
    std::cout << " Student graduate function called" << std::endl;
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
    (void)p_form;
    std::cout << " Staff sign function called" << std::endl;
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
    (void)p_form;
    std::cout << " Headmaster receiveForm function called" << std::endl;
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
    (void)p_course;
    std::cout << " Professor assignCourse function called" << std::endl;
}

void Professor::doClass()
{
    std::cout << " Professor doClass function called" << std::endl;
}

void Professor::closeCourse()
{
    std::cout << " Professor closeCourse function called" << std::endl;
}