#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "City.h"

City::City()
{
    this->id = 0;
    this->name = "Unknown";
    this->degree = 0; //the number of neighbors
    this->neighborIds = NULL;
}

City::~City()
{
    delete []this->neighborIds;
}

void City::setId( int id) { this->id = id; }
void City::setName( string name ) { this->name = name; }
void City::setDegree( int degree ) { this->degree = degree; }
void City::setNeighborIds( int* neighborIds, int size )
{
    this->neighborIds = new int[size];
    for(int i = 0; i < size; i++)
        this->neighborIds[i] = neighborIds[i];
}

int City::getId() { return this->id; }
string City::getName() { return this->name; }
int City::getDegree() { return this->degree; }
int* City::getNeighborIds() { return this->neighborIds; }

void City::show()
{
    cout << "City " << this->id << ": " << this->name << ", degree: " << this->degree << "\nNeighbors: ";
    for(int i = 0; i < this->degree; i++)
        cout << this->neighborIds[i] << " ";
    cout << endl;
}
