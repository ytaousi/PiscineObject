#include "form.hpp"

Form::Form(t_FormType p_formType)
{
    this->_formType = p_formType;
}

Form::~Form()
{
    std::cout << " Form Destructor " << std::endl;
}

CourseFinishedForm::CourseFinishedForm() : Form(CourseFinished)
{
    std::cout << " CourseFinishedForm Constructor " << std::endl;
}

CourseFinishedForm::~CourseFinishedForm()
{
    std::cout << " CourseFinishedForm Destructor " << std::endl;
}

void CourseFinishedForm::execute()
{
    std::cout << "CourseFinishedForm execute function called" << std::endl;
}

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(NeedMoreClassRoom)
{
    std::cout << " NeedMoreClassRoomForm Constructor " << std::endl;
}

NeedMoreClassRoomForm::~NeedMoreClassRoomForm()
{
    std::cout << " NeedMoreClassRoomForm Destructor " << std::endl;
}

void NeedMoreClassRoomForm::execute()
{
    std::cout << "NeedMoreClassRoom  execute function called" << std::endl;
}


NeedCourseCreationForm::NeedCourseCreationForm() : Form(NeedCourseCreation)
{
    std::cout << " NeedCourseCreationForm Constructor " << std::endl;
}

NeedCourseCreationForm::~NeedCourseCreationForm()
{
    std::cout << " NeedCourseCreationForm Destructor " << std::endl;
}

void NeedCourseCreationForm::execute()
{
    std::cout << "NeedCourseCreation  execute function called" << std::endl;
}

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(SubscriptionToCourse)
{
    std::cout << " SubscriptionToCourseForm Constructor " << std::endl;
}

SubscriptionToCourseForm::~SubscriptionToCourseForm()
{
    std::cout << " SubscriptionToCourseForm Destructor " << std::endl;
}

void SubscriptionToCourseForm::execute()
{
    std::cout << "Subscription execute function called" << std::endl;
}