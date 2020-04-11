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

    std::vector <Film> getWatchList() const;

    void setWatchList(vector <Film> list) ;

    void addFilmToWatchList(Film _film);

    void removeFilmFromWatchList(Film _film);

    void showWatchList() const;

    void like(Film _film);

    // Returns the adress of the FilmRepository attribute
    FilmRepository& getFilmRepo();
};