/*
  CH-230-A
  a11_p4.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include "Creature.h"

using namespace std;

int main(int argc, char** argv) 
{
    string data;
    while (1)
    {
      // cout << "Creating a Creature.\n";
      // Creature c;
      // c.run();
      // cout << "\n";

      cout << "enter (wizard) or (land) or (sea) or (quit): ";
      cin >> data;
      cout << "\n";
    
      if (data == "wizard") 
      {
        Wizard* wizardObj = new Wizard();
        wizardObj->run();
        wizardObj->hover();
        delete wizardObj; //delete dynamic creature for wizard
      } 
      else if (data == "land") 
      {
        LandCreature* landObj = new LandCreature();
        landObj->print();
        delete landObj; //delete dynamic creature for land creature
      } 
      else if (data == "sea") 
      {
        SeaCreature* seaObj = new SeaCreature();
        seaObj->print();
        delete seaObj; //delete dynamic creature for sea creature
      } 
      else if (data == "quit") 
      {
        cout << "program has terminated" << endl;
        break;
      } 
      else 
      {
        cout << "Invalid input. enter (wizard) or (land) or (sea) or (quit): " << endl;
      }
      return 0;
    }
    
    

    
    
    
    // cout << "Creating a Creature.\n";
    // Creature c;
    // c.run();
    // cout << "\n";

    // cout << "\nCreating a Wizard.\n";
    // Wizard w;
    // w.run();
    // w.hover();
    // cout << "\n";

    // cout << "Creating a land creature\n";
    // LandCreature a;
    // a.run();
    // a.print();
    // cout << "\n";

    // cout << "creating a sea creature\n";
    // SeaCreature b;
    // b.run();
    // b.print();
    // cout << "\n";

    return 0;
}