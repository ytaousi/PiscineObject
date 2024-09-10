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
            //form->execute();
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
            //form->execute();
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
            //form->execute();
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
            //form->execute();
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
                std::cout << "Form [" << _form->getFormType() << "] Not Ready to be signed , need to be filled first" << std::endl;
                return 1;
            }
            else
            {
                std::cout << "Form [" << _form->getFormType() << "] Ready to be signed" << std::endl;
                _form->setIsSigned(1);
                std::cout << "Form [" << _form->getFormType() << "] Signed" << std::endl;
            }
            return 0;
        }
        int executeForm(Form* _form){
            if (_form->getIsFilled() == 0)
            {
                std::cout << "Form [" << _form->getFormType() << "] Not Ready to be executed, Need to be Filled first and then Signed" << std::endl;
                return 1;
            }
            if (_form->getIsSigned() == 0)
            {
                std::cout << "Form [" << _form->getFormType() << "] Not Ready to be executed, need to be signed first" << std::endl;
                return 1;
            }
            std::cout << "ForM Executed Successfully by the headmaster object" << std::endl;
            return 0;
        }
};

class Secretary 
{
    private:
        std::vector<Form *> formList;
        FormCreator* _formCreator;
    public:
        Secretary() {
            ;
        }
        // Secretary(FormCreator *formCreator = nullptr) _formCreator(formCreator) { 
        // };
        virtual ~Secretary() {
        };
        void createForm(t_FormType t_formType) const {
            if (t_formType == CourseFinished)
            {
                //CourseFinishedFormCreator1();
                CourseFinishedFormCreator1 *CourseFinished = new CourseFinishedFormCreator1();
                
                Form *form = CourseFinished->FactoryMethod();
                form->bestBypassForever();
                // get a const value of the object to pushback to the list
                
            }
            else if (t_formType == NeedMoreClassRoom)
            {
                //CourseFinishedFormCreator1();
                NeedMoreClassRoomFormCreator1 *NeedMoreClassRoom = new NeedMoreClassRoomFormCreator1();
                
                Form *form = NeedMoreClassRoom->FactoryMethod();
                form->bestBypassForever();
                //NeedMoreClassRoom->FactoryMethod();
                
            }
            else if (t_formType == NeedCourseCreation)
            {
               NeedCourseCreationFormCreator1 *NeedCourseCreation = new NeedCourseCreationFormCreator1();
                
                Form *form = NeedCourseCreation->FactoryMethod();
                form->bestBypassForever();
                
                //NeedCourseCreation->FactoryMethod();
                 
            }
            else if (t_formType == SubscriptionToCourse)
            {
                SubscriptionToCourseFormCreator1 *SubscriptionToCourse = new SubscriptionToCourseFormCreator1();
                
                Form *form = SubscriptionToCourse->FactoryMethod();
                form->bestBypassForever();
                //SubscriptionToCourse->createForm();
                
            }
        }
        std::vector<Form *> getList() {
            return formList;
        }

};



#endif