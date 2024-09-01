#ifndef GEARS_HPP
#define GEARS_HPP

// 0(N) 1 2 3 4 5 6(R)
class Gears
{
    private:
        int gearShiftPosition;
    public:
        Gears();
        ~Gears();
        //shifts up to the next gear
        void shift_gears_up();
        //shifts down to the previous gear
        void shift_gears_down();
        //puts the transmission in reverse gear
        void reverse();
        // set gear shift position
        void setGearShiftPosition(int position);
        // get gear shift position
        int getGearShiftPosition();
};

#endif