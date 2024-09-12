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
        static int _uniqueID;
        std::string _name;
        int _maximumAccelerationForce;
        int _maximumBreakForce;
        std::string _departureStation; // Station Object is better
        std::string _arrivalStation; // Station Object is better
        std::string _hourOfDeparture;
        int _timeSpentOnTravel;
    public:
        Train(std::string name, int maximumAccelerationForce, int maximumBreakForce)
        {
            this->_name = name;
            this->_maximumAccelerationForce = maximumAccelerationForce;
            this->_maximumBreakForce = maximumBreakForce;
            this->_departureStation = NULL;
            this->_arrivalStation = NULL;
            this->_hourOfDeparture = "";
            this->_timeSpentOnTravel = 0; // keep track of time spent on travel after leaving the station
            this->_uniqueID++;

        }
        ~Train() {};
        int setDepartureStation(std::string departureStation) {
            if (this->_departureStation == NULL) {
                this->_departureStation = departureStation;
                return 0;
            }
            std::cout << "departureStation already affected" << std::endl;
            return 1;
        }
        int setArrivalStation(std::string arrivalStation) {
            if (this->_arrivalStation == NULL) {
                this->_arrivalStation = arrivalStation;
                return 0;
            }
            std::cout << "arrivalStation already affected" << std::endl;
            return 1;
        }
        int setHourOfDeparture(int hourOfDeparture) {
            if (this->_hourOfDeparture == "") {
                this->_hourOfDeparture = hourOfDeparture;
                return 0;
            }
            std::cout << "hourOfDeparture already affected" << std::endl;
            return 1;
        }
        int getHourOfDeparture() {
            return this->_hourOfDeparture;
        }
        std::string getDepartureStation() {
            return this->_departureStation;
        }
        std::string getArrivalStation() {
            return this->_arrivalStation;
        }
};

#endif