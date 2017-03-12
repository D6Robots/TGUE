#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <ctime>
using namespace std;


int rand (void);


/* initialize random seed: */
  srand (time(NULL));

/* generate random x and y numbers */
  ranx = rand() % 40 + 1;
  rany = rand() % 160 + 1;



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
    
    //Make second pickup called Extension, position it on map and set the amount of health it will add
    pickup Extension;
    Extension.xPosition =ranx; // Random X Location
    Extension.yPosition =rany; // Random Y Location
    Extension.health = 20;
    
    //Make second pickup called Defferal, position it on map and set the amount of health it will add
    pickup Defferal;
    Defferal.xPosition = ranx;  // Random X Location
    Defferal.yPosition = rany;  // Random Y Location
    Defferal.health = 50;
    
}


