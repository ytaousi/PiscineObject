#ifndef BRAKE_HPP
#define BRAKE_HPP



class Brake
{
    private:
        int     force;
        bool    isBrakeOn;
    public:
        Brake();
        ~Brake();
        //applies a specified force to the brakes
        void apply_force_on_brakes(int force);
        //applies the brakes with maximum force for an emergency stop
        void apply_emergency_brakes();
        // get brake force
        int getBrakeForce();
        // set brake force
        void setBrakeForce(int force);
        // get brake status
        bool getBrakeStatus();
        // set brake status
        void setBrakeStatus(bool status);
};

#endif