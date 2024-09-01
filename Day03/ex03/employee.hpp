#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string>

class Employee
{
    private:
        int         hourlyValue;
        std::string name;
        int         hoursSpentInSchool;
        int         hoursSpentInCompany;
        int         hoursSpentOutOfCompany;
    public:
        Employee();
        Employee(std::string name, int hourlyValue);
        ~Employee();
        std::string getEmployeeName();
        void setEmployeeName(std::string name);
        virtual int executeWorkday(int workHours) = 0;
        void setHourlyValue(int hourlyValue);
        int getHourlyValue();
        void setHoursSpentInCompagny(int hours);
        void setHoursSpentOutOfCompagny(int hours);
        void setHoursSpentInSchool(int hours);
        int getHoursSpentInCompagny();
        int getHoursSpentOutOfCompagny();
        int getHoursSpentInSchool();
};
#endif