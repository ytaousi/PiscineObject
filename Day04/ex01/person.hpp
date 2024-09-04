#ifndef SINGETONS_HPP
#define SINGETONS_HPP

#include <vector>
#include <iostream>
#include "room.hpp"

typedef enum Profession {
    STUDENT,
    PROFESSOR,
    STAFF,
    NONE
} t_profession;


class Person {
    private:
        std::string _name;
        t_profession _professionID;
    public:
        Person(std::string p_name, t_profession p_profession);
        ~Person();
        std::string& getName();
        void setName(std::string name);
        void setProfession(t_profession profession);
        std::string getProfession();
};
#endif