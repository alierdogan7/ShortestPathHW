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

private:
    int id;
    string name;
    int degree; //the number of neighbors
    int *neighborIds;
};

#endif
