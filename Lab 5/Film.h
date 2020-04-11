#pragma once
#include <string>
#include <iostream>

using std::string;


class Film {
private:
	string Titel, Genre, Trailer;
	double Jahr, Likes;
public:
	// Constructor
	Film(string, string, double, double, string);

	string getTitel() const;

	string setTitel(string _titel);

	string getGenre() const;

	string setGenre(string _genre);

	string getTrailer() const;

	string setTrailer(string _trailer);

	double getJahr() const;
	
	double setJahr(double _jahr);

	double getLikes() const;

	double setLikes(double _likes);

	friend std::ostream& operator << (std::ostream& out, const Film& f);
};

