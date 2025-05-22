#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;



class Movie{
    private:
    string name;
    double rating;
    
    public:
    
    Movie(string name, double rating);
    bool operator>(const Movie& other)const;
    bool operator<(const Movie& other) const;
    bool operator>=(const Movie& other) const;
    bool operator<=(const Movie& other) const;
    bool operator==(const Movie& other)const;
    friend ostream& operator<<(ostream& out, const Movie& movie);
    string getName();
    double getRating();
};



#endif