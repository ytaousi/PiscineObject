#ifndef STAFFLIST_HPP
#define STAFFLIST_HPP

#include "person.hpp"

class StaffList
{
    private:
        std::vector<Person *> _staffList;
    protected:
        StaffList() {};
        static StaffList* _instance;
    public:
        static StaffList* getInstance();
        virtual ~StaffList(){ this->_staffList.clear(); };
        std::vector<Person *> getStaffList();
        Person* getStaff(Person *staff);
        int addStaff(Person *staff);
        int removeStaff(Person *staff);
};

#endif