#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

vector<double> generateVector(int);
vector<double> groupSums(const vector<double>&, int);
double sumVector(const vector<double>&);
vector<double> removeDuplicates(const vector<double>&, int&);
void sortASC(vector<double>&);
void sortDESC(vector<double>&);
vector<double> maxGroup(const vector<double>&, int);
