#include "personnel.hpp"
#include "person.hpp"
#include "room.hpp"


int main()
{
    CourseFinishedForm *courseFinishedForm = new CourseFinishedForm();
    NeedMoreClassRoomForm *needMoreClassRoomForm = new NeedMoreClassRoomForm();
    NeedCourseCreationForm *needCourseCreationForm = new NeedCourseCreationForm();
    SubscriptionToCourseForm *subscriptionToCourseForm = new SubscriptionToCourseForm();

    std::vector<Form *> formList;

    formList.push_back(courseFinishedForm);
    formList.push_back(needMoreClassRoomForm);
    formList.push_back(needCourseCreationForm);
    formList.push_back(subscriptionToCourseForm);



    for(size_t i = 0; i < formList.size(); i++)
    {
        //formList[i]->setIsFilled(1);
        formList[i]->execute();
    }

    std::cout << "--------------------------------" << std::endl;

    // Professor *professor1 = new Professor();
    // Professor *professor2 = new Professor();
    // Student *student1 = new Student();
    // Student *student2 = new Student();

    std::cout << "---------------------------------" << std::endl;

    Person<Professor> *professor1 = new Person<Professor>();
    Person<Professor> *professor2 = new Person<Professor>();
    Person<Student> *student1 = new Person<Student>();
    Person<Student> *student2 = new Person<Student>();

    Headmaster *headMaster = new Headmaster();
    
    professor1->setName("prfss");
    professor2->setName("prfss2");
    student1->setName("ll");
    student2->setName("nn");
    
    // headmaster - professor - student - secretary
    ConcreteMediator *mediator = headMaster->getMediator();
    mediator->addForm(courseFinishedForm);
    mediator->addForm(needMoreClassRoomForm);
    mediator->addForm(needCourseCreationForm);
    mediator->addForm(subscriptionToCourseForm);
    
    Component1 *c1 = mediator->getComponent1();
    Component2 *c2 = mediator->getComponent2();

    c1->CheckCheck1();
    c2->CheckCheck2();
    // Graduation Process
    // All Professor's has Class afected
    // mediator->notify(headmaster, "AttendClass");
    // mediator->notify(professor1, "TeachCourse");
    // // Student Attended Enough Classes to Graduate
    // mediator->notify(professor1, "GraduationRequest");
    // mediator->notify(headmaster, "FormCourseRequest");
    // mediator->notify(headmaster, "FillFormCourseRequest");
    // mediator->notify(professor1, "SignFormCourseRequest");
    // // Student Need More Classes to Graduate
    // mediator->notify(student1, "FollowClass");

    // Course Subscription Process
    // Professor has no Class afected
    // mediator->notify(professor1, "CourseSubscriptionRequest");
    // mediator->notify(headmaster, "FormCourseRequest");
    // mediator->notify(headmaster, "FillFormCourseRequest");
    // mediator->notify(professor1, "SignFormCourseRequest");
    // mediator->notify(professor1, "TeachCourse");

    delete professor1;
    delete professor2;
    delete student1;
    delete student2;
    return (0);
}