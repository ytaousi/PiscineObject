#include "header.hpp"


int main()
{
    Worker*     worker1 = new Worker();
    Worker*     worker2 = new Worker();
    Shovel*     shovel = new Shovel();
    //Shovel*     anotherShovel = new Shovel();

    std::cout << "Starting Position/Stats" << std::endl;

    std::cout << "Worker1" << std::endl;
    std::cout << "x: [" << worker1->getPosition()->x << "] ";
    std::cout << "y: [" << worker1->getPosition()->y << "] ";
    std::cout << "z: [" << worker1->getPosition()->z << std::endl;
    std::cout << "Level: " << worker1->getStats()->level << " ";
    std::cout << "ExperiencePoints: " << worker1->getStats()->exp << std::endl;

    std::cout << "Worker2" << std::endl;
    std::cout << "x: [" << worker2->getPosition()->x << "] ";
    std::cout << "y: [" << worker2->getPosition()->y << "] ";
    std::cout << "z: [" << worker2->getPosition()->z << std::endl;
    std::cout << "Level: " << worker2->getStats()->level << " ";
    std::cout << "ExperiencePoints: " << worker2->getStats()->exp << std::endl;

    std::cout << "------------------------" << std::endl;

    std::cout << "Mods Position/Stats" << std::endl;
    worker1->setPosition(5, 6, 3);
    worker1->setStats(300, 57689);

    worker2->setPosition(44, 55, 66);
    worker2->setStats(1349, 36598752);

    std::cout << "Worker1" << std::endl;
    std::cout << "x: [" << worker1->getPosition()->x << "] ";
    std::cout << "y: [" << worker1->getPosition()->y << "] ";
    std::cout << "z: [" << worker1->getPosition()->z << std::endl;
    std::cout << "Level: " << worker1->getStats()->level << " ";
    std::cout << "ExperiencePoints: " << worker1->getStats()->exp << std::endl;

    std::cout << "Worker2" << std::endl;
    std::cout << "x: [" << worker2->getPosition()->x << "] ";
    std::cout << "y: [" << worker2->getPosition()->y << "] ";
    std::cout << "z: [" << worker2->getPosition()->z << std::endl;
    std::cout << "Level: " << worker2->getStats()->level << " ";
    std::cout << "ExperiencePoints: " << worker2->getStats()->exp << std::endl;

    std::cout << "------------------------" << std::endl;


    std::cout << "Worker1 : Do I have a shovel? " << worker1->doIhaveShovel() << std::endl;
    std::cout << "Worker2 : Do I have a shovel? " << worker2->doIhaveShovel() << std::endl;    
    worker1->giveShovel(shovel);
    std::cout << "Worker1 : Do I have a shovel? " << worker1->doIhaveShovel() << std::endl;
    std::cout << "Worker2 : Do I have a shovel? " << worker2->doIhaveShovel() << std::endl;
    std::cout << shovel->getNumberOfUses() << std::endl;
    worker1->getShovel()->use();
    worker1->getShovel()->use();
    worker1->getShovel()->use();
    std::cout << shovel->getNumberOfUses() << std::endl;
    worker2->giveShovel(shovel);
    
    std::cout << "Worker1 : Do I have a shovel? " << worker1->doIhaveShovel() << std::endl;
    std::cout << "Worker2 : Do I have a shovel? " << worker2->doIhaveShovel() << std::endl;
    worker2->getShovel()->use();
    worker2->getShovel()->use();
    worker2->getShovel()->use();
    std::cout << shovel->getNumberOfUses() << std::endl;
    


    delete worker1;
    delete worker2;

    // delete shovel;
    // delete anotherShovel;
    return (0);
}