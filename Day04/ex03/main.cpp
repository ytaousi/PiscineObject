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

    Professor *professor1 = new Professor();
    Professor *professor2 = new Professor();
    Student *student1 = new Student();
    Student *student2 = new Student();

    Headmaster *headMaster = new Headmaster();
    Secretary *secretary1 = new Secretary();
    Secretary *secretary2 = new Secretary();

    headMaster->setName("yassir");
    
    secretary1->setName("secretary-1");
    secretary2->setName("secretary-2");
    
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
    
    // Component1 *c1 = mediator->getComponent1();
    // Component2 *c2 = mediator->getComponent2();

    // c1->ExecFormCouseSubscriptionTemp();
    // c2->ExecFormGraduationTemp();

    // Start Process
    // Attend Class : send notification to all professors
    //headMaster->getMediator()->Notify(headMaster->getName(), "AttenClass");
    // if professor has no class to teach and/or student has no class to attend
    Room *mathRoom = new Course();
    Room *programmingRoom = new Course();
    Room *historyRoom = new Course();
    Room *secOpsRoom = new Course();
        // Create Course Object and affect room to the professor

    mathRoom->setRoomName("Math");
    programmingRoom->setRoomName("Programming");
    historyRoom->setRoomName("History");
    secOpsRoom->setRoomName("Security Operationnals");
    
        // Create Course Object and affect room to the student
    std::cout << "---------------------------------" << std::endl;

    
// Professor Has Class Afected and Student has Course Afected
    // Graduation Process
    
    // All Professor's has Class afected
    //mediator->notify(headMaster->getName(), "AttendClass");
    //mediator->notify(professor1->getName(), "TeachCourse");
    // // Student Attended Enough Classes to Graduate
    // mediator->notify(professor1->getName(), "GraduationRequest");
    // mediator->notify(headmaster->getName(), "FormCourseRequest");
    // mediator->notify(headmaster->getName(), "FillFormCourseRequest");
    // mediator->notify(professor1->getName(), "SignFormCourseRequest");
 // Student Need More Classes to Graduate
    // mediator->notify(student1->getName(), "FollowClass");
    
// Professor has no Class afected
    // Professor Course Subscription Process

    // Professor has no Class afected
    // mediator->notify(professor1->getName(), "CourseSubscriptionRequest");
    // mediator->notify(headmaster->getName(), "FormCourseRequest");
    // mediator->notify(headmaster->getName(), "FillFormCourseRequest");
    // mediator->notify(professor1->getName(), "SignFormCourseRequest");
    // mediator->notify(professor1->getName(), "TeachCourse");

// Student has no Course afected
    // Student Course Subscription Process
    
    // Student has no Course afected


    delete professor1;
    delete professor2;
    delete student1;
    delete student2;
    delete secretary1;
    delete secretary2;
    delete headMaster;
    return (0);
}