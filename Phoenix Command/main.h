#pragma once

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <process.h>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include "Literals.h"
#include <random>


using namespace std;

ostream& operator<< (ostream& os, vector<int> vector);
ostream& operator<< (ostream& os, vector<vector<int>> vector);
vector<int> repeater(int number, int times);
int roll(int sides, int times, int mod = 0);
int find_index(double number, vector<double> array);
int find_index(float number, vector<float> array);
int find_index(int number, vector<int> array);