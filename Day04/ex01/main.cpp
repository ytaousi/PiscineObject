#include "person.hpp"
#include "room.hpp"

#include "studentList.hpp"
#include "staffList.hpp"
#include "roomList.hpp"

int main()
{
    Person *student1 = new Person("Jhon Doe", STUDENT);
    Person *student2 = new Person("Solomon Kane", STUDENT);;
    Person *student3 = new Person("BouWdina", STUDENT);
    Person *staff1 = new Person("Yorick", STAFF);
    Person *staff2 = new Person("Elie", STAFF);
    Person *staff3 = new Person("Nirina", STAFF);
    //
    Room *room1 = new Room(LIBRARY);
    Room *room2 = new Room(PROGRAMMING);
    Room *room3 = new Room(PLAYGROUND);
    //
    StudentList *studentList = StudentList::getInstance();
    StaffList *staffList = StaffList::getInstance();
    RoomList *roomList = RoomList::getInstance();



    roomList->addRoom(room1);
    roomList->addRoom(room2);
    roomList->addRoom(room3);

    std::vector<Room *> rooms = roomList->getRoomList();

    for (size_t i = 0; i < rooms.size(); i++) {
        std::cout << "RoomID : " << rooms[i]->getRoomID() << std::endl;
        std::cout << "RoomType : " << rooms[i]->getRoomType() << std::endl;
    }

    roomList->removeRoom(room1);

    rooms = roomList->getRoomList();

    for (size_t i = 0; i < rooms.size(); i++) {
        std::cout << "RoomID : " << rooms[i]->getRoomID() << std::endl;
        std::cout << "RoomType : " << rooms[i]->getRoomType() << std::endl;
    }

    std::cout << "-------------------" << std::endl;


    student1->setName("John Doe");
    student1->setProfession(STUDENT);
    student2->setName("Solomon Kane");
    student2->setProfession(STUDENT);
    student3->setName("BouWdina");
    student3->setProfession(STUDENT);
    
    studentList->addStudent(student1);
    studentList->addStudent(student2);
    studentList->addStudent(student3);

    staff1->setName("Yorick");
    staff1->setProfession(STAFF);
    staff2->setName("Elie");
    staff2->setProfession(STAFF);
    staff3->setName("nnNirina");
    staff3->setProfession(STAFF);

    staffList->addStaff(staff1);
    staffList->addStaff(staff2);
    staffList->addStaff(staff3);


    std::vector<Person *> students = studentList->getStudentList();
    std::vector<Person *> staffs = staffList->getStaffList();

    
    for (size_t i = 0; i < students.size(); i++) {
        std::cout << students[i]->getName() << std::endl;
    }

    

    for (std::vector<Person *>::iterator it = staffs.begin(); it != staffs.end(); it++) {
        std::cout << (*it)->getName() << std::endl;
    }

    std::cout << "-------------------" << std::endl;
    Person *student = studentList->getStudent(student1);

    std::cout << student->getName() << std::endl;
    student->setName("Yassir");

    
    delete student1;
    delete student2;
    delete student3;
    delete staff1;
    delete staff2;
    delete staff3;
    delete room1;
    delete room2;
    delete room3;
    return (0);
}