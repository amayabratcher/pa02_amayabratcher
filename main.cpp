// Winter'24
// Instructor: Diba Mirza
// Student name: 
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

#include "utilities.h"
#include "movies.h"

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[ 0 ] << " moviesFilename prefixFilename " << endl;
        exit(1);
    }

    ifstream movieFile (argv[1]);
 
    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
    // Create an object of a STL data-structure to store all the movies
    set<Movie> movies;
    string line, movieName;
    double movieRating;
    // Read each file and store the name and rating
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
            // Use std::string movieName and double movieRating
            // to construct your Movie objects
            // cout << movieName << " has rating " << movieRating << endl;
            // insert elements into your data structure
            Movie movie(movieName,movieRating);
            movies.insert(movie);
            
    }

    movieFile.close();

    if (argc == 2){
            for(const Movie& movie : movies){
                cout << movie << endl;
            }
            //print all the movies in ascending alphabetical order of movie names
            return 0;
    }

    ifstream prefixFile (argv[2]);

    if (prefixFile.fail()) {
        cerr << "Could not open file " << argv[2];
        exit(1);
    }

    vector<string> prefixes;
    while (getline (prefixFile, line)) {
        if (!line.empty()) {
            prefixes.push_back(line);
        }
    }

    //  For each prefix,
    //  Find all movies that have that prefix and store them in an appropriate data structure
    //  If no movie with that prefix exists print the following message
    for(const string& prefix :prefixes){
        vector<Movie> result = findPrefix(prefix, movies);
        if(result.empty()){
            cout << "No movies found with prefix "<< prefix << endl;
            cout <<  endl;
        }
        else{
            bestRatedSort(result);
            for(const Movie& movie: result){
                cout << movie << endl;
            }
             
            cout << "Best movie with prefix " << prefix << " is: " << result[0].getName() << " with rating " << std::fixed << std::setprecision(1) << result[0].getRating() << endl;
        }
    }
       
    //  For each prefix,
    //  Print the highest rated movie with that prefix if it exists.
   

    return 0;
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/
// In my solution my running time is O(m*(n*l+ k log k))
// where there are n movies in the dataset.
//there are m prefixes specified in a given run of your program.
//at most k movies begin with each prefix.
//l is the maximum number of characters in a movie name
// the n * l comes from the beginning of my code
// first my code checks from the beginning to see if any of the 
// movies names start with the same prefix 
// if it is the worse case senario that is not found until the end of the
// set of movie names
// then my code stores the all the values from that point on alphbetically
// that contain that prefix
//after that i then used a custom sort algorithm in order to rearrange my vector
// most sort algorithms run at a running time of n log n in this case it is k log k
// since these loops are seperate and not nested they are added together
//and then since m is the number of prefixes m is then multiplied by (n*l + k log k)
// giving us a worse case time complexity of O(m*(n*l+k log k))
bool parseLine(string &line, string &movieName, double &movieRating) {
    int commaIndex = line.find_last_of(",");
    movieName = line.substr(0, commaIndex);
    movieRating = stod(line.substr(commaIndex+1));
    if (movieName[0] == '\"') {
        movieName = movieName.substr(1, movieName.length() - 2);
    }
    return true;
}