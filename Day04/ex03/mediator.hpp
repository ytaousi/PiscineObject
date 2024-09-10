#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include "formCreator.hpp"
#include <iostream>
#include <string>

class BaseComponent;
class Mediator {
    public:
        virtual void Notify(BaseComponent *sender, std::string event) const = 0;
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
  void CheckCheck1() {
    std::cout << "CheckCheck1" << std::endl;
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
  void CheckCheck2() {
    std::cout << "CheckCheck2" << std::endl;
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
  void Notify(BaseComponent *sender, std::string event) const  {
    (void)sender;
    if (event == "AttendClass") {
      std::cout << "Mediator reacts on A and triggers following operations:\n";
    }
    if (event == "TeachCourse") {
      std::cout << "Mediator reacts on A and triggers following operations:\n";
    }
    if (event == "FollowClass") {
      std::cout << "Mediator reacts on A and triggers following operations:\n";
    }
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

    if (event == "GraduationRequest") {
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