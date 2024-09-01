#ifndef ENGINE_HPP
#define ENGINE_HPP

class Engine
{
    private:
        bool isEngineOn;
    public:
        Engine();
        ~Engine();
        //starts the engine
        void start();
        //stops the engine
        void stop();
        // get engine status
        bool getEngineStatus();
        // set engine status
        void setEngineStatus(bool status);
};

#endif