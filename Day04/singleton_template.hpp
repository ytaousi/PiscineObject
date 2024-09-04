#ifndef SINGLETONS_HPP
#define SINGLETONS_HPP

#include <vector>
#include <iostream>

class Singleton
{
    protected:
        Singleton() {};
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
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