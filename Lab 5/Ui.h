#pragma once
#include "User.h"
#include "Administrator.h"
#include <vector>

using namespace std;

class Ui {

private:
    vector <User> userList;
    Administrator admin;
    User user;
public:
    Ui(Administrator _admin, User _user);
    void ui_main();
    User userActions();
    Administrator adminActions();
    User filmGenre();
    User deleteAndRate();
};