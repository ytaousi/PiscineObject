#include "salariedEmployee.hpp"
#include <iostream>

TempWorker::TempWorker()
{
    this->setHourlyValue(10);
    this->setEmployeeName("");
}

TempWorker::~TempWorker()
{
    ;
}

int TempWorker::executeWorkday(int workHours)
{
    int workingHours = workHours;
    std::cout << "TempWorker : " << this->getEmployeeName() << " wil be working for " << workingHours << " Hours Today" << std::endl;
    this->mobiliseWorkingHours(workingHours);
    return workingHours;
}

void TempWorker::mobiliseWorkingHours(int hours)
{
   this->setHoursSpentInCompagny(hours);
}

ContractEmployee::ContractEmployee()
{
    this->setHourlyValue(10);
    this->setEmployeeName("");
   
}

ContractEmployee::~ContractEmployee()
{
    ;
}

int ContractEmployee::executeWorkday(int workHours)
{
    int nonWorkingHours = 7 - workHours;
    std::cout << "ContractEmployee : " << this->getEmployeeName() << " has not been working for " << nonWorkingHours << " Hours Today" << std::endl;
    this->mobiliseNonWorkingHours(nonWorkingHours);
    return nonWorkingHours;
}

void ContractEmployee::mobiliseNonWorkingHours(int nonWorkingHours)
{
    this->setHoursSpentOutOfCompagny(nonWorkingHours);
    this->setHoursSpentInCompagny(7 - nonWorkingHours);
}