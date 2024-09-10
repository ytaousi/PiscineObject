#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include "formCreator.hpp"
#include <iostream>
#include <string>

/**
 * The Mediator interface declares a method used by components to notify the
 * mediator about various events. The Mediator may react to these events and
 * pass the execution to other components.
 */
class BaseComponent;
class Mediator {
    public:
        virtual void Notify(BaseComponent *sender, std::string event) const = 0;
};

/**
 * The Base Component provides the basic functionality of storing a mediator's
 * instance inside component objects.
 */
class BaseComponent {
    protected:
        Mediator *mediator_;

    public:
        BaseComponent(Mediator *mediator = NULL) : mediator_(mediator) {};
        void set_mediator(Mediator *mediator) {
            this->mediator_ = mediator;
        };
};

// HeadMaster --> Secretary --> Professor --> Student
//        Graduation Form Diagram
//            -----------------> Pofessor --> Student
//                            Graduation Request
//            <----------------- Pofessor
//        FormRequest
//            --> Secretary
//            <--
//        FillFormRequest
//                             <> Fill  
//            -----------------> Pofessor
//            <----------------- Pofessor
//                                SignFormRequest
//Sign n Exec <>

//        SubscriptionToCourseForm Diagram
//      HeadMaster   Secretary    Professor    Student

// HeadMaster -----------------> Pofessor --> Student
//                        CourseSubscriptionRequest
//            <----------------- Pofessor 
//        FormRequest
//            --> Secretary
//            <--
//        FillFormRequest
//            -----------------> Pofessor
//                             <> Fill
//            <----------------- Pofessor
//                                SignFormRequest
//            <> Sign
//            -----------------> Pofessor
//                               Pofessor --> Student


// CourseSubscriptionRequest - FormRequest - FillFormRequest -SignFormRequest
// GraduationRequest - FormRequest - FillFormRequest -SignFormRequest

/**
 * Concrete Components implement various functionality. They don't depend on
 * other components. They also don't depend on any concrete mediator classes.
 */
class Component1 : public BaseComponent {
 public:
  void CourseSubscriptionRequest() {
    std::cout << "Component 1 does A.\n";
    this->mediator_->Notify(this, "");
  }
  void CourseFormRequest() {
    std::cout << "Component 1 does B.\n";
    this->mediator_->Notify(this, "");
  }
  void CourseFillFormRequest() {
    std::cout << "Component 1 does C.\n";
    this->mediator_->Notify(this, "");
  }
  void SignFormRequest() {
    std::cout << "Component 1 does D.\n";
    this->mediator_->Notify(this, "");
  }
};

class Component2 : public BaseComponent {
 public:
  void GraduationRequest() {
    std::cout << "A graduation Request was Made";
    std::cout << " we need to request q graduation form" << std::endl;
    this->mediator_->Notify(this, "FormGraduationRequest");
  }
  void GraduationFormRequest() {
    std::cout << "Component 2 does F.\n";
    this->mediator_->Notify(this, "");
  }
  void GraduationFillFormRequest() {
    std::cout << "Component 2 does G.\n";
    this->mediator_->Notify(this, "");
  }
  void GraduationSignFormRequest() {
    std::cout << "Component 2 does H.\n";
    this->mediator_->Notify(this, "");
  }
};





/**
 * Concrete Mediators implement cooperative behavior by coordinating several
 * components.
 */
class ConcreteMediator : public Mediator {
    std::vector<FormCreator *> _formList;
 private:
  Component1 *courseSubscriptionForm;
  // Component2 *courseRequestForm;
  Component2 *graduationForm;

 public:
  ConcreteMediator(Component1 *c1, Component2 *c2) : graduationForm(c1), courseRequestForm(c2){
    this->graduationForm->set_mediator(this);
    this->courseSubscriptionForm->set_mediator(this);
  }
  void Notify(BaseComponent *sender, std::string event) const  {
    (void)sender;
    if (event == "CourseSubscriptionRequest") {
      std::cout << "Mediator reacts on A and triggers following operations:\n";
    }
    if (event == "FormCourseRequest") {
      std::cout << "Mediator reacts on C and triggers following operations:\n";
    }
    if (event == "FillFormCourseRequest") {
      std::cout << "Mediator reacts on C and triggers following operations:\n";
    }
    if (event == "SignFormCourseRequest") {
      std::cout << "Mediator reacts on C and triggers following operations:\n";
    }
    if (event == "GraduationForm") {
      std::cout << "Mediator reacts on D and triggers following operations:\n";
      this->graduationForm->GraduationFormRequest();
    }
    if (event == "FormGraduationRequest") {
      std::cout << "Mediator reacts on D and triggers following operations:\n";
      std::cout << "" << std::endl;
      this->graduationForm->GraduationFormRequest();
    }
    if (event == "FillFormGraduationRequest") {
      std::cout << "Mediator reacts on D and triggers following operations:\n";

    }
    if (event == "SignFormGraduationRequest") {
      std::cout << "Mediator reacts on D and triggers following operations:\n";
    }
  }
};


#endif