#ifndef SALARIEDEMPLOYEE_HPP
#define SALARIEDEMPLOYEE_HPP

#include "employee.hpp"

// The TempWorker is a class who must register every work hour it will do. It is also
// need a way to mobilise it over a certain period of time, in hour.

class TempWorker : public Employee
{
    public:
        TempWorker();
        ~TempWorker();
        int executeWorkday(int workHours);
        void mobiliseWorkingHours(int hours);
};

// The ContractEmployee, on the other hand, must register the hour it will NOT do
// (Vacantion, sickness, any reason).

class ContractEmployee : public Employee
{
    public:
        ContractEmployee();
        ~ContractEmployee();
        int executeWorkday(int workHours);
        void mobiliseNonWorkingHours(int hours);
};

#endif