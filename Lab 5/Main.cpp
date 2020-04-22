#include "Tests.h"
#include "FilmRepository.h"
#include "Ui.h"
#include <iostream>

using std::cout;

int main() {
	Tests t;
	t.testAdd();
	t.testDelete();
	t.testUpdate();
	t.testAdministrator();
	t.testUser();
    cout << "\nTest End\n\n";

	// The list starts with 10 movies already added
    Film f1("The Platform", "Thriller", 2019, 76190, "https://www.youtube.com/watch?v=RlfooqeZcdY");
    Film f2("The Maze Runner", "Action", 2014, 401481, "https://www.youtube.com/watch?v=AwwbhhjQ9Xk");
    Film f3("Zodiac", "Crime", 2007, 424385, "https://www.youtube.com/watch?v=yNncHPl1UXg");
    Film f4("Shutter Island", "Mystery", 2010, 1065137, "https://www.youtube.com/watch?v=5iaYLCiq5RM");
    Film f5("Se7en", "Crime", 1995, 1364614, "https://www.youtube.com/watch?v=znmZoVkCjpI");
    Film f6("Inception", "Action", 2010, 5, "https://www.youtube.com/watch?v=YoHD9XEInc0");
    Film f7("Joker", "Drama", 2019, 9, "https://www.youtube.com/watch?v=rgXplohCw5o");
    Film f8("Avengers: Endgame", "Action", 2019, 15, "https://www.youtube.com/watch?v=TcMBFSGVi1c");
    Film f9("The Wolf of Wall Street", "Biography", 2013, 7, "https://www.youtube.com/watch?v=iszwuX1AK6A");
    Film f10("Suicide Squad", "Action", 2016, 9, "https://www.youtube.com/watch?v=CmRih_VtVAs");

	FilmRepository filmRepo;
	filmRepo.addFilm(f1);
	filmRepo.addFilm(f2);
	filmRepo.addFilm(f3);
	filmRepo.addFilm(f4);
	filmRepo.addFilm(f5);
	filmRepo.addFilm(f6);
	filmRepo.addFilm(f7);
	filmRepo.addFilm(f8);
	filmRepo.addFilm(f9);
	filmRepo.addFilm(f10);

    User user = User(filmRepo);
    Administrator admin = Administrator(filmRepo);

	// User starts with 2 films in the watchlist
    user.addFilmToWatchList(f1);
    user.addFilmToWatchList(f2);


	Ui a(admin, user);
	a.ui_main();
}