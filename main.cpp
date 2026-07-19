#include "gis.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

int main(){
    GIS gis;
    string fileName;
    ifstream file;

    // for getting and opening the file name inputted
    while (true){
        cout << "Please enter the file with the polygon data: ";
        cin >> fileName;
        file.open(fileName);
        if (!file){ // [1]
            cout << "Invalid file name!" << endl;
            file.clear();
        }
        else {
            break;
        }
    }
    
    gis.readFile(fileName);
    file.close();

    // prompting for the query points
    while(true){
        string programInputX, programInputY;
        int x, y;

        cout << "Coordinates of query point (non-integer quits)" << endl;
        cout <<"\tx: ";
        cin >> programInputX;
        if (programInputX == "quit" || programInputX == "q"){
            break;
        }
        try{
            x = stoi(programInputX); // prevent stoi exceptions on "q"/quit/non-numbers
        } catch (...){
            break; // non-integer input quits gracefully
        }

        cout << "\ty: ";
        cin >> programInputY;
        if (programInputY == "quit" || programInputY == "q"){
            break;
        }
        try{
            y = stoi(programInputY); // prevent stoi exceptions on "q"/quit/non-numbers
        } catch (...){
            break; // non-integer input quits gracefully
        }
       

       cout << "Query point is inside: " << gis.findParcelName(Point (x,y)) << endl;
    }

    gis.deletePolygonArray();
    cout << "Have a great day!" << endl;
    return 0;
}

// file error handling:
    // [1] https://www.edureka.co/blog/file-handling-in-cpp/#checking-for-errors-with-fstream