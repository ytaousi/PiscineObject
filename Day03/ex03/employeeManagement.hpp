#ifndef EMPLOYEEMANAGEMENT_HPP
#define EMPLOYEEMANAGEMENT_HPP

#include "employee.hpp"
#include <vector>

class EmployeeManager
{
    private:
        std::vector<Employee*> employees;
    public:
        EmployeeManager();
        ~EmployeeManager();
        void addEmployee(Employee* employee);
        void removeEmployee(Employee* employee);
        void executeWorkday();
        void calculatePayroll();
        std::vector<Employee*> getEmployees();
};

#endif