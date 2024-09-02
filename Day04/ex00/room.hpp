#ifndef ROOM_HPP
#define ROOM_HPP

#include <vector>
#include <iostream>

class Person;
class Course;
class Form;

class Room
{
    private:
        static int              _ID;
        int                     _roomID;
        std::vector<Person*>    _occupants;
        int                     _maximumNumberOfOccupants;
        Course*                 _currentCourse;
    public:
        Room();
        bool canEnter(Person*);
        void enter(Person*);
        void exit(Person*);
        Course* getCurrentCourse();
        std::vector<Person*> getOccupants();
        int getRoomID();
        int getMaximumNumberOfOccupants();
        void setRoomID(int p_roomID);
        void addPersonToRoomOccupants(std::vector<Person*> p_occupants);
        void setMaximumNumberOfOccupants(int p_maximumNumberOfOccupants);
        void printOccupant();
        ~Room();
};

class Classroom : public Room
{
    private:
        Course* _currentRoom;
    public:
        Classroom();
        void assignCourse(Course* p_course);
};

class SecretarialOffice: public Room
{
    private:
        std::vector<Form*> _archivedForms;
    public:
};

class HeadmasterOffice : public Room
{
    private:
    public:
};

class StaffRestRoom : public Room
{
    private:
    public:
};

class Courtyard : public Room
{
    private:
    public:
};

#endif