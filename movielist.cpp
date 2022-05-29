#include "movielist.h"
#include "console.h"
#include <iostream>
#include <iomanip>

void Box(COORD coord, int length = 4)
{
    system("clear");
    XY(coord);
    WriteLine("╔════════════════════════════════════════════════════════════════════════════╗");
    for (int i = 0; i < length; ++i)
    {
        WriteLine("║                                                                            ║");
    }
    WriteLine("╚════════════════════════════════════════════════════════════════════════════╝");
    XY(coord.X + 2, coord.Y + 1);
}

void printHeader()
{
    SaveXY();
    std::cout << std::left;
    std::cout << std::setw(15) << "Movie Code"
              << std::setw(20) << "Movie Title"
              << std::setw(15) << "Movie Genre"
              << std::setw(15) << "Year Released"
              << std::setw(10) << "Is Rented";
    LoadXY();
    MoveCursor(CursorDirection::Down);
}

void Blockbuster::rentMovie(const std::string &movieCode)
{
    for (auto &movie: movieStock)
    {
        if (movie.getMovieCode() == movieCode)
        {
            movieStock.remove(movie);
            rentedMovies.push_back(movie);
            WriteLine("Movie rented successfully");
            return;
        }
    }
    WriteLine("Movie not found or is already rented");
}

void Blockbuster::rentMovie()
{
    Box({7, 1});
    std::string movieCode = Prompt<std::string>("Enter movie code: ");
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
            WriteLine("Movie returned successfully");
            return;
        }
    }
    WriteLine("Movie not found or is not rented");
}

void Blockbuster::returnMovie()
{
    Box({7, 1});
    std::string movieCode = Prompt<std::string>("Enter movie code: ");
    returnMovie(movieCode);
}

void Blockbuster::showMovieDetails(const std::string &movieCode)
{
    for (Movie &movie: movieStock)
    {
        if (movie.getMovieCode() == movieCode)
        {
            movie.printMovieDetails(false);
            return;
        }
    }

    std::cout << "Movie not found" << std::endl;
}

void Blockbuster::showMovieDetails()
{
    Box({7, 1});
    std::string movieCode = Prompt<std::string>("Enter movie code: ");
    printHeader();
    showMovieDetails(movieCode);
}

void Blockbuster::printMovieList()
{
    Box({7, 1}, 10);
    printHeader();
    for (auto &movie: movieStock)
    {
        movie.printMovieDetails(false);
    }
    for (auto &movie: rentedMovies)
    {
        movie.printMovieDetails(true);
    }
}

void Blockbuster::addMovie()
{
    Box({7, 1});

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



