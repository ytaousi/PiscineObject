#ifndef FORM_HPP
#define FORM_HPP

#include "singetons.hpp"

class CourseFinishedForm : public Form
{
    private:
    public:
        static CourseFinishedForm* getInstance();
        ~CourseFinishedForm();
        void execute();
        void fillForm();
};

class NeedMoreClassRoomForm : public Form
{
    private:
    public:
        static NeedMoreClassRoomForm* getInstance();
        ~NeedMoreClassRoomForm();
        void execute();
        void fillForm();
};

class NeedCourseCreationForm : public Form
{
    private:
    public:
        static NeedCourseCreationForm* getInstance();
        ~NeedCourseCreationForm();
        void execute();
        void fillForm();
};

class SubscriptionToCourseForm : public Form
{
    private:
    public:
        static SubscriptionToCourseForm* getInstance();
        ~SubscriptionToCourseForm();
        void execute();
        void fillForm();
};

#endif