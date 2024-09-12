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
      std::cout << "Starting Form Request : Give Form to be filled" << std::endl;
    };// headmaster - secretary
    void graduationFillFormRequest(Headmaster *, Person *) {
      std::cout << "Starting Form Filling : Give Form to be signed" << std::endl;
    };// headmaster - professor
    void graduationSignFormRequest(Person *, Headmaster *) {
      std::cout << "Starting Form Signing : Give Form to be executed" << std::endl;
    };// professor - headmaster
    void execFormGraduationTemp(Headmaster *, Person *) {
      std::cout << "Starting Form Graduation Execution" << std::endl;
    }; // headmaster - student
    void courseSubscriptionRequest(Person *, Headmaster *) {
      std::cout << "Starting Course Subscription Request" << std::endl;
    }; // professor - headmaster
    void courseFormRequest(Headmaster *, Secretary *) {
      std::cout << "Starting Form Request : Give Form to be filled" << std::endl;
    }; // headmaster - secretary
    void courseFillFormRequest(Secretary *, Person *) {
      std::cout << "Starting Form Filling : Give Form to be signed" << std::endl;
    };  // secretary - professor
    void signFormRequest(Person *, Headmaster *) {
      std::cout << "Starting Form Signing : Give Form to be executed" << std::endl;
    };  // professor - headmaster
    void execFormCouseSubscriptionTemp(Headmaster *, Person *) {
      std::cout << "Starting Form Course Subscription Execution" << std::endl;
    }; // headmaster - student


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
  TweakedMediator *simulation;

 public:
  ConcreteMediator(TweakedMediator *Tweak) : simulation(Tweak) {
    this->simulation->set_mediator(this);
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
  // BaseComponent *sender
  void Notify(BaseComponent *sender, std::string event) const  {
    (void)sender;
    if (event == "AttendClass") {
      std::cout << "Event : " << event << " Triggered" << std::endl;
    }
    if (event == "TeachCourse") {
      std::cout << "Event : " << event << " Triggered" << std::endl;
    }
    if (event == "lbak7lawtou3amayn") {
      std::cout << "Event : " << event << " Triggered" << std::endl;
    }
    if (event == "CourseSubscriptionRequest") { // first
      std::cout << "Event : " << event << " Triggered" << std::endl;
    }
    if (event == "FormCourseRequest") {
      std::cout << "Event : " << event << " Triggered" << std::endl;
    }
    if (event == "FillFormCourseRequest") {
      std::cout << "Event : " << event << " Triggered" << std::endl;
    }
    if (event == "SignFormCourseRequest") {
      std::cout << "Event : " << event << " Triggered" << std::endl;
    }
    if (event == "ExecuteFromRequest") {
      std::cout << "Event : " << event << " Triggered" << std::endl;
    }

    if (event == "GraduationRequest") {
     std::cout << "Event : " << event << " Triggered" << std::endl;
    }
    if (event == "FormGraduationRequest") {
      std::cout << "Event : " << event << " Triggered" << std::endl;
    }
    if (event == "FillFormGraduationRequest") {
      std::cout << "Event : " << event << " Triggered" << std::endl;
    }
    if (event == "SignFormGraduationRequest") {
      std::cout << "Event : " << event << " Triggered" << std::endl;
    }
  }
  void Receive() const {
    std::cout << "Mediator receives: " << std::endl;
  }
};


#endif