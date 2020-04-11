#include "FilmRepository.h"
#include <iostream>

using std::cout;


void FilmRepository::addFilm(Film _film) {
	bool found = false;
	for (int i = 0; i < Filme.size() && found == false; i++)
		if (_film.getTrailer() == Filme[i].getTrailer())
			found = true;

	if (found == true)
		cout << "\n\tFilm existiert schon, nichts wird eingefugt\n";
	else
		Filme.push_back(_film);
}


void FilmRepository::updateTitel(Film _film, string _titel) {
	for (int i = 0; i < Filme.size(); i++)
		if (_film.getTrailer() == Filme[i].getTrailer()) {
			Filme[i].setTitel(_titel);
			return;
		}
}


void FilmRepository::updateGenre(Film _film, string _genre) {
	for (int i = 0; i < Filme.size(); i++)
		if (_film.getTrailer() == Filme[i].getTrailer()) {
			Filme[i].setGenre(_genre);
			return;
		}
}


void FilmRepository::updateJahr(Film _film, double _jahr) {
	for (int i = 0; i < Filme.size(); i++)
		if (_film.getTrailer() == Filme[i].getTrailer()) {
			Filme[i].setJahr(_jahr);
			return;
		}
}


void FilmRepository::updateLikes(Film _film, double _likes) {
	for (int i = 0; i < Filme.size(); i++)
		if (_film.getTrailer() == Filme[i].getTrailer()) {
			Filme[i].setLikes(_likes);
			return;
		}
}


void FilmRepository::updateTrailer(Film _film, string _trailer) {
	for (int i = 0; i < Filme.size(); i++)
		if (_film.getTrailer() == Filme[i].getTrailer()) {
			Filme[i].setTrailer(_trailer);
			return;
		}
}


void FilmRepository::deleteFilm(Film _film) {
	bool found = false;
	for (int i = 0; i < Filme.size() && found == false; i++)
		if (_film.getTrailer() == Filme[i].getTrailer()) {
			found = true;
			Filme.erase(Filme.begin() + i);
			return;
		}

	cout << "\n\tFilm existiert nicht, nichts wird geloscht\n";
}


void FilmRepository::showFilme() const {
	for (int i = 0; i < Filme.size(); i++)
		cout << Filme[i];
}