#include "gis.hpp"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

// read file object
bool GIS::readFile(const string& filename){
    ifstream file(filename); // open file using ifstream. [2]

    // confirm file opening
    if (!file.is_open()){ 
        cout << "Invalid file name!" << endl;
        return false;
    }
    else {
        // Read the file line by line into a string
        string line;
        fileLines.clear(); // clears out any previous file line readings
        while (getline(file, line)){ // put the data into a vector. [3]
                fileLines.push_back(line);
                //cout << line << endl;
        }

        // Close file
        file.close();

        // delete any old data potentially still in polygonArray
        deletePolygonArray();

        polygonArraySize = fileLines.size();

        if (polygonArraySize == 0){
                polygonArray = nullptr;
                return true;
        }

        // allocate memory [1]
        polygonArray = new Polygon[polygonArraySize]; // feb 18 2025: was causing a segmentation fault without this

        // populate the polygonArray 
        for (int i = 0; i < polygonArraySize; i++){
                polygonArray[i] = createPolygonObject(fileLines[i]);
        }

        // confirms that the file was read and processed
        return true;
     }
}

// frees up memory taken by the dynamic polygonArray. Is executed once the user exits the program.
void GIS::deletePolygonArray(){
        if (polygonArray != nullptr){
                delete[] polygonArray;
                polygonArray = nullptr;
                polygonArraySize = 0;
        } 
}

Polygon* GIS::getPolygonArray(){
        return polygonArray;
}

int GIS::getPolygonArraySize() const{
        return polygonArraySize;
}

// creates polygon objects by passing the data onto the polygon constructor
Polygon GIS::createPolygonObject(string dataRead){
        return Polygon(dataRead);
}


// Finds the name of the parcel (polygon) associated with the point passed in the argument
string GIS::findParcelName(Point testPt){
        for (int i  = 0; i < polygonArraySize; i++){
                if(polygonArray[i].contains(testPt)){
                        return polygonArray[i].getName();
                }
        }
        return "Not Found"; // without this, was causing a “control reaches end of non-void function” error and screwing up the whole makefile compilation
}

// Returns the lines read from the input file (useful for testing/debugging)
vector<string> GIS::getFileLines(){
    return fileLines;
}

// Creating a dynamic array of objects: 
        // [1] https://www.geeksforgeeks.org/array-of-objects-in-c-with-examples/

// turn each line in the .txt files into a string sources:
        // [2] https://www.geeksforgeeks.org/how-to-read-file-into-string-in-cpp/
        // [3] https://www.geeksforgeeks.org/getline-string-c/