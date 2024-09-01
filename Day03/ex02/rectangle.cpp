#include "rectangle.hpp"


Rectangle::Rectangle(int width, int height)
{
    this->setWidth(width);
    this->setHeight(height);
}

Rectangle::~Rectangle()
{
}

int Rectangle::getWidth()
{
    return this->width;
}

int Rectangle::getHeight()
{
    return this->height;
}

void Rectangle::setWidth(int width)
{
    this->width = width;
}

void Rectangle::setHeight(int height)
{
    this->height = height;
}

float Rectangle::area() // Area of a rectangle is : width * height
{
    std::cout << "Rectangle area function called: " << std::endl;
    return this->width * this->height;
}

float Rectangle::perimeter() // Perimeter of a rectangle is : 2 * (width + height)
{
    std::cout << "Rectangle perimeter function called: " << std::endl;
    return 2 * (this->width + this->height);
}