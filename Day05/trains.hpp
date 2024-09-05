#ifndef TRAINS_HPP 
#define TRAINS_HPP

#include <string>

typedef enum states
{
    SPEEDING,
    MAINTAINING_SPEED,
    BRACKING,
    STOPPED,
    WHATEVER
} t_states;

class Train
{
    private:
        std::string _name;
        int _maximumAccelerationForce;
        int _maximumBreakForce;
        std::string _departureStation; // Station Object is better
        std::string _arrivalStation; // Station Object is better
        int _hourOfDeparture;
        int _timeSpentOnTravel;
    public:
        Train(std::string name, int maximumAccelerationForce, int maximumBreakForce);
        ~Train();
        void setDepartureStation(std::string departureStation);
        void setArrivalStation(std::string arrivalStation);
        void setHourOfDeparture(int hourOfDeparture);
        int getHourOfDeparture();
        std::string getDepartureStation();
        std::string getArrivalStation();
};

#endif