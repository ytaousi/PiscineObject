#ifndef HEADER_HPP
#define HEADER_HPP


#include <iostream>
#include <vector>
#include <list>


class Vector2
{
    private:
        float x;
        float y;

    public:
        Vector2() : x(0.0), y(0.0) {};
        Vector2(float x, float y) : x(x), y(y) {};
        float getX() { return this->x; };
        float getY() { return this->y; };
        void setX(float x)
        {
            if (x < 0)
                std::cout << "x cannot be negative the graph display only positive values" << std::endl;
            else 
                this->x = x;
        };
        void setY(float y)
        {
            if (y < 0)
                std::cout << "y cannot be negative the graph display only positive values" << std::endl;
            else
                this->y = y;
        };
        ~Vector2() {};
};


class Graph
{
    private:
        Vector2             *ppointer;
        std::list<Vector2>  ggraph;
        int                 size;

    public:
        Graph() : ppointer(NULL), ggraph(), size(0) {};

        int getSize() { return this->size; };
        void addPoint(Vector2 point)
        {
            ggraph.push_back(point);
            size++;
        }
        void deletePoint(Vector2 point)
        {
            for (std::list<Vector2>::iterator it = ggraph.begin(); it != ggraph.end(); it++)
            {
                if (it->getX() == point.getX() && it->getY() == point.getY())
                {
                    ggraph.erase(it);
                    size--;
                    break;
                }
            }
        }
        void printlist()
        {
            int i = 0;
            for (std::list<Vector2>::iterator it = ggraph.begin(); it != ggraph.end(); it++)
            {
                this->ppointer = &(*it);
                std::cout << "x" << (i + 1) << ": " << this->ppointer->getX() << " y" << (i + 1) << ": " << this->ppointer->getY() << std::endl;
                i++;
            }
        }
        void printGraph()
        {
            // should define the surface of the graph depending on the biggest  value
            float graph_size = 0;
            for (std::list<Vector2>::iterator it = ggraph.begin(); it != ggraph.end(); it++)
            {
                this->ppointer = &(*it);
                if (this->ppointer->getX() > graph_size)
                    graph_size = this->ppointer->getX();
                if (this->ppointer->getY() > graph_size)
                    graph_size = this->ppointer->getY();
            }
            // print the graph using ascii art 
            for (int i = 0; i <= (int)graph_size; i++)
            {
                std::cout << (int)graph_size - i << " ";
                for (int j = 0; j <= graph_size; j++)
                {
                    bool found = false;
                    for (std::list<Vector2>::iterator it = ggraph.begin(); it != ggraph.end(); it++)
                    {
                        this->ppointer = &(*it);
                        if ((int)ppointer->getX() == j && (int)ppointer->getY() == (int)graph_size - i)
                        {
                            std::cout << "x ";
                            found = true;
                            break;
                        }
                        else
                        {

                        }
                    }
                    if (!found)
                        std::cout << ". ";
                }
                std::cout << std::endl;
            }
            std::cout << "  ";
            for (int i = 0; i <= (int)graph_size; i++)
                std::cout << i << " ";
        }

        void clear()
        {
            ggraph.clear();
            size = 0;
        }
        ~Graph() {};
};

#endif