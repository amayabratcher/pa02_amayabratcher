
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



vector<Movie> findPrefix(string prefix, set<Movie> &allMovies);
void bestRatedSort(vector<Movie> &hasPrefix);
bool compareMoviesByRating(const Movie& one, const Movie& two);

#endif