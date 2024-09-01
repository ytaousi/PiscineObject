#include "engine.hpp"
#include <iostream>

Engine::Engine()
{
    this->setEngineStatus(false);
}

Engine::~Engine()
{
    ;
}

void Engine::start()
{
    if (this->getEngineStatus() == true)
    {
        std::cout << "The engine is already Started" << std::endl;
        return;
    }
    else
    {
        this->setEngineStatus(true);
        std::cout << "The engine has started" << std::endl;
    }
}

void Engine::stop()
{
    if (this->getEngineStatus() == false)
    {
        std::cout << "The engine is already Stopped" << std::endl;
        return;
    }
    else
    {
        this->setEngineStatus(false);
        std::cout << "The engine has stopped" << std::endl;
    }
}

bool Engine::getEngineStatus()
{
    return this->isEngineOn;
}

void Engine::setEngineStatus(bool status)
{
    this->isEngineOn = status;
}