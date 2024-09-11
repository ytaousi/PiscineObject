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

    std::cout << "---------------------------------" << std::endl;

    Professor *professor1 = new Professor();
    Professor *professor2 = new Professor();
    Student *student1 = new Student();
    Student *student2 = new Student();
    Student *student3 = new Student();
    Student *student4 = new Student();

    Headmaster *headMaster = new Headmaster();
    Secretary *secretary1 = new Secretary();
    Secretary *secretary2 = new Secretary();


    Room *programmingRoom = new Room();
    Room *healthcareRoom = new Room();
    Room *officeRoom = new Room();

    programmingRoom->setRoomName("Programming Room");
    healthcareRoom->setRoomName("Healthcare Room");
    officeRoom->setRoomName("Office Room");

    headMaster->setName("yassir");
    
    secretary1->setName("secretary-1");
    secretary2->setName("secretary-2");
    
    professor1->setName("prfss");
    professor2->setName("prfss2");
    
    student1->setName("ll");
    student1->assignRoom(programmingRoom);
    student2->setName("nn");
    student2->assignRoom(programmingRoom);
    student3->setName("Lisa");
    student3->assignRoom(healthcareRoom);
    student4->setName("L");
    student4->assignRoom(healthcareRoom);
    
    // headmaster - professor - student - secretary
    ConcreteMediator *mediator = headMaster->getMediator();
    mediator->addForm(courseFinishedForm);
    mediator->addForm(needMoreClassRoomForm);
    mediator->addForm(needCourseCreationForm);
    mediator->addForm(subscriptionToCourseForm);
    
    TweakedMediator *mediatorTweakedComponent = mediator->getTweakedMediator();



    mediatorTweakedComponent->setHeadmaster(headMaster);
    mediatorTweakedComponent->setProfessor(professor1);
    mediatorTweakedComponent->setStudent(student1);
    mediatorTweakedComponent->setSecretary(secretary1);



    professor1->assignRoom(programmingRoom);
    professor1->setCurrentRoom(programmingRoom);
    professor2->assignRoom(healthcareRoom);
    professor2->setCurrentRoom(healthcareRoom);
    
    //mediator->Notify(headMaster, "AttendClass");
    
    mediatorTweakedComponent->attendClass(headMaster, professor1);
    mediatorTweakedComponent->attendClass(headMaster, professor2);
    
    
    professor1->doClass(programmingRoom);
    student1->setCurrentRoom(programmingRoom);
    student2->setCurrentRoom(programmingRoom);

    
    professor2->doClass(healthcareRoom);
    student3->setCurrentRoom(healthcareRoom);
    student4->setCurrentRoom(healthcareRoom);
    
    
    //mediator->Notify(professor1, "TeachCourse");
    //mediator->Notify(professor2, "TeachCourse");
    
    mediatorTweakedComponent->teachCourse(professor1, student1);
    mediatorTweakedComponent->teachCourse(professor1, student2);
    
    mediatorTweakedComponent->teachCourse(professor2, student3);
    mediatorTweakedComponent->teachCourse(professor2, student4);

    student1->attendClass(programmingRoom);
    student2->attendClass(programmingRoom);
    student3->attendClass(healthcareRoom);
    student4->attendClass(healthcareRoom);

    //mediator->Notify(headMaster, "GraduationRequest");
    professor1->studentNeedToGraduateForm(student1);
    professor1->studentNeedToGraduateForm(student2);

    professor2->studentNeedToGraduateForm(student3);
    professor2->studentNeedToGraduateForm(student4);
    
    mediatorTweakedComponent->graduationRequest(professor1, headMaster);
    mediatorTweakedComponent->graduationRequest(professor1, headMaster);
    mediatorTweakedComponent->graduationRequest(professor2, headMaster);
    mediatorTweakedComponent->graduationRequest(professor2, headMaster);
    //mediator->Notify(headMaster, "FormGraduationRequest");
    mediatorTweakedComponent->graduationFormRequest(headMaster, secretary1);
    mediatorTweakedComponent->graduationFormRequest(headMaster, secretary1);
    mediatorTweakedComponent->graduationFormRequest(headMaster, secretary2);
    mediatorTweakedComponent->graduationFormRequest(headMaster, secretary2);
    //mediator->Notify(headMaster, "FillFormGraduationRequest");
    mediatorTweakedComponent->graduationFillFormRequest(headMaster, professor1);
    mediatorTweakedComponent->graduationFillFormRequest(headMaster, professor1);
    mediatorTweakedComponent->graduationFillFormRequest(headMaster, professor2);
    mediatorTweakedComponent->graduationFillFormRequest(headMaster, professor2);
    //mediator->Notify(headMaster, "SignFormGraduationRequest");
    mediatorTweakedComponent->graduationSignFormRequest(professor1, headMaster);
    mediatorTweakedComponent->graduationSignFormRequest(professor1, headMaster);
    mediatorTweakedComponent->graduationSignFormRequest(professor2, headMaster);
    mediatorTweakedComponent->graduationSignFormRequest(professor2, headMaster);

    



    std::cout << "---------------------------------" << std::endl;
    delete professor1;
    delete professor2;
    delete student1;
    delete student2;
    delete secretary1;
    delete secretary2;
    delete headMaster;
    return (0);
}