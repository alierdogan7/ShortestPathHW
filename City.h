#ifndef CITY_H_
#define CITY_H_

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


class City {
public:
    City();
    ~City();
    void setId( int id);
    void setName( string name );
    void setDegree( int degree );
    void setNeighborIds( int* neighborIds, int size );
    int getId();
    string getName();
    int getDegree();
    int* getNeighborIds();
    void show();

private:
    int id;
    string name;
    int degree; //the number of neighbors
    int *neighborIds;
};

#endif
