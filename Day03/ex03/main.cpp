#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"
#include "employeeManagement.hpp"

int main()
{
    EmployeeManager         *employeeManager = new EmployeeManager();
    Apprentice              *apprentice = new Apprentice();
    TempWorker              *tempWorker = new TempWorker();
    ContractEmployee        *contractEmployee = new ContractEmployee();
    std::vector<Employee*>  employees;


    employeeManager->addEmployee(apprentice);
    employeeManager->addEmployee(tempWorker);
    employeeManager->addEmployee(contractEmployee);

    employees = employeeManager->getEmployees();

    employees[0]->setEmployeeName("DevOps Student");
    employees[1]->setEmployeeName("Plombier");
    employees[2]->setEmployeeName("Electricien");

    employees[0]->setHourlyValue(10);
    employees[1]->setHourlyValue(8);
    employees[2]->setHourlyValue(25);
    
    for (std::vector<Employee*>::iterator it = employees.begin(); it != employees.end(); ++it)
    {
        std::cout << "Employee Name : " << (*it)->getEmployeeName() << " Employee Hourly Value " << (*it)->getHourlyValue() << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;

    employeeManager->calculatePayroll();
    

    
    return (0);
}