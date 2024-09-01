#ifndef HOURLYEMPLOYEE_HPP
#define HOURLYEMPLOYEE_HPP

#include "employee.hpp"

class Apprentice : public Employee
{
    public:
        Apprentice();
        ~Apprentice();
        int executeWorkday(int workHours);
        void mobiliseWorkingHours(int workhours, int nonWorkingHours, int schoolhours); 
};

#endif