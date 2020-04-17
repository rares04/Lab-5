#include "Ui.h"
#include "Administrator.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Ui::ui(User user, Administrator admin) {
    User utilizator = user;
    Administrator administrator = admin;
    string mode = "Select Mode\n"
                  "\n1. For user\n"
                  "2. For admin";

    while(true) {
        string input;
        cout << mode;
        cout << "\nInput: "; cin >> input;
        if (input == "1") {
            utilizator = userActions(utilizator);
        }
        if (input == "2"){
            administrator = adminActions(administrator);
        }
        else{
            break;
        }
    }
}

User Ui::userActions(User user){

    User utilizator = user;
    string userActions = "1. To show and add movies by genre\n"
                         "2. To rate a movie and delete it\n"
                         "3. To show the watchList\n"
                         "4. To close\n";
    string input;
    while (true) {
        cout << "User Mode\n";
        cout << "\n" << userActions;
        cout << "\nInput: ";
        cin >> input;
        if (input == "1"){
            utilizator = filmGenre(utilizator);
        }
        else if (input == "2"){
            utilizator = deleteAndRate(utilizator);
        }
        else if (input == "3"){
            utilizator.showWatchList();
        }
        else if(input == "4"){
            break;
        }
        else{
            cout<<"invalid input\n";
        }
    }
    return utilizator;
}

User Ui::filmGenre(User user){
    int input;
    string next = "1.add to watchList\n"
                  "2.next\n"
                  "3.close\n";

    string genre = "";
    int index = 0;
    cout << "Type Genre:";
    cin >> genre;
    if(genre == "0") {
        user.getFilmRepo().showFilme();
    }
    vector <Film> filmeByGenre = user.getFilmRepo().showFilme_byGenre(genre, index);
    if(!filmeByGenre.empty()){
        cout << filmeByGenre[index];
        //system(std::string("start " + filmeByGenre[index].getTrailer()).c_str());
        while (true) {
            string input;
            cout << next;
            cin >> input;

            if (input == "1"){
                std::vector<Film> v = user.getWatchList();
                Film key = filmeByGenre[index];

                if (std::find(v.begin(), v.end(), key) != v.end()){
                    cout<< "It is already in the watchList\n";
                    break;
                }
                user.addFilmToWatchList(filmeByGenre[index]);
                index++;
                cout << "size: " << user.getWatchList().size() << "\n";
            }
            else if (input == "2") {
                if (index == filmeByGenre.size()-1){
                    break;
                }
                index++;
                cout << filmeByGenre[index];
                //system(std::string("start " + filmeByGenre[index].getTrailer()).c_str());

            }
            else if (input == "3") {
                break;
            }
            else{
                cout<<"Invalid input\n";
            }

 
        }
    }
    return user;
}

User Ui::deleteAndRate(User user){
    string title;
    cout << "Enter Title to delete: ";
    cin.ignore();
    getline(cin, title);
    std::vector<Film> v = user.getWatchList();
    Film key = Film("", "", 0, 0, "");
    for (int i = 0; i < user.getFilmRepo().getFilme().size(); i++) {  // Checking if the film exists
        if (title == user.getFilmRepo().getFilme()[i].getTitel()) {
            key = user.getFilmRepo().getFilme()[i];
            break;
        }
    }
    if (!(std::find(v.begin(), v.end(), key) != v.end())) {
        cout << "Is not in the watchList\n";
    } else{
        while(true){
            cout<<"Do you want to rate the film with a like?\n";
            string input;
            cout<<"1. Yes\n"
                  "2. Just delete\n"
                  "3. Cancel\n"
                  "Input: ";
            cin >> input;
            if(input == "1") {
                user.like(key);
                user.removeFilmFromWatchList(key);
                break;
            }
            else if (input == "2"){
                user.removeFilmFromWatchList(key);
                break;
            }
            else if(input == "3"){
                break;
            }
            else{
                cout<<"invalid input\n";
            }
        }
    }
    return user;
}

