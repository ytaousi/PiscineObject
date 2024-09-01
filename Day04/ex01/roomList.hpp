#ifndef ROOMLIST_HPP
#define ROOMLIST_HPP

#include "singetons.hpp"

class RoomList : public Room
{
    private:
        int _roomID;
        std::vector<Room *> _roomList;
    public:
        RoomList();
        ~RoomList();
};

#endif