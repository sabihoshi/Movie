#pragma once

#include <string>
#include <iostream>
#include <list>

// Create a Blockbuster Class with the following components:
// Movie Code
// Movie Title
// Movie Genre
// Year Released

// Insert a New Movie (insert operation)
// Rent a Movie (delete operation)
// Return a Movie (append operation)
// Show Movie Details (traversal operation with match Movie Code)
// Print Movie List (traversal operation)
// Quit the Program (destructor)

class Movie
{
private:
    std::string _movieCode;
    std::string _movieTitle;
    std::string _movieGenre;
    int _yearReleased;
public:
    Movie(std::string movieCode, std::string movieTitle, std::string movieGenre, int yearReleased);

    std::string getMovieCode();

    std::string getMovieTitle();

    std::string getMovieGenre();

    int getYearReleased() const;

    void setMovieCode(std::string &movieCode);

    void setMovieTitle(std::string &movieTitle);

    void setMovieGenre(std::string &movieGenre);

    void setYearReleased(int yearReleased);

    void printMovieDetails();

    bool operator==(const Movie &compare) const;
};
