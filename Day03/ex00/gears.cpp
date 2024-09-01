#include "gears.hpp"
#include <iostream>

Gears::Gears()
{
    this->setGearShiftPosition(0);
}

Gears::~Gears()
{
    ;
}

void Gears::shift_gears_up()
{
    if (this->getGearShiftPosition() < 6)
    {
        this->setGearShiftPosition(this->getGearShiftPosition() + 1);
    }
    else
    {
        std::cout << "The gear is already at the highest gear" << std::endl;
    }
}

void Gears::shift_gears_down()
{
    if (this->getGearShiftPosition() > 1)
    {
        this->setGearShiftPosition(this->getGearShiftPosition() - 1);
    }
    else
    {
        std::cout << "The gear is already at the lowest gear" << std::endl;
    }
}

void Gears::reverse()
{
    int actualGearPosition = this->getGearShiftPosition();
    if (actualGearPosition < 6)
    {
        while (actualGearPosition < 6)
        {
            this->shift_gears_up();
        }
        this->setGearShiftPosition(this->getGearShiftPosition() + 1);
        std::cout << "The gear is now in reverse" << std::endl;
    }
}

void Gears::setGearShiftPosition(int position)
{
    this->gearShiftPosition = position;
}

int Gears::getGearShiftPosition()
{
    return this->gearShiftPosition;
}