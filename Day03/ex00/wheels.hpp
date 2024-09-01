#ifndef WHEELS_HPP
#define WHEELS_HPP

class Wheels
{
    private:
        int wheelAngle;
    public:
        Wheels();
        ~Wheels();
        //turns the wheels by a specified angle
        void turn_wheel(int angle);
        //returns the wheels to a straight-ahead position
        void straighten_wheel();
        // set wheel angle
        void setWheelAngle(int angle);
        // get wheel angle
        int getWheelAngle();
};

#endif