#include "employee.hpp"


Employee::Employee()
{
    this->setHourlyValue(0);
    this->setEmployeeName("");
}

Employee::Employee(std::string name, int hourlyValue)
{
    this->setHourlyValue(hourlyValue);
    this->setEmployeeName(name);
}

Employee::~Employee()
{
    ;
}

int Employee::executeWorkday(int workHours)
{
    return workHours;
}

void Employee::setHourlyValue(int hourlyValue)
{
    this->hourlyValue = hourlyValue;
}

int Employee::getHourlyValue()
{
    return this->hourlyValue;
}

std::string Employee::getEmployeeName()
{
    return this->name;
}

void Employee::setEmployeeName(std::string name)
{
    this->name = name;
}

void Employee::setHoursSpentInCompagny(int hours)
{
    this->hoursSpentInCompany += hours;
}

void Employee::setHoursSpentOutOfCompagny(int hours)
{
    this->hoursSpentOutOfCompany += hours;
}

void Employee::setHoursSpentInSchool(int hours)
{
    this->hoursSpentInSchool += hours;
}

int Employee::getHoursSpentInCompagny()
{
    return this->hoursSpentInCompany;
}

int Employee::getHoursSpentOutOfCompagny()
{
    return this->hoursSpentOutOfCompany;
}

int Employee::getHoursSpentInSchool()
{
    return this->hoursSpentInSchool;
}