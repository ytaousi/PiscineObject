#include "form.hpp"
#include "personnel.hpp"
#include <iostream>

int main()
{
    // Personnel 
    //HeadMaster *headMaster = HeadMaster::getInstance();
    Secretary *secretary1 = Secretary::getInstance();
    Secretary *secretary2 = Secretary::getInstance();
    // Forms
    // CourseFinishedForm *courseFinishedForm = CourseFinishedForm::getInstance();
    // NeedMoreClassRoomForm *needMoreClassRoomForm = NeedMoreClassRoomForm::getInstance();
    // NeedCourseCreationForm *needCourseCreationForm = NeedCourseCreationForm::getInstance();
    // SubscriptionToCourseForm *subscriptionToCourseForm = SubscriptionToCourseForm::getInstance();

    secretary1->createForm(Person::subscriptioncourse);
    secretary2->createForm(Person::needmoreclassroom);

    return (0);
}