Administrator Ui::adminActions(Administrator admin){

    string adminActions = "1. To Add a film\n"
                          "2. To remove a film\n"
                          "3. To edit a film\n"
                          "4. To show all films\n"
                          "5. To close\n";
    while (true) {
        string input;
        cout << "Admin Mode\n";
        cout << "\n" << adminActions;
        cout << "\nInput: ";
        cin >> input;
        if (input == "1"){
            string title;
            string genre;
            double jahr;
            double likes;
            string trailer;
            cout<<"Enter Title: "; cin >> title;
            cout<<"Enter Genre: "; cin >> genre;
            cout<<"Enter Jahr: "; cin >> jahr;
            while(!cin) // or if(cin.fail())
            {
                // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                cout<<"Invalid input\n";
                cout<<"Enter Jahr: "; cin >> jahr;
            }
            cout<<"Enter Likes: "; cin >> likes;
            while(!cin) // or if(cin.fail())
            {
                // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                cout<<"Invalid input\n";
                cout<<"Enter Likes: "; cin >> likes;
            }
            cout<<"Enter Trailer: "; cin >> trailer;
            Film film = Film(title, genre, jahr, likes, trailer);
            admin.addFilm(film);
        }
        else if (input == "2") {
            string title;
            Film film = Film("", "", 0, 0, "");
            cout << "Enter Title to delete: ";
            cin.ignore();
            getline(cin, title);
            for (int i = 0; i < admin.getFilmRepo().getFilme().size(); i++){  // Checking if the film exists
                if (title == admin.getFilmRepo().getFilme()[i].getTitel()) {
                    film = admin.getFilmRepo().getFilme()[i];
                    break;
                }
            }
            if (film.getTitel() == "") {
                cout << "Film not found\n";
            } else{
                admin.deleteFilm(film);
            }

        }
        else if (input == "3"){
            string title;
            Film film = Film("","",0,0,"");
            cout<<"Enter Title to edit: ";cin.ignore(); getline(cin, title);
            for (int i = 0; i < admin.getFilmRepo().getFilme().size(); i++) {  // Checking if the film exists
                if (title == admin.getFilmRepo().getFilme()[i].getTitel()) {
                    film = admin.getFilmRepo().getFilme()[i];
                    break;
                }
            }
            if (film.getTitel() == "") {
                cout << "Film not found\n";

            }
            while (true) {
                string input2;
                cout << "What do you want to edit?\n";
                cout << "1. To edit title\n"
                        "2. To edit genre\n"
                        "3. To edit jahr\n"
                        "4. To edit likes\n"
                        "5. To edit Trailer\n"
                        "Input: ";
                cin >> input2;
                if (input2 == "1") {
                    string title2;
                    cout << "New Title: ";
                    cin.ignore();
                    getline(cin, title2);
                    admin.updateTitel(film, title2);
                    break;
                }
                else if (input2 == "2") {
                    string genre;
                    cout << "New Genre: ";
                    cin.ignore();
                    getline(cin, genre);
                    admin.updateGenre(film, genre);
                    break;
                }
                else if (input2 == "3") {
                    double jahr;
                    cout << "New Jahr: ";
                    cin >> jahr;
                    while(!cin) // or if(cin.fail())
                    {
                        // user didn't input a number
                        cin.clear(); // reset failbit
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                        cout<<"Invalid input\n";
                        cout<<"New Jahr: "; cin >> jahr;
                    }
                    admin.updateJahr(film, jahr);
                    break;
                }
                else if (input2 == "4") {
                    double likes;
                    cout << "Likes: ";
                    cin >> likes;
                    while(!cin) // or if(cin.fail())
                    {
                        // user didn't input a number
                        cin.clear(); // reset failbit
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                        cout<<"Invalid input\n";
                        cout<<"Likes: "; cin >> likes;
                    }
                    admin.updateLikes(film, likes);
                    break;
                }
                else if (input2 == "5") {
                    string trailer;
                    cout << "New Trailer: ";
                    cin.ignore();
                    getline(cin, trailer);
                    admin.updateTrailer(film, trailer);
                    break;
                }
                else{
                    cout<<"Invalid input\n";
                }
            }
        }
        else if (input == "4"){
            admin.showFilme();
        }
        else if(input == "5"){
            break;
        }
        else{
            cout<<"Invalid input\n";
        }
    }
    return admin;
}
