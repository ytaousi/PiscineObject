#ifndef PERSONNEL_HPP
#define PERSONNEL_HPP

#include "mediator.hpp"

class Headmaster 
{
    protected:
        ConcreteMediator* _mediator;
        std::vector<Form *> _formList;
        std::string         _name;
    public:
        Headmaster() : _mediator(new ConcreteMediator(new TweakedMediator())) {// new ConcreteMediator(new Component1(), new Component2())
        };
        ~Headmaster() {
            this->_name = "";
            this->_formList.clear();
            // ConcreteMediator should be properly deleted
        };
        int requestForm(Form* _form){
            (void)_form;
            return 0;
        }
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
        ConcreteMediator* getMediator() {
            return this->_mediator;
        }
        void setName(std::string name) {
            this->_name = name;
        }
        std::string getName() {
            return this->_name;
        }
};

class Secretary 
{
    private:
        std::vector<Form *> formList;
        //FormCreator* _formCreator;
        std::string _name;
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
        void setName(std::string name) {
            this->_name = name;
        }
        std::string getName() {
            return this->_name;
        }

};

#endif