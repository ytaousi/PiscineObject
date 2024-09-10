#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>

template <typename T>
class Room
{
    private:
        T* _room;
        static int _uniqueID;
        int _roomID;
        std::string _roomName;
    public:
        Room() {
            this->_room = new T();
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
        T* getRoom() {
            return this->_room;
        };
};

class Course : public Room<Course>
{
    private:
    public:
        Course();
        ~Course();
};

#endif