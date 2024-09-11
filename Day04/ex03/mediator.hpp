#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include "formCreator.hpp"
#include <iostream>
#include <string>

class BaseComponent;
class Mediator {
    public:
        virtual void Notify(BaseComponent *sender, std::string event) const = 0;
        virtual void Receive() const = 0;
};

class BaseComponent {
    protected:
        Mediator *mediator_;
    public:
        BaseComponent(Mediator *mediator = NULL) : mediator_(mediator) {};
        void set_mediator(Mediator *mediator) {
            this->mediator_ = mediator;
        };
};

class Component1 : public BaseComponent {
 public:
  void CourseSubscriptionRequest() {
    std::cout << "Component 1 does A.\n";
    // Processing for CourseSubscription Started
    // Professor with no course attend processing
    this->mediator_->Notify(this, "FormCourseRequest");
  }
  void CourseFormRequest() {
    std::cout << "Component 1 does B.\n";
    // Processing Course Form Request
    // get Form from Secretary then
    this->mediator_->Notify(this, "FillFormCourseRequest");
  }
  void CourseFillFormRequest() {
    std::cout << "Component 1 does C.\n";
    // Filling Form Processing
    // professor filling form processing
    this->mediator_->Notify(this, "SignFormCourseRequest");
  }
  void SignFormRequest() {
    std::cout << "Component 1 does D.\n";
    // headmaster signs filled forms
    this->mediator_->Notify(this, "ExecuteFormRequest");
  }
  void ExecFormCouseSubscriptionTemp() {
    std::cout << "Master should exec CourseSubscription form" << std::endl;
  }
  void startTeaching() {
    std::cout << "All Professors Should Starting teaching Courses" << std::endl;

  }
  void ProfAttendClass() {
    std::cout << "All Professors Should Go to their Respective ClassRoom" << std::endl;
    this->mediator_->Notify(this, "TeachCourse");
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
    //
    this->mediator_->Notify(this, "FillFormGraduationRequest");
  }
  void GraduationFillFormRequest() {
    std::cout << "Component 2 does G.\n";
    this->mediator_->Notify(this, "SignFormGraduationRequest");
  }
  void GraduationSignFormRequest() {
    std::cout << "Component 2 does H.\n";
    this->mediator_->Notify(this, "");
  }
  void ExecFormGraduationTemp() {
    std::cout << "Master should exec Graduation form" << std::endl;
  }
};

class ConcreteMediator : public Mediator {
    std::vector<Form *> _formList; // (-,-)
 private:
  Component1 *courseSubscriptionForm;
  // Component2 *courseRequestForm;
  Component2 *graduationForm;

 public:
  ConcreteMediator(Component1 *c1, Component2 *c2) : courseSubscriptionForm(c1), graduationForm(c2) {
    this->graduationForm->set_mediator(this);
    this->courseSubscriptionForm->set_mediator(this);
  }
  void addForm(Form *p_form) {
    this->_formList.push_back(p_form);
  }
  std::vector<Form *> getFormList() {
    return this->_formList;
  }
  Component1 *getComponent1()  {
    return this->courseSubscriptionForm;
  }
  Component2 *getComponent2()  {
    return this->graduationForm;
  }
  // BaseComponent *sender
  void Notify(BaseComponent *sender, std::string event) const  {
    (void)sender;
    if (event == "AttendClass") {
      std::cout << "Mediator reacts on A and triggers following operations:\n";
      std::cout << "All Professors Should Go to their Respective ClassRoom" << std::endl;
      this->courseSubscriptionForm->ProfAttendClass();
    }
    if (event == "TeachCourse") {
      std::cout << "Mediator reacts on A and triggers following operations:\n";
      std::cout << "ClassRoom have been afected to all professor's Start Teaching People" << std::endl;
      this->courseSubscriptionForm->startTeaching();
    }
    if (event == "FollowClass") {
      std::cout << "Mediator reacts on A and triggers following operations:\n";
    }
    if (event == "CourseSubscriptionRequest") { // first
      std::cout << "Mediator reacts on A and triggers following operations:\n";
      this->courseSubscriptionForm->CourseSubscriptionRequest();
    }
    if (event == "FormCourseRequest") {
      std::cout << "Mediator reacts and triggers following operations:\n";
      this->courseSubscriptionForm->CourseFormRequest();
    }
    if (event == "FillFormCourseRequest") {
      std::cout << "Mediator reacts and triggers following operations:\n";
      this->courseSubscriptionForm->CourseFillFormRequest();
    }
    if (event == "SignFormCourseRequest") {
      std::cout << "Mediator reacts and triggers following operations:\n";
      this->courseSubscriptionForm->SignFormRequest();
    }
    if (event == "ExecuteFromRequest")
    {
      std::cout << "Mediator react and triggers following operations:\n " << std::endl;
      this->courseSubscriptionForm->ExecFormCouseSubscriptionTemp();
    }

    if (event == "GraduationRequest") {
      std::cout << "Mediator reacts on D and triggers following operations:\n";
      // processing for graduation request
      // asking for graduation form process
      this->graduationForm->GraduationRequest();
    }
    if (event == "FormGraduationRequest") {
      std::cout << "Mediator reacts on D and triggers following operations:\n";
      std::cout << "" << std::endl;
      this->graduationForm->GraduationFormRequest();
    }
    if (event == "FillFormGraduationRequest") {
      std::cout << "Mediator reacts on D and triggers following operations:\n";
      this->graduationForm->GraduationFillFormRequest();
    }
    if (event == "SignFormGraduationRequest") {
      std::cout << "Mediator reacts on D and triggers following operations:\n";
      this->graduationForm->ExecFormGraduationTemp();
    }
  }
  void Receive() const {
    std::cout << "Mediator receives: " << std::endl;
  }
};


#endif