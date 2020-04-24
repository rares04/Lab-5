#pragma once
#include "Film.h"


class Tests {
public:
	// Testing Add Function from Repository
	void testAdd();

	// Testing Delete Function from Repository
	void testDelete();

	// Testing Update Function from Repository
	void testUpdate();

	// Testing Administrators functions
	void testAdministrator();

	// Testing User functions
    void testUser();

	// Tests the functions which returns a movie at a given index
	void test_getFilm_byIndex();

	// Tests the functions which searches for a movies by match and returns it
	void test_getFilm_byMatch(Film _film);

	// Tests if the functions returns the correct number of likes for the given movie
	void test_getLikes(Film _film) const;
};

