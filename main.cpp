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
#include <chrono>
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
    vector<Movie> bestMovies;
    vector<string> prefixWithBestMovie;
    //  For each prefix,
    //  Find all movies that have that prefix and store them in an appropriate data structure
    //  If no movie with that prefix exists print the following message
    auto start = chrono::high_resolution_clock::now();
    for(const string& prefix :prefixes){
        vector<Movie> result = findPrefix(prefix, movies);
        if(result.empty()){
            cout << "No movies found with prefix "<< prefix << endl;
            
        }
        else{
            bestRatedSort(result);
            for(const Movie& movie: result){
                cout << movie << endl;
            }
            bestMovies.push_back(result[0]);
            prefixWithBestMovie.push_back(prefix);
            cout << endl;
            
        }
    }
    if(bestMovies.size() != 0){
        for(int i = 0; i < bestMovies.size(); i++){
            cout << "Best movie with prefix " << prefixWithBestMovie[i] << " is: " << bestMovies[i].getName() << " with rating " << std::fixed << std::setprecision(1) << bestMovies[i].getRating() << endl;
        }
    }
    
    //  For each prefix,
    //  Print the highest rated movie with that prefix if it exists.
    
    auto end = chrono::high_resolution_clock::now();
    double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
    cout << endl;
    cout << " TIME: "<< time_ms << endl;

    return 0;
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/
// part 3a: In my solution my running time is O(m*(n*l+ k log k))
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
//
// part 3b:
//
//
///part 3c:  I designed my code for low time complexity I was not able to achieve this my algorithm isnt too bad but I wasnt able to achieve this 
// in order to sort and print all the values of the the different sized data bases it required alot of loops and because I didnt use a binary search
// type of algorithm it made it the upper bound worse case always o(n) this is also due to having to go through the whole database looking for the prefix
// because my prefix is pre sorted alphabetical it does help find the prefix and prevent me from completely having to search the data base unless the prefix
// doesnt appear at all. My space complexity is o(n) - o(n*m) I think that it is decently low at o(n) but as n gets larger and m and introduced its a little dangerous
// I think that if I made a custom class with a bunch of different functions with destructors it would help alot with the space complexity
// 



bool parseLine(string &line, string &movieName, double &movieRating) {
    int commaIndex = line.find_last_of(",");
    movieName = line.substr(0, commaIndex);
    movieRating = stod(line.substr(commaIndex+1));
    if (movieName[0] == '\"') {
        movieName = movieName.substr(1, movieName.length() - 2);
    }
    return true;
}