#include "hourlyEmployee.hpp"

// The Apprentice, at last, must register the hour it will NOT work, just as the
// ContractEmployee, but it must also log every hour where it will go to school. The
// Apprentice need a way to indicate how many hours of school he will do before going
// back to work. Those hours passed at school will be payed half the hourly value

Apprentice::Apprentice()
{
    this->setHourlyValue(10);
    this->setEmployeeName("");

}

Apprentice::~Apprentice()
{
    ;
}

int Apprentice::executeWorkday(int workHours)
{
    std::cout << "Apprentice : " << this->getEmployeeName() << " wil be working for " << workHours << " Hours Today" << std::endl;
    std::cout << "Apprentice : " << this->getEmployeeName() << " went to school " << 7 - workHours << " Hours Today" << std::endl;
    this->mobiliseWorkingHours(workHours, 7 - workHours, 7 - workHours);
    return workHours;
}

void Apprentice::mobiliseWorkingHours(int workHours, int nonWorkingHours, int schoolHours)
{
    (void)nonWorkingHours;
    this->setHoursSpentInCompagny(workHours);
    this->setHoursSpentInSchool(schoolHours);
}
