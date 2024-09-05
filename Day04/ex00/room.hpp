#ifndef ROOM_HPP
#define ROOM_HPP

#include "person.hpp"
#include "course.hpp"
#include "form.hpp"

class Room
{
    private:
        long long ID;
        std::vector<Person*> _occupants;
    public:
        Room();
        virtual ~Room();
        bool canEnter(Person*);
        void enter(Person*);
        void exit(Person*);
        
        void printOccupant();
};

class Classroom : public Room
{
    private:
        Course* _currentRoom;
    public:
        Classroom();
        ~Classroom();
        void assignCourse(Course* p_course);
};

class SecretarialOffice: public Room
{
    private:
        std::vector<Form*> _archivedForms;
    public:
        SecretarialOffice();
        ~SecretarialOffice();
};

class HeadmasterOffice : public Room
{
    private:
    public:
        HeadmasterOffice();
        ~HeadmasterOffice();
};

class StaffRestRoom : public Room
{
    private:
    public:
        StaffRestRoom();
        ~StaffRestRoom();
};

class Courtyard : public Room
{
    private:
    public:
        Courtyard();
        ~Courtyard();
};

#endif