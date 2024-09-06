#ifndef SINGLETONS_HPP
#define SINGLETONS_HPP

#include <vector>
#include <iostream>

class Singleton
{
    protected:
        Singleton() {};
        static Singleton* instance;

    public:
        static Singleton* getInstance() {
            if (instance == NULL) {
                instance = new Singleton(); // Create the instance only once
            }
            return instance;
        }

        virtual ~Singleton() {};
};

#endif