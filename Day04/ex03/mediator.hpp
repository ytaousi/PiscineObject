#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include "person.hpp"
#include "formCreator.hpp"
#include <iostream>
#include <string>

class Headmaster;
class Secretary;
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
    std::cout << "Apparently all The students has a Course affected to them" << std::endl;
    // this->mediator_->notify(this, "");
  }
  void ProfAttendClass() {
    std::cout << "All Professors Should Go to their Respective ClassRoom" << std::endl;


    //

    std::cout << "Gheyerha every prof should starts its class" << std::endl;
    std::cout << "Apparently every prof has its classrom assigned" << std::endl;
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
  void StudentAttendClass() {
    std::cout << "All Students Should Go to their Respective ClassRoom" << std::endl;
  }
};

class TweakedMediator : public BaseComponent {
  private:
    // Headmaster - Secretary - Professor - Student
    Headmaster * h;
    Secretary * se;
    std::vector<Professor *>    p;
    std::vector<Student *>   st;
  public:
    void setHeadmaster(Headmaster *headmaster) {
      this->h = headmaster;
    }
    void setSecretary(Secretary *secretary) {
      this->se = secretary;
    }
    int setProfessor(Professor *professor) {
      for (size_t i = 0; i < this->p.size(); i++)
      {
        if (p[i] == professor)
        {
          std::cout << "Professor is already set" << std::endl;
          return 1;
        }
      } 
      this->p.push_back(professor);
      return 0;
    }
    int setStudent(Student *student) {
      for (size_t i = 0; i < this->st.size(); i++)
      {
        if(st[i] == student)
        {
          std::cout << "Student is already set" << std::endl;
          return 1;
        }
      }
      this->st.push_back(student);
      return 0;
    }
//Scenario 1
    void attendClass(Headmaster *, Person *) {
      std::cout << "All Professors Should Go to their Respective ClassRoom" << std::endl;
    };// headmaster - professor
    void teachCourse(Person *, Person *) {
      std::cout << "ClassRoom have been afected to all professor's Start Teaching People" << std::endl;
    };// professor - student
    void graduationRequest(Person *, Headmaster *) {
      std::cout << "Starting Graduation Request : Ask Form from Secretay" << std::endl;
    }; // professor - headmaster
    void graduationFormRequest(Headmaster *, Secretary *) {
      std::cout << "" << std::endl;
    };// headmaster - secretary
    void graduationFillFormRequest(Headmaster *, Person *) {};// headmaster - professor
    void graduationSignFormRequest(Person *, Headmaster *) {};// professor - headmaster
    void execFormGraduationTemp(Headmaster *, Person *) {}; // headmaster - student

    void courseSubscriptionRequest(Person *, Headmaster *) {}; // professor - headmaster
    void courseFormRequest(Headmaster *, Secretary *) {}; // headmaster - secretary
    void courseFillFormRequest(Secretary *, Person *) {};  // secretary - professor
    void signFormRequest(Person *, Headmaster *) {};  // professor - headmaster
    void execFormCouseSubscriptionTemp(Headmaster *, Person *) {}; // headmaster - student


//Scenario 2
    //void attendClass(Headmaster *, Person *) {};
    //void startLearning(Person *, Person *) {};
    //void graduationRequest(Person *, Headmaster *) {};
    //void execFormGraduationTemp(Headmaster *, Person *) {};
    //void uselearnedSkillsAndMoveOne(Person *) {};
    
    //void courseSubscriptionRequest(Person *, Headmaster *) {};
    //void courseFormRequest(Headmaster *, Secretary *) {};
    //void courseFillFormRequest(Headmaster *, Person *) {};
    //void signFormRequest(Person *, Headmaster *) {};
    //void execFormCouseSubscriptionTemp(Headmaster *, Person *) {};
};

class ConcreteMediator : public Mediator {
    std::vector<Form *> _formList; // (-,-)
 private:
  Component1 *courseSubscriptionForm;
  // Component2 *courseRequestForm;
  Component2 *graduationForm;
  TweakedMediator *simulation;

 public:
  ConcreteMediator(Component1 *c1, Component2 *c2, TweakedMediator *Tweak) : courseSubscriptionForm(c1), graduationForm(c2), simulation(Tweak) {
    this->graduationForm->set_mediator(this);
    this->courseSubscriptionForm->set_mediator(this);
  }
  void addForm(Form *p_form) {
    this->_formList.push_back(p_form);
  }
  std::vector<Form *> getFormList() {
    return this->_formList;
  }
  TweakedMediator *getTweakedMediator() {
    return this->simulation;
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
      
      std::cout << "All Professors Should Go to their Respective ClassRoom" << std::endl;
      this->courseSubscriptionForm->ProfAttendClass();
    }
    if (event == "TeachCourse") {
      
      std::cout << "ClassRoom have been afected to all professor's Start Teaching People" << std::endl;
      this->courseSubscriptionForm->startTeaching();
    }
    if (event == "lbak7lawtou3amayn") {
      std::cout << "student has failed the class" << std::endl;
      // <----->
    }
    if (event == "CourseSubscriptionRequest") { // first
      
      this->courseSubscriptionForm->CourseSubscriptionRequest();
    }
    if (event == "FormCourseRequest") {
      this->courseSubscriptionForm->CourseFormRequest();
    }
    if (event == "FillFormCourseRequest") {
      this->courseSubscriptionForm->CourseFillFormRequest();
    }
    if (event == "SignFormCourseRequest") {
      this->courseSubscriptionForm->SignFormRequest();
    }
    if (event == "ExecuteFromRequest")
    {
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