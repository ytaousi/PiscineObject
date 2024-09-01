#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <string>
#include <vector>

class LinkablePart
{
    public:
        LinkablePart() {}
        virtual ~LinkablePart() {}
        virtual void execute(float p_pression) = 0;
};

class BrakeController : public LinkablePart
{
    private:
        Brake arrayobjects[];
    public:
        BrakeController() {}
        ~BrakeController() {}
        void execute(float p_pression);
};

class Brake
{
    private:
        Wheel* object;
    public:
        Brake() {}
        ~Brake() {}
        void execute(float p_force);
        void attackWheel(Wheel* p_wheel);
};

class Injector : public LinkablePart
{
    private:
        ExplosionChamber* object;
    public:
        Injector() {}
        ~Injector() {}
        void execute(float p_pression);
};

class Wheel
{
    public:
        Wheel() {}
        ~Wheel() {}
        void executeRotation(float p_force);
};

class Gear
{
    private:
        int demultiplier;
    public:
        Gear() : demultiplier(1) {} 
        ~Gear() {}
};
// The structure GearLever is a class that inherits from Singleton<GearLever> con-taining an array of Gear objects and an integer variable level
class GearLevel
{
    private:
        // array of Gear objects
        static GearLevel* instance;
        Gear arrayobjects[10];
        int level;
        GearLevel() : level(0) {}
    public:
        static GearLevel* getInstance()
        {
            if (instance == NULL)
                instance = new GearLevel();
            return instance;
        }
        ~GearLevel() {}
        void change();
};

class Transmission
{
    private:
        std::vector<Wheel *> objects;
    public:
        Transmission() {}
        ~Transmission() {}
        void activate(float p_force);
};

class Crankshaft
{
    private:
        Transmission* object;
    public:
        void receiveForce(float p_volume);
        Crankshaft() {}
        ~Crankshaft() {}
};

class ExplosionChamber
{
    private:
        Crankshaft* object;
    public:
        ExplosionChamber() {}
        ~ExplosionChamber() {}
        void fill(float p_volume);
};

class Motor
{
    private:
        Injector            InjectorObject;
        ExplosionChamber    ExplosionChamberObject;
        Crankshaft          CrankshaftObject;
    public:
        Motor() {}
        ~Motor() {}
        void connectToTransmission(Transmission* p_transmission);
};

class Pedal
{
    private:
        LinkablePart* object;
    public:
        Pedal() {}
        ~Pedal() {}
        void setTarget(LinkablePart* p_part);
        void use(float p_pression);
};

class Direction
{
    private:
        Wheel arrayobjects[];
    public:
        Direction() {}
        ~Direction() {}
        void turn(float p_angle);
};

class DAE
{
    private:
        Direction*  object;
        float       force;
    public:
        DAE() {}
        ~DAE() {}
        void use(float p_angle);
};

class SteerWheel
{
    private:
        DAE* object;
    public:
        SteerWheel() {}
        ~SteerWheel() {}
        void turn(float p_angle);
};


class Cockpit
{
    private:
        Pedal           PedalObject;
        SteerWheel      SteerWheelObject;
        GearLevel*       GearLevelObject;
    public:
        Cockpit() {}
        ~Cockpit() {}
        void method1();
        void method2();
        void method3();
};

class Electronics
{
    private:
        DAE             Object;
    public:
        Electronics() {}
        ~Electronics() {}
};

class Car
{
    private:
        BrakeController BrakeControllerObject;
        Direction       DirectionObject;
        Transmission    TransmissionObject;
        Motor           MotorObject;
        Electronics     ElectronicsObject;
        Cockpit         CockpitObject;
    public:
        Car() {}
        ~Car() {}
};

#endif