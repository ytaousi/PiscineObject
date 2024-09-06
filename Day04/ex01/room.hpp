#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <string>

typedef enum Module {
    PROGRAMMING,
    HISTORY,
    PRINCIPALE_OFFICE,
    LIBRARY,
    HEALTH_CARE,
    PLAYGROUND,
    GYM
} t_module;

class Room {
    private:
        std::string     _name;
        static int      _uniqueID;
        int             _roomID;
        t_module        _roomType;
    public:
        Room(t_module roomType);
        int getID();
        std::string getType();
        void setName(std::string name);
        std::string getName();
};

#endif