#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <iostream>


class Room
{
    private:
        static int _uniqueID;
        int _roomID;
        std::string _roomName;
    public:
        Room() {
            this->_roomID = _uniqueID++;
            this->_roomName = "";
        };
        ~Room(){};
        void setRoomName(std::string p_name) {
            this->_roomName = p_name;
        };
        std::string getRoomName() {
            return this->_roomName;
        };
        int getRoomID() {
            return this->_roomID;
        };
};

class Course : public Room
{
    private:
    public:
        Course(): Room(){};
        ~Course(){};
};

#endif