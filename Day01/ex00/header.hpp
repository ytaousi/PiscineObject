#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <vector>
#include <list>

struct Position
{
    int x;
    int y;
    int z;
};

struct Statistic
{
    int level;
    int exp;
};

class Worker;

class Tool
{
    public:
        Worker* owner;
        int     numberOfUses;

    public:
        Tool() : owner(NULL), numberOfUses(0) {}
        int getNumberOfUses() { return this->numberOfUses; }
        void setOwner(Worker* newOwner) { this->owner = newOwner; }
        Worker* getOwner() const { return this->owner; }
        virtual void use() = 0;
        virtual ~Tool() {}
};

class Shovel : public Tool
{
    public:
        Shovel() : Tool() {
            this->numberOfUses = 10;
        }
        int getNumberOfUses() { return this->numberOfUses; }
        Worker* getOwner() const { return this->owner; }
        void setOwner(Worker* newOwner) { this->owner = newOwner; }
        void use()
        {
            std::cout << "Shovel is being Used : Digging ...." << std::endl;
            if (this->getNumberOfUses() > 0)
                this->numberOfUses--;
            else
                std::cout << "Shovel is broken" << std::endl;
        }
        ~Shovel() {}
};

class Hammer : public Tool
{
    public:
        Hammer() : Tool() {
            this->numberOfUses = 25;
        }
        int getNumberOfUses() { return this->numberOfUses; }
        Worker* getOwner() const { return this->owner; }
        void setOwner(Worker* newOwner) { this->owner = newOwner; }
        void use()
        {
            std::cout << "Hammer is being Used : Hammering ...." << std::endl;
            if (this->getNumberOfUses() > 0)
                this->numberOfUses--;
            else
                std::cout << "Hammer is broken" << std::endl;
        }
        ~Hammer() {}
};

class Worker
{
    private:
        Position            position;
        Statistic           statistic;
        Shovel*              shovel;
        std::vector<Tool *> tools;

    public:
        Worker()
        {
            this->setPosition(0, 0, 0);
            this->setStats(0, 0);
        }

        void setPosition(int x, int y, int z) {
            this->position.x = x;
            this->position.y = y;
            this->position.z = z;
        }

        void setStats(int lvl, int exp) {
            this->statistic.level = lvl;
            this->statistic.exp = exp;
        }

        void giveTool(Tool& newTool)
        {
            Worker *oldOwner = newTool.getOwner();
            if (oldOwner != NULL)
                oldOwner->takeTool(newTool);
            this->tools.push_back(&newTool);
            newTool.setOwner(this);
        }

        void takeTool(Tool& tool)
        {
            for (std::vector<Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++)
            {
                if (*it == &tool)
                {
                    this->tools.erase(it);
                    tool.setOwner(NULL);
                    return;
                }
            }
        }

        int doIhaveThisTool(Tool& tool)
        {
            for (std::vector<Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++)
            {
                if (*it == &tool)
                    return 1;
            }
            return 0;
        }

        void giveShovel(Shovel &newShovel)
        {
            Worker *oldOwner = newShovel.getOwner();
            if (oldOwner != NULL)
                oldOwner->takeShovel(newShovel);
            this->shovel = &newShovel;
            this->shovel->setOwner(this);
        }

        void takeShovel(Shovel &shovel) {
            Worker *oldOwner = shovel.getOwner();

            oldOwner->getShovel()->setOwner(NULL);
            oldOwner->shovel = NULL;
        }

        int doIhaveShovel() {
            if (this->shovel != NULL)
                return 1;
            return 0;
        }

        Position *getPosition() {
            return &this->position;
        }

        Statistic *getStats() {
            return &this->statistic;
        }
        
        Shovel *getShovel() {
            return this->shovel;
        }
        void work() {
            std::cout << "Working .... " << std::endl;
            for (std::vector<Tool *>::iterator it = this->tools.begin(); it != this->tools.end(); it++)
            {
                (*it)->use();
            }
        }
        ~Worker() {
            ;
        }
};

class Workshop
{
    private:
        std::list<Worker *> workers;
        std::string         name;
    public:
        Workshop() : workers(), name("") {}
        Workshop(std::string name) : workers(), name(name) {}
        std::string &getName() { return this->name; }
        void setName(std::string newName) { this->name = newName; }
        void executeWorkDay()
        {
            for (std::list<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++)
            {
                std::cout << "Strating Work Day for The Worker "  << std::endl;
                (*it)->work();
            }
                
        }
        void registerWorker(Worker* newWorker)
        {
            for (std::list<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++)
            {
                if (*it == newWorker) {
                    std::cout << "Worker already registered" << std::endl;
                    return;
                }
            }
            this->workers.push_back(newWorker);
            std::cout << "Worker registered successfully to " << this->getName() << std::endl;
        }
        void releaseWorker(Worker* worker)
        {
            for (std::list<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++)
            {
                if (*it == worker)
                {
                    this->workers.erase(it);
                    std::cout << "Worker released successfully from " << this->getName() << std::endl;
                    return;
                }
            }
            std::cout << "Worker not found, not currently registered to this workshop" << std::endl;
        }
        Worker* getWorker(Worker* worker) {
            for (std::list<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++)
            {
                if (*it == worker)
                    return *it;
            }
            return NULL;
        }
        std::list<Worker *> getWorkers() { return this->workers; }
        ~Workshop() {}
};

#endif // HEADER_HPP