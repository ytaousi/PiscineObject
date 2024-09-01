#ifndef SINGETONS_HPP
#define SINGETONS_HPP

#include <vector>
#include <iostream>

enum Profession
{
	headmaster,
	secretary
};

class Form
{
    protected:
        Form() {};
        Form(const Form&) = delete;
        Form& operator=(const Form&) = delete;
        static Form* instance;

    public:
        enum FormType
        {
            coursefinished,
            needmoreclassroom,
            needcoursecreation,
            subscriptioncourse
        };

        static Form* getInstance() {
            if (instance == NULL) {
                instance = new Form(); // Create the instance only once
            }
            return instance;
        }

        virtual ~Form() {};
};

class Person
{
    protected:
        Person() {};
        Person(const Person&) = delete;
        Person& operator=(const Person&) = delete;
        static Person* instance;

    public:
        enum FormType
        {
            coursefinished,
            needmoreclassroom,
            needcoursecreation,
            subscriptioncourse
        };

        static Person* getInstance() {
            if (instance == NULL) {
                instance = new Person(); // Create the instance only once
            }
            return instance;
        }

        virtual ~Person() {};
};

#endif