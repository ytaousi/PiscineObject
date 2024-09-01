#include "car.hpp"

int main()
{
    Car car;

    car.getEngine()->start();
    car.accelerate(20);
    car.getGears()->shift_gears_up();
    car.getWheels()->turn_wheel(30);
    car.getEngine()->stop();
    car.getWheels()->straighten_wheel();
    car.accelerate(60);
    car.applyForceOnBrakes(50);
    car.applyEmergencyBrakes();
    car.getGears()->shift_gears_up();
    car.accelerate(100);
    car.getWheels()->turn_wheel(90);
    car.getWheels()->straighten_wheel();
    return (0);
}