#include "Tests.h"
#include "Administrator.h"
#include <cassert>
#include <iostream>

using std::cout;


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
	
	assert(repo.getFilme().size() == 5);

	assert(repo.getFilm_byIndex(0).getTitel() == "The Platform");
	assert(repo.getFilm_byIndex(0).getGenre() == "Horror, Sci-Fi, Thriller");
	assert(repo.getFilm_byIndex(0).getJahr() == 2019);
	assert(repo.getFilm_byIndex(0).getLikes() == 76190);
	assert(repo.getFilm_byIndex(0).getTrailer() == "https://www.youtube.com/watch?v=RlfooqeZcdY");

	assert(repo.getFilm_byIndex(1).getTitel() == "The Maze Runner");
	assert(repo.getFilm_byIndex(1).getGenre() == "Action, Mysterym, Sci-Fi");
	assert(repo.getFilm_byIndex(1).getJahr() == 2014);
	assert(repo.getFilm_byIndex(1).getLikes() == 401481);
	assert(repo.getFilm_byIndex(1).getTrailer() == "https://www.youtube.com/watch?v=AwwbhhjQ9Xk");

	assert(repo.getFilm_byIndex(2).getTitel() == "Zodiac");
	assert(repo.getFilm_byIndex(2).getGenre() == "Crime, Drama, Mystery");
	assert(repo.getFilm_byIndex(2).getJahr() == 2007);
	assert(repo.getFilm_byIndex(2).getLikes() == 424385);
	assert(repo.getFilm_byIndex(2).getTrailer() == "https://www.youtube.com/watch?v=yNncHPl1UXg");

	assert(repo.getFilm_byIndex(3).getTitel() == "Shutter Island");
	assert(repo.getFilm_byIndex(3).getGenre() == "Mystery, Thriller");
	assert(repo.getFilm_byIndex(3).getJahr() == 2010);
	assert(repo.getFilm_byIndex(3).getLikes() == 1065137);
	assert(repo.getFilm_byIndex(3).getTrailer() == "https://www.youtube.com/watch?v=5iaYLCiq5RM");

	assert(repo.getFilm_byIndex(4).getTitel() == "Se7en");
	assert(repo.getFilm_byIndex(4).getGenre() == "Crime, Drama, Mystery");
	assert(repo.getFilm_byIndex(4).getJahr() == 1995);
	assert(repo.getFilm_byIndex(4).getLikes() == 1364614);
	assert(repo.getFilm_byIndex(4).getTrailer() == "https://www.youtube.com/watch?v=znmZoVkCjpI");


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

	assert(repo.getFilme().size() == 2);

	assert(repo.getFilm_byIndex(0).getTitel() == "The Maze Runner");
	assert(repo.getFilm_byIndex(0).getGenre() == "Action, Mysterym, Sci-Fi");
	assert(repo.getFilm_byIndex(0).getJahr() == 2014);
	assert(repo.getFilm_byIndex(0).getLikes() == 401481);
	assert(repo.getFilm_byIndex(0).getTrailer() == "https://www.youtube.com/watch?v=AwwbhhjQ9Xk");

	assert(repo.getFilm_byIndex(1).getTitel() == "Shutter Island");
	assert(repo.getFilm_byIndex(1).getGenre() == "Mystery, Thriller");
	assert(repo.getFilm_byIndex(1).getJahr() == 2010);
	assert(repo.getFilm_byIndex(1).getLikes() == 1065137);
	assert(repo.getFilm_byIndex(1).getTrailer() == "https://www.youtube.com/watch?v=5iaYLCiq5RM");


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

	assert(admin.getFilmRepo().getFilme().size() == 5);

	assert(admin.getFilmRepo().getFilm_byIndex(0).getTitel() == "The Platform");
	assert(admin.getFilmRepo().getFilm_byIndex(0).getGenre() == "Horror, Sci-Fi, Thriller");
	assert(admin.getFilmRepo().getFilm_byIndex(0).getJahr() == 2019);
	assert(admin.getFilmRepo().getFilm_byIndex(0).getLikes() == 76190);
	assert(admin.getFilmRepo().getFilm_byIndex(0).getTrailer() == "https://www.youtube.com/watch?v=RlfooqeZcdY");

	assert(admin.getFilmRepo().getFilm_byIndex(1).getTitel() == "The Maze Runner");
	assert(admin.getFilmRepo().getFilm_byIndex(1).getGenre() == "Action, Mysterym, Sci-Fi");
	assert(admin.getFilmRepo().getFilm_byIndex(1).getJahr() == 2014);
	assert(admin.getFilmRepo().getFilm_byIndex(1).getLikes() == 401481);
	assert(admin.getFilmRepo().getFilm_byIndex(1).getTrailer() == "https://www.youtube.com/watch?v=AwwbhhjQ9Xk");

	assert(admin.getFilmRepo().getFilm_byIndex(2).getTitel() == "Zodiac");
	assert(admin.getFilmRepo().getFilm_byIndex(2).getGenre() == "Crime, Drama, Mystery");
	assert(admin.getFilmRepo().getFilm_byIndex(2).getJahr() == 2007);
	assert(admin.getFilmRepo().getFilm_byIndex(2).getLikes() == 424385);
	assert(admin.getFilmRepo().getFilm_byIndex(2).getTrailer() == "https://www.youtube.com/watch?v=yNncHPl1UXg");

	assert(admin.getFilmRepo().getFilm_byIndex(3).getTitel() == "Shutter Island");
	assert(admin.getFilmRepo().getFilm_byIndex(3).getGenre() == "Mystery, Thriller");
	assert(admin.getFilmRepo().getFilm_byIndex(3).getJahr() == 2010);
	assert(admin.getFilmRepo().getFilm_byIndex(3).getLikes() == 1065137);
	assert(admin.getFilmRepo().getFilm_byIndex(3).getTrailer() == "https://www.youtube.com/watch?v=5iaYLCiq5RM");

	assert(admin.getFilmRepo().getFilm_byIndex(4).getTitel() == "Se7en");
	assert(admin.getFilmRepo().getFilm_byIndex(4).getGenre() == "Crime, Drama, Mystery");
	assert(admin.getFilmRepo().getFilm_byIndex(4).getJahr() == 1995);
	assert(admin.getFilmRepo().getFilm_byIndex(4).getLikes() == 1364614);
	assert(admin.getFilmRepo().getFilm_byIndex(4).getTrailer() == "https://www.youtube.com/watch?v=znmZoVkCjpI");

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

	assert(admin2.getFilmRepo().getFilme().size() == 2);

	assert(admin2.getFilmRepo().getFilm_byIndex(0).getTitel() == "The Maze Runner");
	assert(admin2.getFilmRepo().getFilm_byIndex(0).getGenre() == "Action, Mysterym, Sci-Fi");
	assert(admin2.getFilmRepo().getFilm_byIndex(0).getJahr() == 2014);
	assert(admin2.getFilmRepo().getFilm_byIndex(0).getLikes() == 401481);
	assert(admin2.getFilmRepo().getFilm_byIndex(0).getTrailer() == "https://www.youtube.com/watch?v=AwwbhhjQ9Xk");

	assert(admin2.getFilmRepo().getFilm_byIndex(1).getTitel() == "Shutter Island");
	assert(admin2.getFilmRepo().getFilm_byIndex(1).getGenre() == "Mystery, Thriller");
	assert(admin2.getFilmRepo().getFilm_byIndex(1).getJahr() == 2010);
	assert(admin2.getFilmRepo().getFilm_byIndex(1).getLikes() == 1065137);
	assert(admin2.getFilmRepo().getFilm_byIndex(1).getTrailer() == "https://www.youtube.com/watch?v=5iaYLCiq5RM");


	// Testing Delete for Administrator - Checking the output of the function when deleting a non existent movie
	admin2.getFilmRepo().deleteFilm(f1);
}