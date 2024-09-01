#ifndef SINGETONS_HPP
#define SINGETONS_HPP

#include <vector>
#include <iostream>

enum class Profession {
    STUDENT,
    PROFESSOR,
    STAFF
};

enum class Module {
    MATHS,
    PHYSICS,
    PROGRAMMING,
    HISTORY
};

class Person {
    private:
        Person() { std::cout << "Person instance created." << std::endl; }
        ~Person() { std::cout << "Person instance destroyed." << std::endl; }
        static Person* instance;
        std::string _name;
        Profession _professionID;
        //std::pair<int, Course *> _subscribedCourses;
    public:
        Person(const Person&) = delete;
        Person& operator=(const Person&) = delete;
        static Person& getInstance()
        {
            if (!instance) {
                instance = new Person();
            }
            return *instance;
        }
        void someOperation() { std::cout<< "Person is performing some operation." << std::endl; }
        virtual std::string& getName() { return _name; };
};

class Room {
    private:
        Room() { std::cout << "Room instance created." << std::endl; }
        ~Room() { std::cout << "Room instance destroyed." << std::endl; }
        static Room* instance;
        std::string _name;
        int         _roomID;
        Module      _moduleOfStudy;
    public:
        Room(const Room&) = delete;
        Room& operator=(const Room&) = delete;
        static Room& getInstance()
        {
            if (!instance) {
                instance = new Room();
            }
            return *instance;
        }
        void someOperation() { std::cout<< "Room is performing some operation." << std::endl; }
};


#endif