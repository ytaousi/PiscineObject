#include "header.hpp"

int main()
{
    Workshop cofeeshop("cofeeshop");
    Workshop foodshop("foodshop");
    Workshop barbershop("barbershop");
    Workshop bakery("bakery");

    Worker *worker1 = new Worker();
    Worker *worker2 = new Worker();
    Worker *worker3 = new Worker();

    Shovel shovel = Shovel();
    Shovel anothershovel = Shovel();
    Hammer hammer = Hammer();
    Hammer anotherhammer = Hammer();
    Shovel anothershovell = Shovel();
    Hammer anotherhammerr = Hammer();

    worker1->setPosition(5, 6, 3);
    worker1->setStats(300, 57689);

    worker2->setPosition(44, 55, 66);
    worker2->setStats(120, 3659);

    worker3->setPosition(33, 1, 42);
    worker3->setStats(1142, 36598752);

    worker1->giveTool(shovel);
    worker1->giveTool(hammer);

    worker2->giveTool(anothershovel);
    worker2->giveTool(anotherhammer);

    worker3->giveTool(anothershovell);
    worker3->giveTool(anotherhammerr);

    std::cout << "----------------" << std::endl;

    cofeeshop.registerWorker(worker1);
    cofeeshop.registerWorker(worker2);
    cofeeshop.registerWorker(worker3);
    foodshop.registerWorker(worker1);
    foodshop.registerWorker(worker2);
    foodshop.registerWorker(worker3);
    barbershop.registerWorker(worker1);
    barbershop.registerWorker(worker2);
    barbershop.registerWorker(worker3);
    bakery.registerWorker(worker3);
    bakery.registerWorker(worker1);
    bakery.registerWorker(worker2);

    std::cout << "-------BAKERY LOGS----------" << std::endl;

    bakery.executeWorkDay();

    std::cout << "-------COFEESHOP LOGS----------" << std::endl;

    cofeeshop.executeWorkDay();

    std::cout << "--------FOODSHOP LOGS----------" << std::endl;

    foodshop.executeWorkDay();

    std::cout << "--------BARBERSHOP LOGS----------" << std::endl;

    barbershop.executeWorkDay();

    return (0);
}