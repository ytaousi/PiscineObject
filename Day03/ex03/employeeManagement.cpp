#include "employeeManagement.hpp"
#include "salariedEmployee.hpp"
#include "hourlyEmployee.hpp"


EmployeeManager::EmployeeManager()
{
    ;
}

EmployeeManager::~EmployeeManager()
{
    ;
}

void EmployeeManager::addEmployee(Employee* employee)
{
    for (std::vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it)
    {
        if (*it == employee)
        {
            std::cout << "Employee already exists " << std::endl;
            return;
        }
    }
    employees.push_back(employee);
}

void EmployeeManager::removeEmployee(Employee* employee)
{
    for (std::vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it)
    {
        if (*it == employee)
        {
            employees.erase(it);
            return;
        }
    }
    std::cout << "Employee not found " << std::endl;
}

void EmployeeManager::executeWorkday()
{
    for (std::vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it)
    {
        std::cout << "[Employee: " << (*it)->getEmployeeName() << " Starting His Working Day ]" << std::endl;
        std::cout << "\n";
        std::cout << "------------------------" << std::endl;
        (*it)->executeWorkday(6); // number of hours to work today
        std::cout << "\n";
    }
}

void EmployeeManager::calculatePayroll()
{   
    float apprenticePayout = 0;
    float tempWorkerPayout = 0;
    float contractEmployeePayout = 0;
    float internsHoursRating = 0.5;
    std::vector<Employee *> employees;

    for (int i = 0; i < 2; i++) // days of work
    {
        this->executeWorkday();
    }

    employees = this->getEmployees();

    for (std::vector<Employee *>::iterator it = employees.begin(); it != employees.end(); ++it)
    {
        if (dynamic_cast<Apprentice*>(*it))
        {
            apprenticePayout = (*it)->getHourlyValue() * (*it)->getHoursSpentInCompagny();
            apprenticePayout += ((*it)->getHourlyValue() * internsHoursRating) * (*it)->getHoursSpentInSchool();
        }
        else if (dynamic_cast<TempWorker*>(*it))
        {
            tempWorkerPayout = (*it)->getHourlyValue() * (*it)->getHoursSpentInCompagny();
        }
        else if (dynamic_cast<ContractEmployee*>(*it))
        {
            contractEmployeePayout += (*it)->getHourlyValue() * (*it)->getHoursSpentInCompagny();
        }
    }

    
    
    std::cout << "-----PAYOUTS FOR THE LAST Working PERIOD-----" << std::endl;
    std::cout << "Payroll For The Apprentice Employee is : " << apprenticePayout << std::endl;
    std::cout << "Payroll For The TempWorker Employee is : " << tempWorkerPayout << std::endl;
    std::cout << "Payroll For The ContractEmployee Employee is : " << contractEmployeePayout << std::endl;
}

std::vector<Employee*> EmployeeManager::getEmployees()
{
    return employees;   
}