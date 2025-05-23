#include "utilities.h"
#include <string>
#include <cstring>
#include <cctype>
#include <iterator>
#include <algorithm>
using namespace std;

vector<Movie> findPrefix(string prefix, set<Movie> &allMovies){
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

    vector<Movie> hasPrefix;
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
      hasPrefix.push_back(*startIdx);
      startIdx++;
    }
    return hasPrefix;
  }

  bool compareMoviesByRating(const Movie& one, const Movie& two){
    if(one.getRating()  != two.getRating()){
      return one.getRating() > two.getRating();
    }
    return one.getName() < two.getName();
  }

  void bestRatedSort(vector<Movie> &hasPrefix){
    sort(hasPrefix.begin(),hasPrefix.end(), compareMoviesByRating);
    
    
  }