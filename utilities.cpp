#include "utilities.h"
#include <string>
#include <cstring>
#include <cctype>
#include <iterator>
using namespace std;

set<Movie> findPrefix(string prefix, set<Movie> &allMovies){
    // vector<Movie> hasPrefix;
    // int pSize = prefix.size();
    // int startIdx;
    // for(int i = 0; i < allMovies.size(); i++){
    //     string name = allMovies[i].getName();
    //     if(name.substr(0,pSize) == prefix){
    //         startIdx = i;
    //         break;
    //     }
    // }
    // auto it = allMovies.begin()+startIdx;
    // while(startIdx < allMovies.size() && ((*it).getName()).substr(0,pSize) == prefix){
    //     hasPrefix.push_back(*it);
    //     it++;
    // }
    // return hasPrefix;

    set<Movie> hasPrefix;
    int pSize = prefix.size();
    auto startIdx = allMovies.begin();
    for(auto it = allMovies.begin(); it != allMovies.end(); it++){
        string name = it -> getName();
        if(name.substr(0,pSize) == prefix){
          startIdx = it;
          break;
        }
    }
    while(startIdx != allMovies.end() && startIdx -> getName().substr(0,pSize) == prefix){
      hasPrefix.insert(*startIdx);
      startIdx++;
    }
    return hasPrefix;
  }

  Movie bestRated(set<Movie> hasPrefix){
    Movie bestRated = *hasPrefix.begin();
    for(const Movie& movie: hasPrefix){
      if(bestRated.getRating() < movie.getRating()){
        bestRated = movie;
      }
    }
    return bestRated;
  }