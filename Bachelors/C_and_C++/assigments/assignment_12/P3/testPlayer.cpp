#include "TournamentMember.h"

int main() {
    TournamentMember::setlocation("Main Stadium");

    // Create Player instances
    Player player1("steve", "smith", "1990-05-20", true, 10, "field", 7, "Forward", true);
    Player player2("hari", "black", "1992-08-15", false, 20, "field", 11, "Midfielder", false);
    Player player3("Sam", "Smith", "1988-02-10", true, 30, "field", 3, "Defender", true);

    // Print player information
    player1.print();
    player2.print();
    player3.print();

    // Increment goals scored for player1
    player1.IncrementGoals();

    // Move all players to the location "Hamburg"
    Player::changelocation("Hamburg");

    // Print player information after location change
    player1.printPlayer();
    player2.printPlayer();
    player3.printPlayer();

    return 0;
}
