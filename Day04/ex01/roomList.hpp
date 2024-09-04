#ifndef ROOMLIST_HPP
#define ROOMLIST_HPP

#include "person.hpp"
#include "room.hpp"

class RoomList
{
    private:
        std::vector<Room *> _roomList;
    protected:
        RoomList() {};
        static RoomList *_instance;
    public:
        static RoomList *getInstance();
        virtual ~RoomList() {this->_roomList.clear();};
        std::vector<Room *> getRoomList();
        Room* getRoom(Room *p_room);
        int addRoom(Room *p_room);
        int removeRoom(Room *p_room);
};

#endif