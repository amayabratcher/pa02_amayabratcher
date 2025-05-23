
#ifndef UTILITIES_H
#define UTILITIES_H
#include "movies.h"
#include <string>
#include <cstring>
#include <cctype>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<Movie> findPrefix(string prefix, set<Movie> &allMovies);
Movie bestRated(set<Movie> hasPrefix);
#endif