#include "utilities.h"
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

vector<Movie> findPrefix(string prefix, vector<Movie> &allMovies){
    vector<Movie> hasPrefix;
    int pSize = prefix.size();
    int startIdx;
    for(int i = 0; i < allMovies.size(); i++){
        string name = allMovies[i].getName();
        if(name.substr(0,pSize) == prefix){
            startIdx = i;
            break;
        }
    }
    auto it = allMovies.begin()+startIdx;
    while(startIdx < allMovies.size() && ((*it).getName()).substr(0,pSize) == prefix){
        hasPrefix.push_back(*it);
        it++;
    }
    return hasPrefix;
  }

  Movie bestRated(vector<Movie> hasPrefix){
    Movie bestRated = hasPrefix[0];
    for(int x = 0; x < hasPrefix.size(); x++){
        if(bestRated.getRating() < hasPrefix[x].getRating()){
            bestRated = hasPrefix[x];
        }
    }
    return bestRated;
  }