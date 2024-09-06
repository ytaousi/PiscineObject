#include "singleton.hpp"

int main()
{
    std::cout << "-------------------" << std::endl;
    RoomList *roomList = RoomList::getInstance();
    CourseList *courseList = CourseList::getInstance();
    StaffList *staffList = StaffList::getInstance();
    StudentList *studentList = StudentList::getInstance();

    Room *room1 = new Room(LIBRARY);
    Room *room2 = new Room(PROGRAMMING);
    Room *room3 = new Room(PLAYGROUND);

    Room *course1 = new Room(HEALTH_CARE);
    Room *course2 = new Room(PROGRAMMING);
    Room *course3 = new Room(HEALTH_CARE);

    Person *student1 = new Person("John", STUDENT);
    Person *student2 = new Person("yassir", STUDENT);
    Person *student3 = new Person("yolyo", STUDENT);

    Person *staff1 = new Person("John", STAFF);
    Person *staff2 = new Person("Yori", STAFF);
    Person *staff3 = new Person("Random",STAFF);

    roomList->addObject(room1);
    roomList->addObject(room2);
    roomList->addObject(room3);

    courseList->addObject(course1);
    courseList->addObject(course2);
    courseList->addObject(course3);

    staffList->addObject(staff1);
    staffList->addObject(staff2);
    staffList->addObject(staff3);

    studentList->addObject(student1);
    studentList->addObject(student2);
    studentList->addObject(student3);



    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    std::vector<Room *> rooms = roomList->getList();
    std::vector<Room *> courses = courseList->getList();
    std::vector<Person *> staffs = staffList->getList();
    std::vector<Person *> students = studentList->getList();


    std::cout << "---------Available Rooms-----------" << std::endl;
    for (size_t i = 0 ; i < rooms.size(); i++) {
        std::cout << "RoomID : " << rooms[i]->getID() << std::endl;
        std::cout << "RoomType : " << rooms[i]->getType() << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    std::cout << "----------Courses Held---------" << std::endl;
    for (size_t i = 0 ; i < courses.size(); i++) {
        std::cout << "RoomID : " << courses[i]->getID() << std::endl;
        std::cout << "CourseType : " << courses[i]->getType() << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    for (size_t i = 0 ; i < staffs.size(); i++) {
        std::cout << "Occupant Name : " << staffs[i]->getName() << std::endl;
        std::cout << staffs[i]->getProfession() << std::endl;
    }
    for (size_t i = 0; i < students.size(); i++)
    {
        std::cout << "Occupant Name : " << students[i]->getName() << std::endl;
        std::cout << students[i]->getProfession() << std::endl;
    }

    


    delete course1;
    delete course2;
    delete course3;
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