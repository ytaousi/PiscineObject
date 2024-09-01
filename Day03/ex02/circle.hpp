#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "math.h"

class Circle : public Shape
{
    private:
        float radius;

    public:
        Circle(float radius);
        ~Circle();
        float getRadius();
        void setRadius(float radius);
        float area();
        float perimeter();
};

#endif