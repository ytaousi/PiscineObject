#ifndef PERSON_HPP
#define PERSON_HPP

#include "room.hpp"
#include <vector>
#include <string>

# define GRADUATION 7

class Person
{
    protected:
        std::string _name;
        std::vector<Room *> _subscribedCourses;
        Room *              _currentRoom;
        Person() {};
    public:
        virtual ~Person() {};
        void setName(std::string p_name) {
            this->_name = p_name;
        };
        void setCurrentRoom(Room * p_room) {
            this->_currentRoom = p_room;
        };
        std::string getName() {
            return this->_name;
        };
        Room * getCurrentRoom() {
            return this->_currentRoom;
        };
        std::vector<Room *> getSubscribedCourses() {
            return this->_subscribedCourses;
        };
        virtual int assignRoom(Room * p_room) = 0;
};

class Student : public Person
{
    private:
        int _isGraduated;
        int _coursesToGraduate;
    public:
        Student() : Person(){
            this->_isGraduated = 0;
            this->_coursesToGraduate = 0;
        };
        ~Student() {
            this->_name = "";
            this->_currentRoom = NULL;
            this->_subscribedCourses.clear();
        };
        int assignRoom(Room * p_room) {
            std::vector<Room *> subscribedCourses = this->getSubscribedCourses();
            for (size_t i = 0; i < subscribedCourses.size(); i++)
            {
                if (subscribedCourses[i] == p_room)
                {
                    std::cout << " This Course is already affected to me : " << subscribedCourses[i]->getRoomName() << std::endl;
                    return 1;
                }
            }
            std::cout << "I Can Start Reading that new Stuff : " << p_room->getRoomName() << std::endl;
            this->_subscribedCourses.push_back(p_room);
            return 0;
        };
        int attendClass(Room * p_classroom) {
            std::vector<Room *> subscribedCourses = this->getSubscribedCourses();
            Room* currentRoom = this->getCurrentRoom();
            for (size_t i = 0; i < subscribedCourses.size(); i++)
            {
                if (subscribedCourses[i] == p_classroom)
                {
                    if (p_classroom == currentRoom)
                    {
                        std::cout << "I am ready to start the class to find a job : " << subscribedCourses[i]->getRoomName() << std::endl;
                        return 0;
                    }
                    else
                    {
                        std::cout << "Ready to starting learning this module : " << subscribedCourses[i]->getRoomName() << " but this is not the currentRoom Affected to me : " << (this->getCurrentRoom() == NULL ? "NULL": this->getCurrentRoom()->getRoomName()) << std::endl;
                        return 1;
                    }
                }
            }
            std::cout << "I am not Subscribed to This Course : " << p_classroom->getRoomName() << " I need to Request It from Headmaster" << std::endl;
            return 1;
        };
        void graduate(Course * p_course) { (void )p_course; };
};
// professor can be affected to multiple courseRoom's since it can teach multiple disciplines
class Professor : public Person
{
    private:
    public:
        Professor() : Person(){}
        ~Professor() {
            this->_name = "";
            this->_currentRoom = NULL;
            this->_subscribedCourses.clear();
        };
        int assignRoom(Room * p_room) {
            std::vector<Room *> subscribedCourses = this->getSubscribedCourses();
            for (size_t i = 0; i < subscribedCourses.size() ; i++)
            {
                if (subscribedCourses[i] == p_room)
                {
                    std::cout << " This CourseRoom is already affected to me " << std::endl;
                    return 1;
                }
            }
            std::cout << "I Can Start Teaching that new Stuff" << std::endl;
            this->_subscribedCourses.push_back(p_room);
            return 0;
        };
        int doClass(Room* p_classroom) {
            std::vector<Room *> affectedClasses = this->getSubscribedCourses();
            Room * currentRoom = this->getCurrentRoom();
            for(size_t i = 0 ; i < affectedClasses.size(); i++)
            {
                if (p_classroom == affectedClasses[i])
                {
                    if (p_classroom == currentRoom)
                    {
                        std::cout << "I am ready to start teaching at " << this->getCurrentRoom()->getRoomName() << std::endl;
                        return 0;
                    }
                    else
                    {
                        std::cout << "I do Teach This Module : " << affectedClasses[i]->getRoomName()<< " but that is not the currentRoom affected to me : " << (this->getCurrentRoom() == NULL ?  " NULL " : this->getCurrentRoom()->getRoomName()) << std::endl;
                        return 1;
                    }
                }
            }
            std::cout << "I am not assigned to this class, I need to request it from the headmaster" << std::endl;
            return 1;
        };
        void studentNeedToGraduateForm(Student * p_student) {(void)p_student;};
};



#endif