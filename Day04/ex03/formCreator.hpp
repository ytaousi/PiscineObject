#ifndef FORMCREATOR_HPP
#define FORMCREATOR_HPP

#include <iostream>
#include <vector>

typedef enum FormType
{
	CourseFinished = 0,
	NeedMoreClassRoom = 13,
	NeedCourseCreation = 95,
	SubscriptionToCourse = 42,
    invalidForm = 165
} t_FormType;

typedef enum CourseType
{
    Math = 55,
    Physics = 1,
    Chemistry = 5,
    Biology = 42,
    Programming = 0,
    invalidCourse = 166
} t_CourseType;

typedef enum RoomType
{
    Classroom = 0,
    Laboratory = 1,
    Auditorium = 2,
    Pergola = 55,
    invalidRoom = 167
} t_RoomType;

class Form
{
    private:
        int _formType;
        int _isFilled;
        int _isSigned;

    public:
        Form(int p_formType){
            this->_formType = p_formType;
            this->_isFilled = 0;
            this->_isSigned = 0;
        };
        virtual ~Form(){};
        virtual void execute() = 0; // modify prototype depending the commun need of the forms
        virtual void bestBypassForever() = 0;
        int getFormType(){
            return this->_formType;
        };
        int getIsFilled(){
            return this->_isFilled;
        };
        int getIsSigned(){
            return this->_isSigned;
        };
        void setIsSigned(int p_isSigned){
            this->_isSigned = p_isSigned;
        };
        void setIsFilled(int p_isFilled) {
            this->_isFilled = p_isFilled;
        };
};

class CourseFinishedForm : public Form
{
    private:
        t_CourseType _courseType;

    public:
        CourseFinishedForm() : Form(0){
            this->_courseType = invalidCourse;
        };
        ~CourseFinishedForm(){};
        void bestBypassForever(){
            std::cout << "Form : CourseFinishedForm Successfully Created" << std::endl;
        };
        void execute() {
            if (getIsFilled() == 0)
            {
                std::cout << "Form : CourseFinishedForm is not filled" << std::endl;
                return;
            }
            if (getIsFilled() == 1 && getIsSigned() == 0)
            {
                std::cout << "Form : CourseFinishedForm is filled but not signed" << std::endl;
                return;
            }
            std::cout << "form CourseFinishedForm IS_FILLED AND IS_SIGNED  executing ....." << std::endl;
        }
        // form object getter to be added is the secretary vector<Form *> _formList
        
};

class NeedMoreClassRoomForm : public Form
{
    private:
        t_RoomType _roomType;
    public:
        NeedMoreClassRoomForm() : Form(13){
            this->_roomType = invalidRoom;
        };
        ~NeedMoreClassRoomForm(){};
        void bestBypassForever(){
            std::cout << "Form : NeedMoreClassRoom Successfully Created" << std::endl;
        };
        void execute(){
            if (getIsFilled() == 0)
            {
                std::cout << "Form : NeedMoreClassRoom is not filled" << std::endl;
                return;
            }
            if (getIsFilled() == 1 && getIsSigned() == 0)
            {
                std::cout << "Form : NeedMoreClassRoom is filled but not signed" << std::endl;
                return;
            }
            std::cout << "form NeedMoreClassRoom IS_FILLED AND IS_SIGNED  executing ....." << std::endl;
        };
        
};

class NeedCourseCreationForm : public Form
{
    private:
        t_CourseType _courseType;
    public:
        NeedCourseCreationForm() : Form(95){
            this->_courseType = invalidCourse;
        };
        ~NeedCourseCreationForm(){};
        void bestBypassForever(){
            std::cout << "Form : NeedCourseCreation Successfully Created" << std::endl;
        };
        void execute(){
            if (getIsFilled() == 0)
            {
                std::cout << "Form : NeedCourseCreation is not filled" << std::endl;
                return;
            }
            if (getIsFilled() == 1 && getIsSigned() == 0)
            {
                std::cout << "Form : NeedCourseCreation is filled but not signed" << std::endl;
                return;
            }
            std::cout << "form NeedCourseCreation IS_FILLED AND IS_SIGNED  executing ....." << std::endl;
        };
       
};

class SubscriptionToCourseForm : public Form
{
    private:
        t_CourseType _courseType;
    public:
        SubscriptionToCourseForm() : Form(42){ // -1 for invalid
            this->_courseType = invalidCourse;
        };
        ~SubscriptionToCourseForm(){};
        void bestBypassForever(){
            std::cout << "Form : SubscriptionToCourseForm Successfully Created" << std::endl;
        };
        void execute(){
            if (getIsFilled() == 0)
            {
                std::cout << "Form : SubscriptionToCourseForm is not filled" << std::endl;
                return;
            }
            if (getIsFilled() == 1 && getIsSigned() == 0)
            {
                std::cout << "Form : SubscriptionToCourseForm is filled but not signed" << std::endl;
                return;
            }
            std::cout << "form SubscriptionToCourseForm IS_FILLED AND IS_SIGNED  executing ....." << std::endl;
        };
        
};

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

#endif