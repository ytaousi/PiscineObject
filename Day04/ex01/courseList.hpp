#ifndef COURSELIST_HPP
#define COURSELIST_HPP

#include "person.hpp"

class CourseList
{
    private:
        std::vector<Room *> _courseList;
    public:
        CourseList();
        ~CourseList();
        std::vector<Room *> getCourseList() { return _courseList; }
        Room& getCourse(Module p_module);
        void addCourse(Room *p_course);
        void removeCourse(Room *p_course);
};

#endif