#include "Tests.h"
#include "Administrator.h"
#include <cassert>
#include <iostream>

using std::cout;

// Movies on which the app will be tested
Film f1("The Platform", "Horror, Sci-Fi, Thriller", 2019, 76190, "https://www.youtube.com/watch?v=RlfooqeZcdY");
Film f2("The Maze Runner", "Action, Mysterym, Sci-Fi", 2014, 401481, "https://www.youtube.com/watch?v=AwwbhhjQ9Xk");
Film f3("Zodiac", "Crime, Drama, Mystery", 2007, 424385, "https://www.youtube.com/watch?v=yNncHPl1UXg");
Film f4("Shutter Island", "Mystery, Thriller", 2010, 1065137, "https://www.youtube.com/watch?v=5iaYLCiq5RM");
Film f5("Se7en", "Crime, Drama, Mystery", 1995, 1364614, "https://www.youtube.com/watch?v=znmZoVkCjpI");

void Tests::testAdd() {
	cout << "Test Add\n";

	FilmRepository repo;

	repo.addFilm(f1);
	repo.addFilm(f2);
	repo.addFilm(f3);
	repo.addFilm(f4);
	repo.addFilm(f5);
	
	// There should be 5 movies in the list now
	assert(repo.getFilme().size() == 5);

	// Checking from each film from the list, that it's the same with the created one
	assert(repo.getFilm_byIndex(0) == f1);
	assert(repo.getFilm_byIndex(1) == f2);
	assert(repo.getFilm_byIndex(2) == f3);
	assert(repo.getFilm_byIndex(3) == f4);
	assert(repo.getFilm_byIndex(4) == f5);

	// Testing Add - Checking the output of the function when same film will be added
	repo.addFilm(f1);
	repo.addFilm(f2);
	repo.addFilm(f3);
	repo.addFilm(f4);
	repo.addFilm(f5);
}


void Tests::testDelete() {
	cout << "\nTest Delete\n";
	
	FilmRepository repo;

	repo.addFilm(f1);
	repo.addFilm(f2);
	repo.addFilm(f3);
	repo.addFilm(f4);
	repo.addFilm(f5);

	repo.deleteFilm(f1);
	repo.deleteFilm(f3);
	repo.deleteFilm(f5);

	// There should be 2 movies in the list now
	assert(repo.getFilme().size() == 2);

	assert(repo.getFilm_byIndex(0) == f2);
	assert(repo.getFilm_byIndex(1) == f4);

	// Testing Delete - Checking the output of the function when deleting a non existent movie
	repo.deleteFilm(f1);
	repo.deleteFilm(f2);
	repo.deleteFilm(f3);
}


void Tests::testUpdate() {
	cout << "\nTest Update\n";
	
	FilmRepository repo;

	repo.addFilm(f1);
	repo.addFilm(f2);
	repo.addFilm(f3);
	repo.addFilm(f4);
	repo.addFilm(f5);

	// Updateing something from each film and then checking 
	repo.updateTitel(f1, "New Titel");
	assert(repo.getFilm_byIndex(0).getTitel() == "New Titel");

	repo.updateGenre(f2, "New Genre");
	assert(repo.getFilm_byIndex(1).getGenre() == "New Genre");

	repo.updateJahr(f3, 3020);
	assert(repo.getFilm_byIndex(2).getJahr() == 3020);

	repo.updateLikes(f4, 10);
	assert(repo.getFilm_byIndex(3).getLikes() == 10);

	repo.updateTrailer(f5, "New Trailer");
	assert(repo.getFilm_byIndex(4).getTrailer() == "New Trailer");

	// Testing Update - Checking that no error will be given when trying to update inexistent movie
	repo.deleteFilm(f1);
	repo.updateTitel(f1, "New new Titel");
	repo.updateGenre(f1, "New new Genre");
	repo.updateJahr(f1, 4020);
	repo.updateLikes(f1, 20);
	repo.updateTrailer(f1, "New new Trailer");
}


void Tests::testAdministrator() {
	cout << "\nTest Administrator\n";
	
	Administrator admin;

	// Testing Add for Administrator
	admin.addFilm(f1);
	admin.addFilm(f2);
	admin.addFilm(f3);
	admin.addFilm(f4);
	admin.addFilm(f5);

	// There should be 5 movies in the list now
	assert(admin.getFilmRepo().getFilme().size() == 5);

	assert(admin.getFilmRepo().getFilm_byIndex(0) == f1);
	assert(admin.getFilmRepo().getFilm_byIndex(1) == f2);
	assert(admin.getFilmRepo().getFilm_byIndex(2) == f3);
	assert(admin.getFilmRepo().getFilm_byIndex(3) == f4);
	assert(admin.getFilmRepo().getFilm_byIndex(4) == f5);

	// Testing Add for Administrator - Checking the output of the function when same film will be added
	admin.addFilm(f1);
	admin.addFilm(f2);
	admin.addFilm(f3);
	admin.addFilm(f4);
	admin.addFilm(f5);


	// Testing Update for Administrator
	admin.getFilmRepo().updateTitel(f1, "New Titel");
	assert(admin.getFilmRepo().getFilm_byIndex(0).getTitel() == "New Titel");

	admin.getFilmRepo().updateGenre(f2, "New Genre");
	assert(admin.getFilmRepo().getFilm_byIndex(1).getGenre() == "New Genre");

	admin.getFilmRepo().updateJahr(f3, 3020);
	assert(admin.getFilmRepo().getFilm_byIndex(2).getJahr() == 3020);

	admin.getFilmRepo().updateLikes(f4, 10);
	assert(admin.getFilmRepo().getFilm_byIndex(3).getLikes() == 10);

	admin.getFilmRepo().updateTrailer(f5, "New Trailer");
	assert(admin.getFilmRepo().getFilm_byIndex(4).getTrailer() == "New Trailer");


	// Testing Update for Administrator - Checking that no error will be given when trying to update inexistent movie
	Administrator admin2;
	admin2.addFilm(f1);
	admin2.addFilm(f2);
	admin2.addFilm(f3);
	admin2.addFilm(f4);
	admin2.addFilm(f5);

	admin2.getFilmRepo().deleteFilm(f1);
	admin2.getFilmRepo().updateTitel(f1, "New new Titel");
	admin2.getFilmRepo().updateGenre(f1, "New new Genre");
	admin2.getFilmRepo().updateJahr(f1, 4020);
	admin2.getFilmRepo().updateLikes(f1, 20);
	admin2.getFilmRepo().updateTrailer(f1, "New new Trailer");


	// Testing Delete for Administrator
	admin2.getFilmRepo().deleteFilm(f3);
	admin2.getFilmRepo().deleteFilm(f5);

	// There should be 2 movies in the list now
	assert(admin2.getFilmRepo().getFilme().size() == 2);

	assert(admin2.getFilmRepo().getFilm_byIndex(0) == f2);
	assert(admin2.getFilmRepo().getFilm_byIndex(1) == f4);


	// Testing Delete for Administrator - Checking the output of the function when deleting a non existent movie
	admin2.getFilmRepo().deleteFilm(f1);
}