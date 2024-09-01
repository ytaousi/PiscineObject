#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include <cmath>

class Triangle : public Shape
{
    private:
        double edge1;
        double edge2;
        double edge3;

    public:
        Triangle(double edge1, double edge2, double edge3);
        ~Triangle();
        float area();
        float perimeter();
        void setEdges(double edge1, double edge2, double edge3);
};

#endif