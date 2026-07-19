#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point{
    public:
        Point();
        Point(int x, int y);
        bool operator==(const Point &coordsToCompare) const;

        int getX() const;
        int getY() const;
    private:
        int x_coord;
        int y_coord;

};

#endif