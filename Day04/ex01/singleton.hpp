#ifndef SINGLETON_HPP
#define SINGLETON_HPP


#include <iostream>
#include <vector>

#include "room.hpp"
#include "person.hpp"

template <class T, class U>
class Singleton
{
    private:
        std::vector<U *> _List;
    protected:
        Singleton() {};
        static T *_instance;
    public:
        static T *getInstance();
        virtual ~Singleton();
        std::vector<U *> getList();
        U* getObject(U *p_var);
        int addObject(U *p_var);
        int removeObject(U *p_var);
};

//    template <T, U>
// Singelton<CourseList, Room>

class RoomList : public Singleton<RoomList, Room>
{
    private:
        std::vector<Room *> _roomList;
    public:
        RoomList() {};
        ~RoomList() {this->_roomList.clear();};

};

class CourseList : public Singleton<CourseList, Room>
{
    private:
        std::vector<Room *> _courseList;
    public:
        CourseList() {};
        ~CourseList() {this->_courseList.clear();};
};

class StaffList : public Singleton<StaffList, Person>
{
    private:
        std::vector<Person *> _staffList;
    public:
        StaffList() {};
        ~StaffList() {this->_staffList.clear();};
};

class StudentList : public Singleton<StudentList, Person>
{
    private:
        std::vector<Person *> _studentList;

    public:
        StudentList() {};
        ~StudentList() {this->_studentList.clear();};
};


#endif