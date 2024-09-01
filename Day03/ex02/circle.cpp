#include "circle.hpp"

Circle::Circle(float radius)
{
    this->setRadius(radius);
}

Circle::~Circle()
{
}

float Circle::getRadius()
{
    return this->radius;
}

void Circle::setRadius(float radius)
{
    this->radius = radius;
}

float Circle::area() // Area of a circle is : PI * radius * radius
{
    std::cout << "Circle area function called: " << std::endl;
    return M_PI * this->radius * this->radius;
}

float Circle::perimeter() // Perimeter of a circle is : 2 * PI * radius
{
    std::cout << "Circle perimeter function called: " << std::endl;
    return 2 * M_PI * this->radius;
}