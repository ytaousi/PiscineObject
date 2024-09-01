#include "header.hpp"

int main()
{
    Vector2 point1(1.0, 2.0);
    Vector2 point2(3.0, 4.0);
    Vector2 point3(5.0, 6.0);

    point1.setX(5.1);
    point1.setY(2.2);

    point2.setX(3.0);
    point2.setY(9.3);

    point3.setX(-1);
    point3.setY(-1);

    std::cout << "---------------------------" << std::endl;

    Graph graph;

    graph.addPoint(point1);
    graph.addPoint(point2);
    graph.addPoint(point3);
    graph.addPoint(Vector2(4.8, 2.9));
    


    graph.printlist();
    
    std::cout << "---------------------------" << std::endl;

    graph.printGraph();


    return (0);
}