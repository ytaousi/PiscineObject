#include "wheels.hpp"
#include <iostream>

Wheels::Wheels()
{
    this->wheelAngle = 0;
}

Wheels::~Wheels()
{
    ;
}

void Wheels::turn_wheel(int angle)
{
    if (angle < 0)
    {
        std::cout << "The wheel is turning left by " << angle << " degrees" << std::endl;
        this->setWheelAngle(angle);
    }
    else if (angle > 0)
    {
        std::cout << "The wheel is turning right by " << angle << " degrees" << std::endl;
        this->setWheelAngle(angle);
    }
    else
    {
        std::cout << "The wheel is straight" << std::endl;
    }
}

void Wheels::straighten_wheel()
{
    int angle = this->getWheelAngle();
    if (this->getWheelAngle() > 0)
    {
        this->setWheelAngle(this->getWheelAngle() + (this->getWheelAngle() * -1));
        std::cout << "The wheel is turning left by " << angle << " degrees" << std::endl;
        std::cout << "The wheel is straight" << std::endl;
    }
    else if (this->getWheelAngle() < 0)
    {
        this->setWheelAngle(this->getWheelAngle() + (this->getWheelAngle() * -1));
        std::cout << "The wheel is turning right by " << angle << " degrees" << std::endl;
        std::cout << "The wheel is straight" << std::endl;
    }

}

void Wheels::setWheelAngle(int angle)
{
    this->wheelAngle = angle;
}

int Wheels::getWheelAngle()
{
    return this->wheelAngle;
}

