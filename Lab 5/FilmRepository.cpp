#include "FilmRepository.h"
#include <iostream>
#include <vector>

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
	for (int i = 0; i < Filme.size(); i++)  // Goes trough all the vector and outputs the films (<< Operator wurde uberladen)
		cout << Filme[i];
}


std::vector<Film> FilmRepository::getFilme() const {
	return Filme;
}


Film FilmRepository::getFilm_byIndex(int index) const {
	return Filme[index];
}


Film FilmRepository::getFilm_byMatch(Film _film) const {
	for (int i = 0; i < Filme.size(); i++)   // Searches for the film in the list with movies, return the films if found
		if (Filme[i] == _film)
			return Filme[i];
}


std::vector<Film> FilmRepository::showFilme_byGenre(string _genre, int index) const{
    std::vector <Film> filmByGenre;  // A list with movies that have the specified Genre
    for(int i = 0; i < Filme.size(); i++) {   // Searches for movies with the specified _genre and adds them to a list 
        if (Filme[i].getGenre() == _genre)
            filmByGenre.push_back(Filme[i]);
    }
//    if(!filmByGenre.empty()) {
//        cout << filmByGenre[index];
//        system(std::string("start " + filmByGenre[index].getTrailer()).c_str());
//        return filmByGenre[index];
//    }
    return filmByGenre; 
}


double FilmRepository::getLikes(Film _film) const{
    for(int i = 0; i < Filme.size(); i++)  // Searches for the movie given as parameter and returns the number of likes
        if(_film.getTitel() == Filme[i].getTitel() && _film.getJahr() == Filme[i].getJahr())
            return _film.getLikes();
    return 0;
}