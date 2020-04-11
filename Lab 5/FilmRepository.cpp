#include "FilmRepository.h"
#include <iostream>

using std::cout;


void FilmRepository::addFilm(Film _film) {
	bool found = false;
	for (int i = 0; i < Filme.size() && found == false; i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr())
			found = true;

	if (found == true)  // If the film does exist -> Error message
		cout << "\tFilm " << _film.getTitel() << " existiert schon, nichts wird eingefugt\n";
	else  // If the film does not exist -> Add it
		Filme.push_back(_film);
}


void FilmRepository::updateTitel(Film _film, string _titel) {
	for (int i = 0; i < Filme.size(); i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr()) {
			// If the film does exist -> Update
			Filme[i].setTitel(_titel);
			return;
		}
}


void FilmRepository::updateGenre(Film _film, string _genre) {
	for (int i = 0; i < Filme.size(); i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr()) {
			// If the film does exist -> Update
			Filme[i].setGenre(_genre);
			return;
		}
}


void FilmRepository::updateJahr(Film _film, double _jahr) {
	for (int i = 0; i < Filme.size(); i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr()) {
			// If the film does exist -> Update
			Filme[i].setJahr(_jahr);
			return;
		}
}


void FilmRepository::updateLikes(Film _film, double _likes) {
	for (int i = 0; i < Filme.size(); i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr()) {
			// If the film does exist -> Update
			Filme[i].setLikes(_likes);
			return;
		}
}


void FilmRepository::updateTrailer(Film _film, string _trailer) {
	for (int i = 0; i < Filme.size(); i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr()) {
			// If the film does exist -> Update
			Filme[i].setTrailer(_trailer);
			return;
		}
}


void FilmRepository::deleteFilm(Film _film) {
	bool found = false;
	for (int i = 0; i < Filme.size() && found == false; i++)  // Checking if the film exists
		if (_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr()) {
			// If the film does exist -> Delete
			found = true;
			Filme.erase(Filme.begin() + i);
			return;
		}
	
	// If the film does not exist -> Error message
	cout << "\tFilm " << _film.getTitel() << " existiert nicht, nichts wird geloscht\n";
}


void FilmRepository::showFilme() const {
	for (int i = 0; i < Filme.size(); i++)
		cout << Filme[i];
}


std::vector<Film> FilmRepository::getFilme() const {
	return Filme;
}


Film FilmRepository::getFilm_byIndex(int index) const {
	return Filme[index];
}

void FilmRepository::showFilme_byGenre(string _genre, Film _film) const{
    for(int i = 0; i < Filme.size(); i++) {
        if (_film.getGenre() == _genre)
            cout << Filme[i];
    }
}

double FilmRepository::getLikes(Film _film) const{
    for(int i = 0; i < Filme.size(); i++)
        if(_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr())
            return _film.getLikes();
    return 0;
}