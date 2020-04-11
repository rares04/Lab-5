#pragma once
#include "FilmRepository.h"


class Administrator {
private:
	FilmRepository FilmRepo;
public:
	void addFilm(Film);

	void updateTitel(Film, string);

	void updateGenre(Film, string);

	void updateJahr(Film, double);

	void updateLikes(Film, double);

	void updateTrailer(Film, string);

	void deleteFilm(Film);

	void showFilme() const;
};

