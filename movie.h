#pragma once

#include "json.hpp"
#include <string>
#include <iostream>
#include <list>

class Movie
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Movie, _movieCode, _movieTitle, _movieGenre, _yearReleased);

    std::string _movieCode;
    std::string _movieTitle;
    std::string _movieGenre;
    int _yearReleased;
public:
    Movie() = default;

    Movie(std::string movieCode, std::string movieTitle, std::string movieGenre, int yearReleased);

    std::string getMovieCode();

    std::string getMovieTitle();

    std::string getMovieGenre();

    int getYearReleased() const;

    void setMovieCode(std::string &movieCode);

    void setMovieTitle(std::string &movieTitle);

    void setMovieGenre(std::string &movieGenre);

    void setYearReleased(int yearReleased);

    void printRentedMovieDetails();

    void printMovieDetails(bool rented);

    bool operator==(const Movie &compare) const;

};