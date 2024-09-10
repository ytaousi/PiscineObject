#include "personnel.hpp"
#include "person.hpp"
#include "room.hpp"


int main()
{
    CourseFinishedForm *courseFinishedForm = new CourseFinishedForm();
    NeedMoreClassRoomForm *needMoreClassRoomForm = new NeedMoreClassRoomForm();
    SubscriptionToCourseForm *subscriptionToCourseForm = new SubscriptionToCourseForm();

    std::vector<Form *> formList;

    formList.push_back(courseFinishedForm);
    formList.push_back(needMoreClassRoomForm);
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

    Room<Course> *room1 = new Room<Course>();
    Room<Course> *room2 = new Room<Course>();

    room1->setRoomName("Room1");
    room2->setRoomName("Room2");

    std::cout << "Room1 Name : " << room1->getRoomName() << std::endl;
    std::cout << "Room2 Name : " << room2->getRoomName() << std::endl;

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
    
    //ConcreteMediator *mediator = new ConcreteMediator(new Component1(), new Component2());


    delete professor1;
    delete professor2;
    delete student1;
    delete student2;
    return (0);
}