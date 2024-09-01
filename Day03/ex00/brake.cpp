#include "brake.hpp"
#include <iostream>

Brake::Brake()
{
    this->setBrakeForce(0);
    this->setBrakeStatus(false);
}

Brake::~Brake()
{
    ;
}

void Brake::apply_force_on_brakes(int force)
{
    if (this->getBrakeStatus() == false)
    {
        this->setBrakeStatus(true);
        this->setBrakeForce(force);
        this->setBrakeStatus(false);
    }
    else
    {
        std::cout << "The brakes are already applied , if Speed Is not Deacresing You Should use Emergency Brakes Carefully or You will Hit Something For Sur unless You are a good Driver Good Luck" << std::endl;
    }
}

void Brake::apply_emergency_brakes()
{
    if (this->getBrakeStatus() == false)
    {
        this->setBrakeForce(100);
        this->setBrakeStatus(true);
    }
    else
    {
        this->setBrakeForce(0);
        this->setBrakeStatus(false);
    }
}

int Brake::getBrakeForce()
{
    return this->force;
}

void Brake::setBrakeForce(int force)
{
    this->force = force;
}

bool Brake::getBrakeStatus()
{
    return this->isBrakeOn;
}

void Brake::setBrakeStatus(bool status)
{
    this->isBrakeOn = status;
}