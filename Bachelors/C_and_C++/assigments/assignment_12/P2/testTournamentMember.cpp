/*
  CH-230-A
  a12_p2.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include "TournamentMember.h"
#include <iostream>

int main()
{
    TournamentMember::setlocation("Main Stadium");

    TournamentMember member1;
    member1.print();

    TournamentMember member2("John", "Doe", "1990-05-20", true, 10, "gym"); // true would be person is married
                                                                            // and with static location no need to give location
    member2.print();

    TournamentMember member3 = member2;
    member3.print();

    member2.changelocation("Training Ground");
    member2.print();

    TournamentMember member4("hari", "bing", "1990-05-20", true, 10); // using the static
    member4.print();

    // just to test
    TournamentMember::changelocation("center practic ground");
    member2.print();
    member3.print();
    member4.print();

    return 0;
}
