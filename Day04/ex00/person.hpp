#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <vector>
#include <iostream>

class Room;
class Course;
class Form;
class Classroom;
enum class FormType;


class Person
{
    private:
        std::string _name;
        Room* _currentRoom;
    public:
        Person(std::string p_name);
        std::string getName();
        Room* getCurrentRoom();
        void setName(std::string p_name);
        void setCurrentRoom(Room* p_room);
        ~Person();
};

class Student : public Person
{
    private:
        std::vector<Course*> _subscribedCourse;

    public:
        Student(std::string p_name);
        void attendClass(Classroom* p_classroom);
        void exitClass();
        void graduate(Course* p_course);
        std::vector<Course *> getSubscribedCourse();
        int subscribeCourse(Course* p_course);
        ~Student();
};

class Staff : public Person
{
    private:

    public:
        void sign(Form* p_form);
};

class Professor : public Staff
{
    private:
        Course* _currentCourse;

    public:
        void assignCourse(Course* p_course);
        void doClass();
        void closeCourse();
};

class Headmaster : public Staff
{
    private:
        std::vector<Form*> _formToValidate;
        
    public:
        void receiveForm(Form* p_form);
};

class Secretary : public Staff
{
    private:

    public:
        Form* createForm(FormType p_formType);
        void archiveForm();
};

#endif