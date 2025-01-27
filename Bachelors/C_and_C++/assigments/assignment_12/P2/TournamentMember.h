/*
  CH-230-A
  a12_p2.cpp
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

#endif
