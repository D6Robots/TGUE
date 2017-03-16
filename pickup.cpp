#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

using namespace std;


class Pickup 

{
    public:
            int xPosition;
            int yPosition;
            int health; // Indicates the level of health that will be added onto player 
            int level;
            
    
    
    
            int pickuptotal(int a)
            {
         if (a == 1)
        {
            return 6;   
        }
    
        else if (a == 2)
        {
            return 3;
        }
    
        else if (a == 3)
        {
            return 3;  
        }
    
        else if (a == 4)
        {
            return 2;
        }
    
        else if (a == 5)
        {
            return 2;
        }
        
                
        else // When Level is less than 1 or greater than 5, it throws Error 1001 and outputs it in the screen
        {
             try
                {
                    throw 1001; //Throws error 1001
                }
             catch (int e)
                {
                    cout << "An exception occurred, Level is not Available. No:" << e << '\n'; //Prints error to the screen
                }
                return 0;
        }      
    };
    

    
    
    
    
}; 



int main (){

    // Variable Declaration
int rand (void);
int ranDx;
int ranDy;
int ranEx;
int ranEy;
int a;
int level;
    
    

    
    
/* initialize random seed: */
  srand (time(NULL));
 
/* generate random x and y numbers */
  ranDx = rand() % 40 + 1; // Used to Limit the Range of possible X values for Defferal from 1 to 40 'in relation to map X axis'
  ranDy = rand() % 160 + 1;// Used to Limit the Range of possible Y values for Defferal from 1 to 160 'in relation to map Y axis '
  
  ranEx = rand() % 40 + 1; // Used to Limit the Range of possible X values for Extension from 1 to 40 'in relation to map X axis'
  ranEy = rand() % 160 + 1;// Used to Limit the Range of possible Y values for Extension from 1 to 160 'in relation to map Y axis '
    
    
    
    //Make second pickup called Extension, position it on map and set the amount of health it will add
    Pickup Extension;
    Extension.xPosition =ranEx; // Random X Location
    Extension.yPosition =ranEy; // Random Y Location
    Extension.health = 20; // Adds 20 points to the Health of the Player
    Extension.pickuptotal(a);
    
    //Make second pickup called Defferal, position it on map and set the amount of health it will add
    Pickup Defferal;
    Defferal.xPosition = ranDx;  // Random X Location
    Defferal.yPosition = ranDy;  // Random Y Location
    Defferal.health = 50; // Adds 50 points to the Health of the Player
    Defferal.pickuptotal(a);
    
    
    
    /*Section Used for testing the random location, by Printing it Out
    cout << "The Extension x Position is : "<<Extension.xPosition << endl;
    cout << "The Extension y Position is : "<<Extension.yPosition << endl;
    
    cout << "The Defferal x Position is : "<<Defferal.xPosition << endl;
    cout << "The Defferal y Position is : "<<Defferal.yPosition << endl;
    
    cout <<"The Defferal pick up adds : "<<Defferal.health<<endl;
    cout <<"The Extension pick up adds : "<<Extension.health<<endl;
    */
    
    
    /*Used to test the amount of pickups available in the level 
    for( int a = 1; a < 7; a = a + 1 ) {
      cout << "value of a: " << a << endl;
      cout << "The Defferal pickup level for this level is  : " << Defferal.pickuptotal(a) <<endl;
      cout << "The Extension pickup level for this level is  : " << Extension.pickuptotal(a) <<endl;
   } 
    */
    
    
    
    
    return 0;
    
}

