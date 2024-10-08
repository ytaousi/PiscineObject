#ifndef PERSONNEL_HPP
#define PERSONNEL_HPP

#include "forms.hpp"


class FormCreator
{
    private:
    public:
        FormCreator(){};
        virtual ~FormCreator(){};
        virtual Form* FactoryMethod() = 0;
        virtual Form* createForm() = 0;
};

class CourseFinishedFormCreator1 : public FormCreator
{
    private:
    public:
        Form* FactoryMethod() {
            return new CourseFinishedForm();
        };
        Form* createForm(){
            Form* form = this->FactoryMethod();
            return form;
        };
};

class NeedMoreClassRoomFormCreator1 : public FormCreator
{
    private:
    public:
        Form* FactoryMethod() {
            return new NeedMoreClassRoomForm();
        };
        Form* createForm(){
            Form* form = this->FactoryMethod();
            return form;
        };
        // Form getter
};

class NeedCourseCreationFormCreator1 : public FormCreator
{
    private:

    public:
        Form* FactoryMethod() {
            return new NeedCourseCreationForm();
        };
        Form* createForm(){
            Form* form = this->FactoryMethod();
            return form;
        };
        
};

class SubscriptionToCourseFormCreator1 : public FormCreator
{
    private:
    public:
        Form* FactoryMethod() {
            return new SubscriptionToCourseForm();
        };
        Form* createForm(){
            Form* form = this->FactoryMethod();
            return form;
        };
        
};


class Headmaster 
{
    private:
    
    public:
        Headmaster() {};
        ~Headmaster() {};
        int signForm(Form * _form) {
            if (_form->getIsFilled() == 0)
            {
                std::cout << "Form [" << _form->getFormTypeString() << "] Not Ready to be signed , need to be filled first" << std::endl;
                return 1;
            }
            else
            {
                std::cout << "Form [" << _form->getFormTypeString() << "] Ready to be signed" << std::endl;
                _form->setIsSigned(1);
                std::cout << "Form [" << _form->getFormTypeString() << "] Signed" << std::endl;
            }
            return 0;
        }
        int executeForm(Form* _form){
            if (_form->getIsFilled() == 0)
            {
                std::cout << "Form [" << _form->getFormTypeString() << "] Not Ready to be executed, Need to be Filled first and then Signed" << std::endl;
                return 1;
            }
            if (_form->getIsSigned() == 0)
            {
                std::cout << "Form [" << _form->getFormTypeString() << "] Not Ready to be executed, need to be signed first" << std::endl;
                return 1;
            }
            std::cout << "ForM [" << _form->getFormTypeString() << "] Executed Successfully by the headmaster object" << std::endl;
            return 0;
        }
};

class Secretary 
{
    private:
        std::vector<Form *> formList;
    public:
        
        Secretary() {};
        virtual ~Secretary() {
        };
        void createForm(t_FormType t_formType) {
            if (t_formType == CourseFinished)
            {
                CourseFinishedFormCreator1 *courseFinished = new CourseFinishedFormCreator1();
                Form *form = courseFinished->FactoryMethod();
                formList.push_back(form);
            }
            else if (t_formType == NeedMoreClassRoom)
            {
                NeedMoreClassRoomFormCreator1 *needMoreClassRoom = new NeedMoreClassRoomFormCreator1();
                Form *form = needMoreClassRoom->FactoryMethod();
                formList.push_back(form);
            }
            else if (t_formType == NeedCourseCreation)
            {
                NeedCourseCreationFormCreator1 *needCourseCreation = new NeedCourseCreationFormCreator1();
                Form *form = needCourseCreation->FactoryMethod();
                formList.push_back(form);
            }
            else if (t_formType == SubscriptionToCourse)
            {
                SubscriptionToCourseFormCreator1 *subscriptionToCourse = new SubscriptionToCourseFormCreator1();
                Form *form = subscriptionToCourse->FactoryMethod();
                formList.push_back(form);                
            }
        }
        std::vector<Form *> getList() {
            return formList;
        }
        void fillForm(Form *form) {
            std::cout << "Filling [" << form->getFormTypeString() << "] with necessary information" << std::endl;
            form->setIsFilled(1);
        }

};



#endif