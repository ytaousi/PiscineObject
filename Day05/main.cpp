#include "trains.hpp"
#include "parser.hpp"

#include <iostream>


int processing(char *file1, char *file2)
{
    Parser parser(file1, file2);
    return (1);
}

// void initLogger() {}

void initRailNetworkComponents() {
    // rails - nodes - events - trains 
}

// void lunchSimulation()
// {
//     // create simulation object
//     // Facade , mediator .
// }

int main(int ac, char **av)
{
    if (ac == 3)
    {
        std::cout << "Processing RailsNetworkFile: " <<  av[1] << std::endl;
        if (processing(av[1], av[2]) == 0)
            std::cout << "Success" << std::endl;
        else
            std::cout << "Error" << std::endl;
        // initLogger();
        initRailNetworkComponents();
        // lunchSimulation();
    }
    else
    {
        std::cout << "Usage: ./convert [RailsNetwork] [workingTrainsModels]" << std::endl;
    }
    return (0);
}

// Facade - Observer - Singleton 
// SingleResponsibility - OpenForExtentionClosedForModification - LiskovSubstitution
// InterfaceSegregation - DependencyInversion