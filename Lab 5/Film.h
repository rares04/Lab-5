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

	void setTitel(string _titel);
	
	string getGenre() const;

	void setGenre(string _genre);

	string getTrailer() const;

	void setTrailer(string _trailer);

	double getJahr() const;
	
	void setJahr(double _jahr);

	double getLikes() const;

	void setLikes(double _likes);

	friend std::ostream& operator << (std::ostream& out, const Film& f);
};

