#ifndef FORM_HPP
#define FORM_HPP

#include "utils.hpp"

class Form
{
    private:
        t_FormType _formType;

    public:
        Form(t_FormType p_formType);
        virtual ~Form();
        virtual void execute() = 0;
};

class CourseFinishedForm : public Form
{
    private:

    public:
        CourseFinishedForm();
        ~CourseFinishedForm();
        void execute();
};

class NeedMoreClassRoomForm : public Form
{
    private:

    public:
        NeedMoreClassRoomForm();
        ~NeedMoreClassRoomForm();
        void execute();
};

class NeedCourseCreationForm : public Form
{
    private:

    public:
        NeedCourseCreationForm();
        ~NeedCourseCreationForm();
        void execute();
};

class SubscriptionToCourseForm : public Form
{
    private:

    public:
        SubscriptionToCourseForm();
        ~SubscriptionToCourseForm();
        void execute();
};

#endif