#include "movielist.h"
#include "console.h"
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

void Box(COORD coord)
{
    XY(coord);
    WriteLine("╔════════════════════════════════════════════════════════════════════════════╗");
    WriteLine("║                                                                            ║");
    WriteLine("║                                                                            ║");
    WriteLine("║                                                                            ║");
    WriteLine("║                                                                            ║");
    WriteLine("╚════════════════════════════════════════════════════════════════════════════╝");
    XY(coord.X + 2, coord.Y + 1);
}

void Blockbuster::addMovie()
{
    Box({20, 0});

    std::string code = Prompt<std::string>("Enter the movie code");
    std::string title = Prompt<std::string>("Enter the movie title");
    std::string genre = Prompt<std::string>("Enter the movie genre");
    int year = Prompt<int>("Enter the movie year");
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



