#include "header.hpp"
#include "stdio.h"
int main()
{
    Worker*     worker1 = new Worker();
    Worker*     worker2 = new Worker();
    Worker*     worker3 = new Worker();
    Shovel      anothershovell = Shovel();
    Shovel     anothershovel = Shovel();

    Shovel       shovel = Shovel();
    Shovel       anothershovelll = Shovel();
    Hammer       hammer = Hammer();
    Hammer       anotherhammer = Hammer();

    worker1->setPosition(5, 6, 3);
    worker1->setStats(300, 57689);

    worker2->setPosition(44, 55, 66);
    worker2->setStats(120, 3659);

    worker3->setPosition(33, 1, 42);
    worker3->setStats(1142, 36598752);

    std::cout << "------------------------" << std::endl;

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

    std::cout << "Worker3" << std::endl;
    std::cout << "x: [" << worker3->getPosition()->x << "] ";
    std::cout << "y: [" << worker3->getPosition()->y << "] ";
    std::cout << "z: [" << worker3->getPosition()->z << std::endl;
    std::cout << "Level: " << worker3->getStats()->level << " ";
    std::cout << "ExperiencePoints: " << worker3->getStats()->exp << std::endl;

    std::cout << "------------------------" << std::endl;

    worker1->giveShovel(anothershovel);

    printf("Shovel : %p\n", worker1->getShovel());
    worker2->giveShovel(anothershovell);
    printf("Shovel : %p\n", worker2->getShovel());

    std::cout << "Do I have Shovel? : Worker1" << worker1->doIhaveShovel() << std::endl;
    std::cout << "Do I have Shovel? : Worker1" << worker2->doIhaveShovel() << std::endl;

    worker3->giveShovel(anothershovel);
    printf("Shovel : %p\n", worker3->getShovel());

    std::cout << "Do I have Shovel? : Worker1 " << worker1->doIhaveShovel() << std::endl;
    std::cout << "Do I have Shovel? : Worker3 " << worker3->doIhaveShovel() << std::endl;

    worker1->giveShovel(anothershovel);

    std::cout << "Do I have Shovel? : Worker1 " << worker1->doIhaveShovel() << std::endl;
    std::cout << "Do I have Shovel? : Worker3 " << worker3->doIhaveShovel() << std::endl;

    worker1->takeShovel(anothershovel);
    std::cout << "Do I have Shovel? : Worker1 " << worker1->doIhaveShovel() << std::endl;
    worker3->giveShovel(anothershovell);
    
    std::cout << "Do I have Shovel? : Worker3 " << worker3->doIhaveShovel() << std::endl;
    worker3->takeShovel(anothershovell);
    std::cout << "Do I have Shovel? : Worker3 " << worker3->doIhaveShovel() << std::endl;
    std::cout << "Do I have Shovel? : Worker2 " << worker2->doIhaveShovel() << std::endl;



    worker1->giveTool(anotherhammer);
    std::cout << "Worker1 : Do I have This Tool? anotherhammer " << worker1->doIhaveThisTool(anotherhammer) << std::endl;
    worker1->giveTool(shovel);
    worker2->giveTool(hammer);
    std::cout << "Worker2 : Do I have This Tool? anotherhammer " << worker2->doIhaveThisTool(anotherhammer) << std::endl;
    worker2->giveTool(anotherhammer);
    std::cout << "Worker2 : Do I have This Tool? anotherhammer " << worker2->doIhaveThisTool(anotherhammer) << std::endl;
    
    worker1->giveTool(anotherhammer);
    std::cout << "Worker1 : Do I have This Tool? anotherhammer " << worker1->doIhaveThisTool(anotherhammer) << std::endl;
    std::cout << "Worker2 : Do I have This Tool? anotherhammer " << worker2->doIhaveThisTool(anotherhammer) << std::endl;
    

    delete worker1;
    delete worker2;
    delete worker3;
    return (0);
}