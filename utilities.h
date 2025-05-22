
#ifndef UTILITIES_H
#define UTILITIES_H
#include "movies.h"
#include <string>
#include <cstring>
#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

vector<Movie> findPrefix(string prefix, vector<Movie> &allMovies);
Movie bestRated(vector<Movie> hasPrefix);
#endif