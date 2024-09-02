#include "room.hpp"

int Room::_ID = 0;

Room::Room()
{
    this->setRoomID(++_ID);
}

Room::~Room()
{
    ;
}

// Getters
Course* Room::getCurrentCourse()
{
    return this->_currentCourse;
}

int Room::getRoomID()
{
    return this->_roomID;
}

std::vector<Person*> Room::getOccupants()
{
    return this->_occupants;
}

int Room::getMaximumNumberOfOccupants()
{
    return this->_maximumNumberOfOccupants;
}

// Setters
void Room::setRoomID(int p_roomID)
{
    this->_roomID = p_roomID;
}
void Room::addPersonToRoomOccupants(std::vector<Person*> p_occupants)
{
    for (std::vector<Person *>::iterator it = p_occupants.begin(); it != p_occupants.end(); it++)
    {
        ;
    }
}

void Room::setMaximumNumberOfOccupants(int p_maximumNumberOfOccupants)
{
    this->_maximumNumberOfOccupants = p_maximumNumberOfOccupants;
}

//

bool Room::canEnter(Person *p_person)
{

}

void Room::enter(Person *p_person)
{
    ;
}

void Room::exit(Person *p_person)
{
    ;
}

void Room::printOccupant()
{
    ;
}