#ifndef STAFFLIST_HPP
#define STAFFLIST_HPP

#include "singetons.hpp"

class StaffList : public Person
{
    private:
        std::vector<Person *> _staffList;
    public:
        StaffList();
        ~StaffList();
        std::vector<Person *> getStaffList() {
            return this->_staffList;
        };
        Person& getStaff(Person *staff) {
            for (std::vector<Person *>::iterator it = _staffList.begin(); it != _staffList.end(); it++) {
                if (*it == staff) {
                    return **it;
                }
            }
            std::cout << " Staff Not Found " << std::endl;
        }
        void addStaff(Person *staff) {
            _staffList.push_back(staff);
        };
        void removeStaff(Person *staff) {
            for (std::vector<Person *>::iterator it = _staffList.begin(); it != _staffList.end(); it++) {
                if (*it == staff) {
                    _staffList.erase(it);
                    std::cout << " Staff Removed " << std::endl;
                    return;
                }
            }
            std::cout << " Staff Not Found " << std::endl;
        };
};

#endif