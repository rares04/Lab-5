#pragma once
#include "User.h"
#include "Administrator.h"
#include <vector>

using namespace std;

class Ui {

private:
    vector <User> userList;

public:
    void UI(vector <User> userList);
    void ui(User user, Administrator admin);
    User userActions(User user);
    Administrator adminActions(Administrator admin);
    User filmGenre(User user);
    User deleteAndRate(User user);
};