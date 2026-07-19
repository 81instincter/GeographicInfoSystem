#include "point.hpp"

Point::Point(){
    x_coord = 0;
    y_coord = 0;
}

Point::Point(int x, int y){
    x_coord = x;
    y_coord = y;
}

bool Point::operator == (const Point &coordsToCompare) const { // [1]
    return (getX() == coordsToCompare.getX() && getY() == coordsToCompare.getY()); 
}

int Point::getX() const { return x_coord; } // [2]

int Point::getY() const { return y_coord; }

// Source for learning the "== operator overloading":
    // [1] https://www.geeksforgeeks.org/how-to-overload-operator-in-cpp/
// Source for "Object has type qualifiers that are not compatible with the member function" error:
    // [2] https://stackoverflow.com/questions/24677032/object-has-type-qualifiers-that-are-not-compatible-with-the-member-function