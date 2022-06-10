#pragma once

#include "json.hpp"
#include <string>
#include <iostream>
#include <list>

class Movie
{
private:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Movie, _movieCode, _movieTitle, _movieGenre, _movieProduction, _movieCopies, _yearReleased, _movieImageFilename, _movieAvailability);

    std::string _movieCode;
    std::string _movieTitle;
    std::string _movieGenre;
    std::string _movieProduction;
    std::string _movieImageFilename;
    bool _movieAvailability;
    int _movieCopies;
    int _yearReleased;
public:
    Movie() = default;

    Movie(std::string movieCode, std::string movieTitle, std::string movieGenre, std::string movieProduction, int movieCopies, int yearReleased, std::string movieImageFilename, bool movieAvailability);

    std::string getMovieCode();

    std::string getMovieTitle();

    std::string getMovieGenre();

    std::string getMovieProduction();

    int getMovieCopies();

    std::string getMovieImageFilename();

    bool getMovieAvailability();

    int getYearReleased() const;

    void setMovieCode(std::string &movieCode);

    void setMovieTitle(std::string &movieTitle);

    void setMovieGenre(std::string &movieGenre);

    void setMovieProduction(std::string &movieProduction);

    void setMovieCopies(int movieCopies);

    void setYearReleased(int yearReleased);

    void setMovieImageFilename(std::string &movieImageFilename);

    void setMovieAvailability(bool &movieAvailability);

    void printRentedMovieDetails();

    void printMovieDetails(bool rented);

    bool operator==(const Movie &compare) const;
};