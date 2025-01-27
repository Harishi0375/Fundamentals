/*
  CH-230-A
  a12_p3.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#ifndef TOURNAMENTMEMBER_H
#define TOURNAMENTMEMBER_H

#include <cstring>
#include <iostream>

class TournamentMember
{
private:
    char firstName[36]; // including '\0'
    char lastName[36];  // including '\0'
    char dateofbirth[11];
    static char location[30]; // random location

    bool isMarried;
    int playerNumber;

public:
    TournamentMember();
    TournamentMember(const TournamentMember &other);
    TournamentMember(const char *firstname, const char *lastname, const char *dob, bool ms, int pn, const char *loc);
    TournamentMember(const char *firstname, const char *lastname, const char *dob, bool ms, int pn);
    ~TournamentMember() { std::cout << "destructor called" << std::endl
                                    << std::endl; };

    // using inline
    inline void setfirstname(const char *firstname) { strcpy(firstName, firstname); }
    inline const char *getfirstname() const { return firstName; }

    inline void setlastname(const char *lastname) { strcpy(lastName, lastname); }
    inline const char *getlastname() const { return lastName; }

    inline void setdob(const char *dob) { strcpy(dateofbirth, dob); }
    inline const char *getdob() const { return dateofbirth; }

    inline void setmarriagestatus(const bool ms) { isMarried = ms; }
    inline const bool getmarriagestatus() const { return isMarried; }

    inline void setplayernumber(const int pn) { playerNumber = pn; }
    inline const int getplayernumber() const { return playerNumber; }

    inline static void setlocation(const char *loc) { strcpy(location, loc); }
    inline static const char *getlocation() { return location; }

    inline static void changelocation(const char *newloc)
    {
        strcpy(location, newloc);
        std::cout << std::endl;
        std::cout << "location changed" << std::endl;
        std::cout << std::endl;
    }
    void print() const;
};


class Player : public TournamentMember
{
    private:
        int Number; //in my TournamentMember class I have player number already
                    // hence this number would not be used for player number but something random
        std::string Position;
        int NumOfGoals;
        bool isLeftFooted;

    public:
        Player();
        Player(const Player &other);
        Player(const char *firstname,const char *lastname,const char *dob,bool ms,int pn,const char *loc,
                int number,const std::string &pos,bool leftfoot);
        ~Player() { std::cout << " player destructor called" << std::endl << std::endl;}

        inline void setPlayer(const int number) {Number = number;}
        inline const int getPlayer() const {return Number;}

        inline void setPosition(const std::string &pos) {Position = pos;}
        inline const std::string &getPosition() const {return Position;}

        inline void setFoot(const bool leftfoot) {isLeftFooted = leftfoot;}
        inline const bool getFoot() const {return isLeftFooted;}

        void IncrementGoals();

        inline const int getGoalsScored() const {return NumOfGoals;}

        void printPlayer() const; //I could have used overide but
                                 //might cause issues later on 
};

#endif