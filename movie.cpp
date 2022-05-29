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
              << std::setw(15) << std::to_string(rented);
    LoadXY();
    MoveCursor(CursorDirection::Down);
}

Movie::Movie(std::string movieCode, std::string movieTitle,
             std::string movieGenre, int yearReleased) :
    _movieCode(std::move(movieCode)), _movieTitle(std::move(movieTitle)),
    _movieGenre(std::move(movieGenre)), _yearReleased(yearReleased)
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

int Movie::getYearReleased() const
{
    return _yearReleased;
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

void Movie::setYearReleased(int yearReleased)
{
    _yearReleased = yearReleased;
}

bool Movie::operator==(const Movie &compare) const
{
    return _movieCode == compare._movieCode;
}

