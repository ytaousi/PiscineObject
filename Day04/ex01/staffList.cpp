#include "staffList.hpp"

StaffList* StaffList::_instance = NULL;

StaffList* StaffList::getInstance()
{
    if (_instance == NULL)
    {
        _instance = new StaffList();
    }
    return _instance;
}

std::vector<Person *> StaffList::getStaffList()
{
    return this->_staffList;
}

Person* StaffList::getStaff(Person *staff)
{
    for (size_t i = 0; i < _staffList.size(); i++)
    {
        if (_staffList[i] == staff)
        {
            return _staffList[i];
        }
    }
    std::cout << " Staff Not Found " << std::endl;
    return NULL;
}

int StaffList::addStaff(Person *staff)
{
    for (std::vector<Person *>::iterator it = _staffList.begin(); it != _staffList.end(); it++)
    {
        if (*it == staff)
        {
            std::cout << " Staff Already Exists " << std::endl;
            return 1;
        }
    }
    this->_staffList.push_back(staff);
    return 0;
}

int StaffList::removeStaff(Person *staff)
{
    for (std::vector<Person *>::iterator it = _staffList.begin(); it != _staffList.end(); it++)
    {
        if (*it == staff)
        {
            _staffList.erase(it);
            return 0;
        }
    }
    std::cout << " Staff Not Found " << std::endl;
    return 1;
}