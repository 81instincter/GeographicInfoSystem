#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "point.hpp"
#include <sstream>
using namespace std;

class Polygon{
    public:
        Polygon();
        Polygon(string data);
        Polygon(const Polygon& polygonToCopy); // copy constructor
        Polygon& operator = (const Polygon& originalPolygon); // assignment operator overloading

        string getName();
        int getVertexCount();
        Point getVertex(int index);

        void parse(string data);

        bool contains(Point testPt);

    private:
        string name;
        vector<Point> vertexVector;
        int vertexCount;

};

#endif