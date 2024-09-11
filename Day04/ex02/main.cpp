#include "forms.hpp"
#include "personnel.hpp"
#include <iostream>

int main()
{

    Secretary *s2 = new Secretary();
    std::vector<Form*> _formList;
    Headmaster *h1 = new Headmaster();
    std::cout << "----------------------" << std::endl;
    s2->createForm(CourseFinished);
    s2->createForm(NeedMoreClassRoom);
    s2->createForm(NeedCourseCreation);
    s2->createForm(SubscriptionToCourse);
    std::cout << "----------------------" << std::endl;
    _formList = s2->getList();
    for (size_t i = 0; i < _formList.size(); i++)
    {
        h1->executeForm(_formList[i]);
    }
    std::cout << "---------------------" << std::endl;
    for (size_t i = 0; i < _formList.size(); i++)
    {
        s2->fillForm(_formList[i]); //
        _formList[i]->setIsFilled(1);
    }
    std::cout << "---------------------" << std::endl;
    for (size_t i = 0; i < _formList.size(); i++)
    {
        h1->signForm(_formList[i]);
    }
    std::cout << "---------------------" << std::endl;
    for (size_t i = 0; i < _formList.size(); i++)
    {
        h1->executeForm(_formList[i]);
    }
    std::cout << "---------------------" << std::endl;
    return (0);
}