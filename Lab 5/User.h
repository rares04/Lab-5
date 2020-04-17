#pragma once
#include<iostream>
#include <vector>
#include "Film.h"
#include "FilmRepository.h"

using namespace std;

class User {
private:
    vector <Film> watchList;
    FilmRepository filmRepo;
public:
    User(FilmRepository FilmRepo);

    // Return the watchList
    std::vector <Film> getWatchList() const;

    // Sets the watchList
    void setWatchList(vector <Film> list) ;

    // Adds a film to the watchList
    void addFilmToWatchList(Film _film);

    // Removes a film from the watchList
    void removeFilmFromWatchList(Film _film);

    // Prints the watchList
    void showWatchList() const;

    // Adds 1 like to the film
    void like(Film _film);

    // Returns the adress of the FilmRepository attribute
    FilmRepository& getFilmRepo();
};