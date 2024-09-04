#include "roomList.hpp"

RoomList* RoomList::_instance = 0;


RoomList* RoomList::getInstance()
{
    if (_instance == 0) {
        _instance = new RoomList();
    }
    return _instance;
}

std::vector<Room *> RoomList::getRoomList()
{
    return this->_roomList;
}

Room* RoomList::getRoom(Room *p_room)
{
    for (size_t i = 0; i < _roomList.size(); i++)
    {
        if (_roomList[i] == p_room)
        {
            return _roomList[i];
        }
    }
    std::cout << " Room Not Found " << std::endl;
    return NULL;
}

int RoomList::addRoom(Room *p_room)
{
    for (std::vector<Room *>::iterator it = _roomList.begin(); it != _roomList.end(); it++)
    {
        if (*it == p_room)
        {
            std::cout << " Room Already Exists " << std::endl;
            return 1;
        }
    }
    this->_roomList.push_back(p_room);
    return 0;
}

int RoomList::removeRoom(Room *p_room)
{
    for (std::vector<Room *>::iterator it = _roomList.begin(); it != _roomList.end(); it++)
    {
        if (*it == p_room)
        {
            _roomList.erase(it);
            return 0;
        }
    }
    std::cout << " Room Not Found " << std::endl;
    return 1;
}