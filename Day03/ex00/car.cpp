#include "car.hpp"

Car::Car()
{
    this->speed = 0;
    this->wheels = new Wheels();
    this->gears = new Gears();
    this->engine = new Engine();
    this->brake = new Brake();
}

Car::~Car()
{
    delete wheels;
    delete gears;
    delete engine;
    delete brake;
}

int Car::getSpeed()
{
    return speed;
}

void Car::setSpeed(int speed)
{
    this->speed = speed;
}

void Car::applyForceOnBrakes(int force)
{
    Brake* brake = this->getBrake();

    if (this->getEngine()->getEngineStatus() == false)
    {
        std::cout << "The engine is not started Hitting The Brakes Wont Do Anything" << std::endl;
    }
    else
    {
        brake->apply_force_on_brakes(force);
        const float decelerationFactor = 0.2; // Example factor, adjust as needed
        int speedDecrease = static_cast<int>(brake->getBrakeForce() * decelerationFactor);
        this->setSpeed(this->getSpeed() - speedDecrease);
        if (this->getSpeed() < 0) {
            this->setSpeed(0);
            this->getEngine()->stop();
            std::cout << "The car has stopped" << std::endl;
        }
        else
            std::cout << "The car is now going " << this->speed << " km/h" << std::endl;
    }

}

void Car::applyEmergencyBrakes()
{
    Brake* brake = this->getBrake();

    if (this->getEngine()->getEngineStatus() == false)
    {
        std::cout << "The engine is not started Using The Emergency Brakes Wont Do Anything" << std::endl;
    }
    else
    {
        brake->apply_emergency_brakes();
        const float decelerationFactor = 0.5; // Example factor, adjust as needed
        int speedDecrease = static_cast<int>(brake->getBrakeForce() * decelerationFactor);
        this->setSpeed(this->getSpeed() - speedDecrease);
        if (this->getSpeed() < 0) {
            this->setSpeed(0);
            this->getEngine()->stop();
            std::cout << "The car has stopped" << std::endl;
        }
        else
            std::cout << "The car is now going " << this->speed << " km/h" << std::endl;
    }
}

void Car::accelerate(int speed)
{
    Engine* engine = this->getEngine();

    if (engine->getEngineStatus() == false)
    {
        std::cout << "The engine is not started" << std::endl;
    }
    else
    {
        this->setSpeed(this->getSpeed() + speed);
        std::cout << "The car is now going " << this->speed << " km/h" << std::endl;
    }
}

Wheels* Car::getWheels()
{
    return wheels;
}

Gears* Car::getGears()
{
    return gears;
}

Engine* Car::getEngine()
{
    return engine;
}

Brake* Car::getBrake()
{
    return brake;
}


