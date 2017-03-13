#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;






class Pickup 

{
    public:
            int xPosition;
            int yPosition;
            int pickupstatus;
            int pickuptotal;
            int health; // Indicates the level of health that will be added onto player 
}; 
      
int main (){
    
int rand (void);
int ranx;
int rany;



/* initialize random seed: */
  srand (time(NULL));

/* generate random x and y numbers */
  ranx = rand() % 40 + 1; // Used to Limit the Range of possible X values from 1 to 40 'in relation to map X axis'
  rany = rand() % 160 + 1;// Used to Limit the Range of possible Y values from 1 to 160 'in relation to map Y axis '
    
    
    
    //Make second pickup called Extension, position it on map and set the amount of health it will add
    Pickup Extension;
    Extension.xPosition =ranx; // Random X Location
    Extension.yPosition =rany; // Random Y Location
    Extension.health = 20; // Adds 20 points to the Health of the Player
    
    //Make second pickup called Defferal, position it on map and set the amount of health it will add
    Pickup Defferal;
    Defferal.xPosition = ranx;  // Random X Location
    Defferal.yPosition = rany;  // Random Y Location
    Defferal.health = 50; // Adds 50 points to the Health of the Player
    
    //Section Used for testing the random location, by Printing it Out
    cout << ranx << endl;
    cout << rany << endl;
    
    return 0;
    
}


