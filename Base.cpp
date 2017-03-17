#include <stdio.h>      /* printf */
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>       /* sqrt */
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdexcept>
#include "libsqlite.hpp"


using namespace std;
string Name;




/*
class map
{
    array<array<char, 40>, 20> importMap (string filename)
    {
        ifstream mapData;
        mapData.open(filename);
    }
    void drawMap()
    {
        
    }
};
*/

/*
The class to draw and call the map to the game loop
/**/

/*
class movement
{
    void ChangePosition(inital_posx, inital_posy, next_posx, next_posy)
    {
        if next_posx > map_size || next_posy > map_size
        {
            cout << "Your movement is invalid and wrong: next position is larger than the map" << endl;
        }
    }
};
*/

/*
The class to check position, change position, check new position
/**/

class player
{
    
};
/*
the class to hold functions relating to player, holds some data relating to the player
/**/


class database_connection
{
    string sqliteFile = "Gamedatabase.db";
    int startconnection(sqliteFile)
    {
        auto cur = db.get_statement();
        
        cur->set_sql( "select * "
                      "from Weapons "
                      "where Unique_loot_id = 1" );
       cur->prepare();                            // run query

    while( cur->step() )                    // loop over results
        cout << cur->get_int(0) << " " << cur->get_text(1) << endl;

        

        
    }
    catch( sqlite::exception e )      // catch all sql issues
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
};
    };
};

/*
the class to connect the database to the game, will also call data from the database
/**/


class enemies
{
    
};
/* Class used for Pickup*/


/*
the class to hold functions relating to enemies, holds some data relating to the enemies
/**/

class health
{
  int checkHealth()
  {
      return current_Health
  }
};



/*
Deals with health calculations
/**/

//Chin - Code deals with pickups
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

int main ()
{
    
    //Declarations for Pickup Class
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
    
    cout<<"Hello World\n";
    return 0;
}
/*  
The main gameloop it calls the functions, classes, variables and database values

/**/






