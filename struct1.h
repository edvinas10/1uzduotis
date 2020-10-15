#ifndef STRUCT1_H_INCLUDED
#define STRUCT1_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib> //Del rand() funkcijos
#include <time.h>  //del "time"
#include <ctime>
#include <random>
#include <exception>
using std::cout;
using std::cin;
using std::string;
using std::swap;
struct duomuo {
    string Vard;
    string Pav;
    std::vector<int> paz;
    int egz;
    float GP = 0;
};

void rikiuoti(std::vector<int> masyvas, int n);

double rastiMediana(std::vector<int> masyvas, int n);

int randomSk();

#endif // STRUCT1_H_INCLUDED