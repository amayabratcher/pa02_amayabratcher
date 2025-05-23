#include "movies.h"
#include <string>
#include <cstring>
#include <cctype>
using namespace std;


Movie::Movie(string name, double rating){
    this -> name = name;
    this -> rating  = rating;
}
bool Movie::Movie::operator<(const Movie& other) const{ //overloading movie operators in order to have them easily alphabetized in a 
    if(this -> name < other.name || (this -> name == other.name && this -> rating > other.rating)){
        return true;
    }                                           // if a movie is less than the other it means it comes first
    return false;
}

bool Movie::Movie::operator>(const Movie& other) const{
     if(this -> name > other.name || (this -> name == other.name && this -> rating < other.rating)){
        return true;
    }                                           // if a movie is more than the other it means it comes after it
    return false;
}
bool Movie::Movie::operator<=(const Movie& other) const{
 return !(*this > other);
}
bool Movie::Movie::operator>=(const Movie& other) const{
  return !(*this < other);
}
bool Movie::Movie::operator==(const Movie& other) const{
    if(this -> rating == other.rating  && this -> name == other.name){
        return true; 
    }
    return false;
}

ostream& operator<<(ostream& out, const Movie& movie){
    out << movie.name << ", " << movie.rating;
    return out;
}

string Movie::getName() const{
    return this -> name;
}

double Movie::getRating() const{
    return this -> rating;
}

