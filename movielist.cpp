#include "movielist.h"
#include <iostream>
#include <iomanip>

void Blockbuster::rentMovie(const std::string &movieCode)
{
    for (auto &movie: movieStock)
    {
        if (movie.getMovieCode() == movieCode)
        {
            movieStock.remove(movie);
            rentedMovies.push_back(movie);
            std::cout << "Movie rented successfully" << std::endl;
            return;
        }
    }
    std::cout << "Movie not found or is already rented" << std::endl;
}

void Blockbuster::rentMovie()
{
    std::string movieCode;
    std::cout << "Enter movie code: ";
    std::cin >> movieCode;

    rentMovie(movieCode);
}

void Blockbuster::returnMovie(const std::string &movieCode)
{
    for (Movie &movie: rentedMovies)
    {
        if (movie.getMovieCode() == movieCode)
        {
            rentedMovies.remove(movie);
            movieStock.push_back(movie);
            std::cout << "Movie returned successfully" << std::endl;
            return;
        }
    }
    std::cout << "Movie not found or is not rented" << std::endl;
}

void Blockbuster::returnMovie()
{
    std::string movieCode;
    std::cout << "Enter movie code: ";
    std::cin >> movieCode;

    returnMovie(movieCode);
}

void Blockbuster::showMovieDetails(const std::string &movieCode)
{
    for (Movie &movie: movieStock)
    {
        if (movie.getMovieCode() == movieCode)
        {
            movie.printMovieDetails();
            return;
        }
    }

    std::cout << "Movie not found" << std::endl;
}

void Blockbuster::showMovieDetails()
{
    std::string movieCode;
    std::cout << "Enter movie code: ";
    std::cin >> movieCode;

    showMovieDetails(movieCode);
}

void Blockbuster::printMovieList()
{
    std::cout << std::left;
    std::cout << std::setw(15) << "Movie Code"
              << std::setw(20) << "Movie Title"
              << std::setw(15) << "Movie Genre"
              << std::setw(15) << "Year Released"
              << std::endl;
    for (auto &movie: movieStock)
    {
        movie.printMovieDetails();
    }
}

void Blockbuster::addMovie()
{
    int year;
    std::string code, title, genre;

    std::cout << "Enter the movie code: ";
    std::cin.ignore();
    std::getline(std::cin, code);

    std::cout << "Enter the movie title: ";
    std::getline(std::cin, title);

    std::cout << "Enter the movie genre: ";
    std::getline(std::cin, genre);

    std::cout << "Enter the movie year: ";
    std::cin >> year;

    Movie movie(code, title, genre, year);
    insertMovie(movie);
}

void Blockbuster::insertMovie(const Movie &movie)
{
    movieStock.push_back(movie);
}

Blockbuster::~Blockbuster()
{
    movieStock.clear();
}



