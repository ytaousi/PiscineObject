#ifndef PERSONNEL_HPP
#define PERSONNEL_HPP

#include "mediator.hpp"

class Headmaster 
{
    protected:
        ConcreteMediator* _mediator;
        std::vector<Form *> _formList;
    public:
        Headmaster() : _mediator(new ConcreteMediator(new Component1(), new Component2())) {// new ConcreteMediator(new Component1(), new Component2())
            std::cout << "Headmaster Created" << std::endl;
        };
        ~Headmaster() {};
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
        Component1* getComponent1() {
            return this->_mediator->getComponent1();
        }
        Component2* getComponent2() {
            return this->_mediator->getComponent2();
        }
};

#endif