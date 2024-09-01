#ifndef PERSONNEL_HPP
#define PERSONNEL_HPP

#include "singetons.hpp"

class HeadMaster : public Person
{
    private:
        HeadMaster() {};
        HeadMaster(const HeadMaster&) = delete;
        HeadMaster& operator=(const HeadMaster&) = delete;

    public:
        static HeadMaster* getInstance() {
            static HeadMaster instance;
            return static_cast<HeadMaster*>(Person::getInstance());
        }

        void signForm(FormType formType);
        ~HeadMaster();
};

class Secretary : public Person
{
    private:
        Secretary() {};
        Secretary(const Secretary&) = delete;
        Secretary& operator=(const Secretary&) = delete;

    public:
        static Secretary* getInstance() {
            static Secretary instance;
            return static_cast<Secretary*>(Person::getInstance());
        }

        void createForm(FormType formType);
        ~Secretary();
};

#endif // PERSONNEL_HPP
