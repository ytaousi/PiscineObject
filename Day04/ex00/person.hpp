#ifndef PERSON_HPP
#define PERSON_HPP

#include "utils.hpp"

class Person
{
    private:
        std::string _name;
        Room* _currentRoom;
    public:
        Person(std::string p_name);
        void setName(std::string p_name);
        ~Person();
        Room* room();
};

class Student : public Person
{
    private:
        std::vector<Course*> _subscribedCourse;

    public:
        Student(std::string p_name);
        ~Student();
        void attendClass(Classroom* p_classroom);
        void exitClass();
        void graduate(Course* p_course);
};

class Staff : public Person
{
    private:

    public:
        Staff(std::string p_name);
        ~Staff();
        void sign(Form* p_form);
};

class Headmaster : public Staff
{
    private:
        std::vector<Form*> _formToValidate;
        
    public:
        Headmaster(std::string p_name);
        ~Headmaster();
        void receiveForm(Form* p_form);
};

class Secretary : public Staff
{
    private:

    public:
        Secretary(std::string p_name);
        ~Secretary();
        Form* createForm(FormType p_formType);
        void archiveForm();
};

class Professor : public Staff
{
    private:
        Course* _currentCourse;

    public:
        Professor(std::string p_name);
        ~Professor();
        void assignCourse(Course* p_course);
        void doClass();
        void closeCourse();
};

#endif