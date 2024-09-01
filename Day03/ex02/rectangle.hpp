#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
    private:
        int width;
        int height;

    public:
        Rectangle(int width, int height);
        ~Rectangle();
        int getWidth();
        int getHeight();
        void setWidth(int width);
        void setHeight(int height);
        float area();
        float perimeter();
};

#endif