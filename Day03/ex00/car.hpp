#ifndef CAR_HPP
#define CAR_HPP


#include "brake.hpp"
#include "gears.hpp"
#include "wheels.hpp"
#include "engine.hpp"
#include <iostream>

class Car
{
    private:
        int     speed;
        Wheels*  wheels;
        Gears*   gears;
        Engine*  engine;
        Brake*   brake;

    public:
        //increases the speed of the car by a specified value
        void accelerate(int speed);
        // get speed
        int getSpeed();
        // set speed
        void setSpeed(int speed);
        // apply force to brakes
        void applyForceOnBrakes(int force);
        // apply emergency brakes
        void applyEmergencyBrakes();
        // get the wheels object
        Wheels* getWheels();
        // get the gears object
        Gears* getGears();
        // get the engine object
        Engine* getEngine();
        // get the brake object
        Brake* getBrake();
        Car();
        ~Car();
};

#endif