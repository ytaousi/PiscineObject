#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>

class Shape
{
    private:
    public:
        Shape();
        virtual ~Shape();
        // calculate the area of the shape
        virtual float area();
        // calculate the perimeter of the shape
        virtual float perimeter();
};

#endif