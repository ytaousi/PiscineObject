#include "forms.hpp"
#include "personnel.hpp"
#include <iostream>

int main()
{
    //Secretary *s1 = new Secretary();
    CourseFinishedForm *Form1 = new CourseFinishedForm();
    NeedMoreClassRoomForm *Form2 = new NeedMoreClassRoomForm();
    NeedCourseCreationForm *Form3 = new NeedCourseCreationForm();
    SubscriptionToCourseForm *Form4 = new SubscriptionToCourseForm();
    std::vector<Form *> _list;

    _list.push_back(Form1);
    _list.push_back(Form2);
    _list.push_back(Form3);
    _list.push_back(Form4);

    Secretary *s2 = new Secretary();


    std::cout << "----------------------" << std::endl;
    s2->createForm(CourseFinished);
    s2->createForm(NeedMoreClassRoom);
    s2->createForm(NeedCourseCreation);
    s2->createForm(SubscriptionToCourse);
    std::cout << "----------------------" << std::endl;
    //std::vector<Form *> _formList = s2->getList();

    // for (size_t i = 0; i < _formList.size(); i++)
    // {
    //     _formList[i]->execute();
    // }
    // s2->createForm(NeedMoreClassRoom);
    // s2->createForm(NeedCourseCreation);
    // s2->createForm(SubscriptionToCourse);
    // Headmaster *h1 = new Headmaster();


    // std::vector<Form *> _formList = _list;
    // for (size_t i = 0; i < _formList.size(); i++)
    // {
    //     _formList[i]->setIsFilled(1);
    //     h1->signForm(_formList[i]);
    // }
    // std::cout << "----------------------" << std::endl;
    // for (size_t i = 0; i < _formList.size(); i++)
    // {
    //     h1->executeForm(_formList[i]);
    // }
    // std::cout << "----------------------" << std::endl;
    // for(size_t i = 0; i < _formList.size(); i++)
    // {
    //     _formList[i]->setIsFilled(1);
    // }
    // for (size_t i = 0; i < _formList.size(); i++)
    // {
    //     _formList[i]->execute();
    // }
    // std::cout << "----------------------" << std::endl;
    // for(size_t i = 0; i < _formList.size(); i++)
    // {
    //     _formList[i]->setIsSigned(1);
    // }
    // for(size_t i = 0; i < _formList.size(); i++)
    // {
    //     _formList[i]->execute();
    // }
    // std::cout << "----------------------" << std::endl;
    return (0);
}