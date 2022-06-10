#include "movie.h"
#include "console.h"
#include <iostream>
#include <iomanip>
#include <utility>

void Movie::printMovieDetails(bool rented)
{
    SaveXY();
    std::cout << std::left;
    std::cout << std::setw(15) << getMovieCode()
              << std::setw(20) << getMovieTitle()
              << std::setw(15) << getMovieGenre()
              << std::setw(15) << getYearReleased()
              << std::setw(10) << std::boolalpha << rented;
    LoadXY();
    MoveCursor(CursorDirection::Down);
}

void Movie::printRentedMovieDetails()
{
  std::cout << std::left;
  std::cout << std::setw(15) << getMovieCode()
            << std::setw(20) << getMovieTitle();
}

Movie::Movie(std::string movieCode, std::string movieTitle, std::string movieGenre,std::string movieProduction,
             int movieCopies, int yearReleased, std::string movieImageFilename, bool movieAvailability):
    _movieCode(std::move(movieCode)), _movieTitle(std::move(movieTitle)),_movieGenre(std::move(movieGenre)), _movieProduction(std::move(movieProduction)),
    _movieCopies(movieCopies), _yearReleased(yearReleased), _movieImageFilename(std::move(movieImageFilename)), _movieAvailability(movieAvailability)
{
}

std::string Movie::getMovieCode()
{
    return _movieCode;
}

std::string Movie::getMovieTitle()
{
    return _movieTitle;
}

std::string Movie::getMovieGenre()
{
    return _movieGenre;
}

std::string Movie::getMovieProduction()
{
    return _movieProduction;
}

int Movie::getMovieCopies()
{
    return _movieCopies;
}

int Movie::getYearReleased() const
{
  return _yearReleased;
}

std::string Movie::getMovieImageFilename()
{
    return _movieImageFilename;
}

bool Movie::getMovieAvailability()
{
    return _movieAvailability;
}

void Movie::setMovieCode(std::string &movieCode)
{
    _movieCode = std::move(movieCode);
}

void Movie::setMovieTitle(std::string &movieTitle)
{
    _movieTitle = std::move(movieTitle);
}

void Movie::setMovieGenre(std::string &movieGenre)
{
    _movieGenre = std::move(movieGenre);
}

void Movie::setMovieProduction(std::string &movieProduction)
{
    _movieProduction = std::move(movieProduction);
}

void Movie::setMovieCopies(int movieCopies)
{
    _movieCopies = movieCopies;
}

void Movie::setYearReleased(int yearReleased)
{
    _yearReleased = yearReleased;
}

void Movie::setMovieImageFilename(std::string &movieImageFilename)
{
    _movieImageFilename = std::move(movieImageFilename);
}

void Movie::setMovieAvailability(bool &movieAvailability)
{
    _movieAvailability = movieAvailability;
}

bool Movie::operator==(const Movie &compare) const
{
    return _movieCode == compare._movieCode;
}

