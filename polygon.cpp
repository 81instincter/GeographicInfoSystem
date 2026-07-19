#include "polygon.hpp"

Polygon::Polygon(){
    name = "";
    vertexCount = 0;
}

Polygon::Polygon(string data){
    // parse data to vertexVector to properly create the polygon object
    vector<string> tokensVec; 
    vector<int> vertexElements;

    stringstream stream(data);
    string token;

    while (stream >> token){
        tokensVec.push_back(token);
    }

    name = tokensVec[0];

    for (int i = 1; i < tokensVec.size(); i++){         // processes all other data in polygonData 
        vertexElements.push_back(stoi(tokensVec[i]));
    }

    int numVertices = 0; // keeps track of the number of vertices (aka point objects)
    vertexVector.clear(); // rids of any previous data from previous program run                        
    for (int i = 0; i < vertexElements.size(); i += 2){
        vertexVector.push_back(Point(vertexElements[i], vertexElements[i + 1]));
        numVertices++; 
    }
    vertexCount = numVertices;
}

Polygon::Polygon(const Polygon& polygonToCopy){
    name = polygonToCopy.name;
    vertexCount = polygonToCopy.vertexCount;
    vertexVector = polygonToCopy.vertexVector;
}

Polygon& Polygon::operator = (const Polygon& originalPolygon){
    if (this != &originalPolygon){ //checks self-assignment and assigns original data to copy of polygon
        /* 
        copies all of originalPolygon's data - name, number of vertices, and the vector containing its
        vertices - to the new polygon object that the new polygon object is being assigned to
        */
        name = originalPolygon.name; 
        vertexCount = originalPolygon.vertexCount;
        vertexVector = originalPolygon.vertexVector;
    }
    return *this; //returns the copied polygon
}

string Polygon::getName(){
    return name;
}

int Polygon::getVertexCount(){
    return vertexCount;
}

Point Polygon::getVertex(int index){
    return vertexVector[index];
}

void Polygon::parse(string data){ // updates an empty Polygon object with passed ("parsed") data or update with new data
    vector<string> tokensVec; 
    vector<int> vertexElements;

    stringstream stream(data);
    string token;

    while (stream >> token){
        tokensVec.push_back(token);
    }

    name = tokensVec[0];
    

    for (int i = 1; i < tokensVec.size(); i++){         // processes all other data in polygonData 
        vertexElements.push_back(stoi(tokensVec[i]));
    }

    int numVertices = 0; // keeps track of the number of vertices (aka point objects)
    
    vertexVector.clear(); // rids of any previous data from previous program run                         
    
    for (int i = 0; i < vertexElements.size(); i += 2){
        Point newPoint(vertexElements[i], vertexElements[i + 1]);
        vertexVector.push_back(newPoint);
        numVertices++; 
    }
    vertexCount = numVertices;
}

bool Polygon::contains(Point testPt){ // uses the ray casting algorithm to see if a point is inside or outside a randomly shaped polygon
    int testX = testPt.getX();
    int testY = testPt.getY();
    int intersections = 0;

    // check for vertices
    for (int i = 0; i < vertexCount; i++){
        if (testX == vertexVector[i].getX() && testY == vertexVector[i].getY()){
            return true;
        }
    }

    // ray casting algorithm [3], [4], [5]
    for (int i = 0; i < vertexCount; i++){
        int x1 = vertexVector[i].getX();
        int y1 = vertexVector[i].getY();
        int x2 = vertexVector[(i + 1) % vertexCount].getX(); // [3] 
        int y2 = vertexVector[(i + 1) % vertexCount].getY(); 


        // checks for non-vertex points on the edges (including horizontal edges)
        if (((testX >= min(x1, x2)) && (testX <= max(x1, x2)) && (testY >= min(y1, y2)) && (testY <= max(y1, y2)))){
            if ((x2 - x1) * (testY - y1) == (y2 - y1) * (testX - x1)){
                return true;
            }
        }

        // check for non-vertex points inside or outside (not on edge)
      if ( (y1 <= testY && testY < y2) || (y2 <= testY && testY < y1) ) { // if the y's are in between vertices
            double xIntersect = ( ( (testY - y1) * (x2 - x1) ) / (y2 - y1) ) + x1; // [5]
            
            if (testX < xIntersect){
                intersections += 1;
            }
        }
    }
    return (intersections % 2) == 1; // If odd, will return true. If even, will return false.
}

// Sources for word and number extraction from a string in C++:
    // [1] https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
    // [2] https://www.geeksforgeeks.org/cpp-string-to-vector-using-delimiter/

// ray casting algorithm that is used to see if a point is inside or outside a polygon:
    // [3] https://medium.com/@girishajmera/exploring-algorithms-to-determine-points-inside-or-outside-a-polygon-038952946f87
    // [4] https://people.utm.my/shahabuddin/?p=6277
    // [5] https://www.geeksforgeeks.org/point-in-polygon-in-cpp/
    // [6] https://www.youtube.com/watch?v=4NshnkzOdI0