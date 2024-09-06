#include "room.hpp"

#include <iostream>

Room::Room()
{
    this->ID = 0;
    std::cout << " Room Construct " << std::endl;
}

Room::~Room()
{
    std::cout << " Room Destruct " << std::endl;
}

bool Room::canEnter(Person* p_person)
{
    (void)p_person;
    std::cout << " Room canEnter function called" << std::endl;
    return (true);
}

void Room::enter(Person* p_person)
{
    (void)p_person;
    std::cout << " Room enter function called" << std::endl;
}


void Room::exit(Person* p_person)
{
    (void)p_person;
    std::cout << " Room exit function called" << std::endl;
}

void printOccupant()
{
    std::cout << " Room printOccupant function called" << std::endl;
}


Classroom::Classroom()
{
    std::cout << " Classroom Construct " << std::endl;
}

Classroom::~Classroom()
{
    std::cout << " Classroom Destruct " << std::endl;
}

void Classroom::assignCourse(Course* p_course)
{
    (void)p_course;
    std::cout << " Classroom assignCourse function called" << std::endl;
}

SecretarialOffice::SecretarialOffice()
{
    std::cout << " SecretarialOffice Construct " << std::endl;
}

SecretarialOffice::~SecretarialOffice()
{
    std::cout << " SecretarialOffice Destruct " << std::endl;
}


HeadmasterOffice::HeadmasterOffice()
{
    std::cout << " HeadmasterOffice Construct " << std::endl;
}

HeadmasterOffice::~HeadmasterOffice()
{
    std::cout << " HeadmasterOffice Destruct " << std::endl;
}


StaffRestRoom::StaffRestRoom()
{
    std::cout << " StaffRestRoom Construct " << std::endl;
}

StaffRestRoom::~StaffRestRoom()
{
    std::cout << " StaffRestRoom Destruct " << std::endl;
}

Courtyard::Courtyard()
{
    std::cout << " Courtyard Construct " << std::endl;
}

Courtyard::~Courtyard()
{
    std::cout << " Courtyard Destruct " << std::endl;
}