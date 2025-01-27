/*
  CH-230-A
  a12_p3.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include "TournamentMember.h"
#include <iostream>

using namespace std;

char TournamentMember::location[30] = "Locker room"; // static for all players

void TournamentMember::print() const // print function
{
    std::string marriagereturn;
    if (getmarriagestatus() == true)
        marriagereturn = "yes";
    else
        marriagereturn = "no";

    cout << "The player name is: " << firstName << " " << lastName << endl;
    cout << "The player date of birth: " << dateofbirth << endl;
    cout << "Current location of player: " << location << endl;
    cout << "Is player married: " << marriagereturn << endl;
    cout << "The player number: " << playerNumber << endl;
    cout << endl;
}

TournamentMember::TournamentMember()
{
    cout << "default constructor called" << endl;
    
    strcpy(firstName,"--empty--");
    strcpy(lastName,"");
    strcpy(location,"none");
    string marriagereturn;
    if (getmarriagestatus() == true)
        marriagereturn = "yes";
    else
        marriagereturn = "no";
    playerNumber = 0;
}

TournamentMember::TournamentMember(const char *firstname, const char *lastname, const char *dob, bool ms, int pn, const char *loc) : TournamentMember(firstname, lastname, dob, ms, pn)
{
    cout << "parametric constructor 1 called" << endl
              << endl;

    strcpy(location, loc);
}

TournamentMember::TournamentMember(const char *firstname, const char *lastname, const char *dob, bool ms, int pn)
{

    cout << "parametric constructor 2 called" << endl
              << endl;

    strcpy(firstName, firstname);
    strcpy(lastName, lastname);
    strcpy(dateofbirth, dob);
    isMarried = ms;
    playerNumber = pn;
}

TournamentMember::TournamentMember(const TournamentMember &other) // copy constructor
{
    cout << endl;
    cout << "copy constructor called" << endl
              << endl;

    strcpy(firstName, other.firstName);
    strcpy(lastName, other.lastName);
    strcpy(dateofbirth, other.dateofbirth);
    isMarried = other.isMarried;
    playerNumber = other.playerNumber;
}


Player::Player() : TournamentMember()
{
    cout << "player default constructor called" << endl;
    Number = 0;
    Position = "-empty-";
    NumOfGoals = 0;
    isLeftFooted = false;
}

Player::Player(const Player &other) : TournamentMember(other)
{
    cout << "player copy constructor called" << endl;
    Number = other.Number;
    Position = other.Position;
    NumOfGoals = other.NumOfGoals;
    isLeftFooted = other.isLeftFooted;
}

Player::Player(const char *firstname,const char *lastname,const char *dob,bool ms,
                int pn,const char *loc,int number,const std::string &pos,
                bool leftfoot) 
        : TournamentMember(firstname,lastname,dob,ms,pn,loc)
{
    cout << "player parametric constructor called" << endl;
    Number = number;
    Position = pos;
    isLeftFooted = leftfoot;
}

void Player::IncrementGoals()
{
    NumOfGoals++;
}

void Player::printPlayer() const
{
    TournamentMember::print();
    cout << "Number: " << Number << endl;
    cout << "Position: " << Position << endl;
    cout << "goals scored: " << NumOfGoals << endl;
    cout << "is player left footed: " << (isLeftFooted ? "Yes" : "No") << endl; 
    cout << endl << endl;
}







