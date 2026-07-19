#ifndef GIS_H
#define GIS_H

#include "polygon.hpp"
#include <vector> 
#include <string>

/*
The Gis class reads text files and parses them to the other files to read the data, make comparisons, and 
*/

class GIS{
    public:
        // for getting polygon data from files, creating Polygon objects out of them, and storing them inside a dynamic array
        bool readFile(const string& filename); // reads file name, parses data through createPolygonObject(), and populates polygonArray
        vector<string> getFileLines();
        int getPolygonArraySize() const;
        Polygon* getPolygonArray();

        Polygon createPolygonObject(string dataRead);// parses data in Polygon parameterized constructor 
        void deletePolygonArray(); // delete dynamic array to free up memory

        string findParcelName(Point testPt);
        

    private:
        int polygonArraySize; // unitialized to avoid memory errors
        Polygon *polygonArray = nullptr; // set as a nullptr to avoid memory issues
        vector<string> fileLines; // part of the readFile() function. Used to feed createPolygonObject() function. 
    };

#endif