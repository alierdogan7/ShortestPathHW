#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>
#include <fstream>
#include <algorithm>
using namespace std;

#include "City.h"
#include "Graph.h"

bool loadInput( char *fileName, City **&adjList, int& numVertices );

int main( int argc, char **arg )
{
    // arg[1] <inputFile>, arg[2] <sourceCity>, arg[3] <destinationCity>
    if( argc != 4 )
    {
        cout << "Wrong arguments " << endl;
        return -1;
    }

    City **adjList;
    int numVertices;
    loadInput(arg[1], adjList, numVertices);

    for(int i = 0; i < numVertices; i++)
        (adjList[i])->show();


    return 0;

}

//loading all the tasks from input file to an array
bool loadInput( char *fileName, City **&adjList, int& numVertices )
{

    ifstream myFile(fileName);
    string line("");

    if ( !myFile.is_open() )
    {
        cout << "Unable to open file" << endl;
        return false;
    }
    else
    {
        getline(myFile, line);
        int size = atoi( line.c_str() ); //get size from first line
        int count = 0;

        //generate new City array
        adjList = new City*[size];
        numVertices = size;

        //this loop simply parses each line and generates a Task object
        while ( count < size && getline(myFile, line) )
        {
            string temp("");
            City *tmpCity = new City();

            // first one is ID
            int blankPos = line.find_first_of(" ");
            temp = line.substr(0, blankPos);
            line = line.substr(blankPos + 1);
            tmpCity->setId( atoi( temp.c_str() ) );

            //second one is NAME
            blankPos = line.find_first_of(" ");
            temp = line.substr(0, blankPos);
            line = line.substr(blankPos + 1);
            tmpCity->setName( temp );

            //third one is DEGREE
            blankPos = line.find_first_of(" ");
            temp = line.substr(0, blankPos);
            line = line.substr(blankPos + 1);
            tmpCity->setDegree( atoi( temp.c_str() ) );

            //while \n isn't reached, keep loading the neighbor ids
            //the num of neighbors of the city is equal to the num. of blanks plus 1
            int degree = std::count(line.begin(), line.end(), ' ') + 1;
            int tmpNeighborIds[degree];
            for(int i = 0; i < degree; i++)
            {
                blankPos = line.find_first_of(" ");
                temp = line.substr(0, blankPos);
                line = line.substr(blankPos + 1);
                tmpNeighborIds[i] = atoi(temp.c_str());
            }
            tmpCity->setNeighborIds(tmpNeighborIds, degree);

            //tmpTask->show();
            adjList[count] = tmpCity;
            count++;

        } //end of while loop

        myFile.close();
        return true;
    }
}
