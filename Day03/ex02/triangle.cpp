#include "triangle.hpp"


Triangle::Triangle(double edge1, double edge2, double edge3)
{
    this->setEdges(edge1, edge2, edge3);
}

Triangle::~Triangle()
{
}

void Triangle::setEdges(double edge1, double edge2, double edge3)
{
    this->edge1 = edge1;
    this->edge2 = edge2;
    this->edge3 = edge3;
}

float Triangle::area() // Area of a triangle is : sqrt(s * (s - a) * (s - b) * (s - c))
{
    std::cout << "Triangle area function called: " << std::endl;
    float s = (this->edge1 + this->edge2 + this->edge3) / 2;
    return sqrt(s * (s - this->edge1) * (s - this->edge2) * (s - this->edge3));
}

float Triangle::perimeter() // Perimeter of a triangle is : a + b + c
{
    std::cout << "Triangle perimeter function called: " << std::endl;
    return this->edge1 + this->edge2 + this->edge3;
}