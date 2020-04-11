#pragma once
#include "Film.h"
#include <vector>


class FilmRepository {
private:
	std::vector <Film> Filme;
public:
	void addFilm(Film);

	void updateTitel(Film, string);

	void updateGenre(Film, string);

	void updateJahr(Film, double);

	void updateLikes(Film, double);

	void updateTrailer(Film, string);

	void deleteFilm(Film);

	void showFilme() const;

	std::vector<Film> getFilme() const;

	Film getFilm_byIndex(int index) const;
};

