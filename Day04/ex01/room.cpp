#include "room.hpp"

int Room::_uniqueID = 0;

Room::Room(t_module p_roomType)
{
    this->_roomID = _uniqueID++;
    this->_roomType = p_roomType;
    this->_name = getRoomType();
}
int Room::getRoomID()
{
    return this->_roomID;
}

std::string Room::getRoomType()
{
    if (this->_roomType == PRINCIPALE_OFFICE)
        return "PRINCIPALE_OFFICE";
    else if (this->_roomType == HISTORY)
        return "HISTORY";
    else if (this->_roomType == PROGRAMMING)
        return "Programming";
    else if (this->_roomType == LIBRARY)
        return "LIBRARY";
    else if (this->_roomType == HEALTH_CARE)
        return "HEALTH_CARE";
    else if (this->_roomType == PLAYGROUND)
        return "PLAYGROUND";
    else if (this->_roomType == GYM)
        return "GYM";
    else
        return "Unknown Room";
}

void Room::setRoomName(std::string p_name)
{
    this->_name = p_name;
}

std::string Room::getRoomName()
{
    return this->_name;
}