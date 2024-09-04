#include <iostream>

int processingRailsNetwork(char *file)
{
    (void)file;
    return (1);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::cout << "Processing RailsNetworkFile: " <<  av[1] << std::endl;
        if (processingRailsNetwork(av[1]) == 0)
            std::cout << "Success" << std::endl;
        else
            std::cout << "Error" << std::endl;
    }
    else
    {
        std::cout << "Usage: ./convert [RailsNetwork] [workingTrainsModels]" << std::endl;
    }
    return (0);
}