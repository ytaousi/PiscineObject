#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

int main()
{
    Shape *circle = new Circle(3.42);
    Shape *rectangle = new Rectangle(2, 3);
    Shape *triangle = new Triangle(2, 2, 3);
    


    std::cout << "The Area of The circle is : " << circle->area() << std::endl;
    std::cout << "The Perimeter of The circle is : " << circle->perimeter() << std::endl;

    std::cout << "--------------------------" << std::endl;

    std::cout << "The Area of The rectangle is : " << rectangle->area() << std::endl;
    std::cout << "The Perimeter of The rectangle is : " << rectangle->perimeter() << std::endl;

    std::cout << "--------------------------" << std::endl;

    std::cout << "The Area of The triangle is : " << triangle->area() << std::endl;
    std::cout << "The Perimeter of The triangle is : " << triangle->perimeter() << std::endl;


    delete triangle;
    delete rectangle;
    delete circle;
    return (0);
}