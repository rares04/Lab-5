#include "Administrator.h"


void Administrator::addFilm(Film _film) {
	FilmRepo.addFilm(_film);
}


void Administrator::updateTitel(Film _film, string _titel) {
	FilmRepo.updateTitel(_film, _titel);
}


void Administrator::updateGenre(Film _film, string _genre) {
	FilmRepo.updateGenre(_film, _genre);
}


void Administrator::updateJahr(Film _film, double _jahr) {
	FilmRepo.updateJahr(_film, _jahr);
}


void Administrator::updateLikes(Film _film, double _likes) {
	FilmRepo.updateLikes(_film, _likes);
}


void Administrator::updateTrailer(Film _film, string _trailer) {
	FilmRepo.updateTrailer(_film, _trailer);
}


void Administrator::deleteFilm(Film _film) {
	FilmRepo.deleteFilm(_film);
}


void Administrator::showFilme() const {
	FilmRepo.showFilme();
}