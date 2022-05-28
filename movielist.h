#pragma once

#include <list>
#include "movie.h"

class Blockbuster
{
private:
    std::list<Movie> movieStock;
    std::list<Movie> rentedMovies;

    void insertMovie(const Movie &movie);

    void rentMovie(const std::string &movieCode);

    void returnMovie(const std::string &movieCode);

    void showMovieDetails(const std::string &movieCode);

public:
    void rentMovie();

    void returnMovie();

    void showMovieDetails();

    void printMovieList();

    void addMovie();

    ~Blockbuster();

    Movie getMovie(const std::string &movieCode);
};