#include "person.hpp"

Person::Person(std::string p_name, t_profession p_profession)
{
    this->setName(p_name);
    this->setProfession(p_profession);
}

Person::~Person()
{
    this->_name.clear();
    this->_professionID = NONE;
}


std::string& Person::getName()
{
    return _name;
};

void Person::setName(std::string name)
{
    this->_name = name;
};

void Person::setProfession(t_profession profession)
{
    this->_professionID = profession;
};

std::string Person::getProfession()
{
    if (this->_professionID == STUDENT) {
        return "STUDENT";
    }
    else if (this->_professionID == PROFESSOR) {
        return "PROFESSOR";
    }
    else if (this->_professionID == STAFF) {
        return "STAFF";
    }
    else {
        return "UNKNOWN";
    }
};