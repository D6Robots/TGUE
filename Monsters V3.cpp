#include <iostream>
#include <time.h>
#include <vector>
#include <string> 
#include <ctime>
#include <cstdlib>
using namespace std;

class Monster 

{
    public:
            int xPosition;
            int yPosition;
            int monsterstatus;
            int monstertotal;        
        
    
        //Movement methods for monster
        int moveUp(int movement){
            if(yPosition - movement > 0){
                yPosition = yPosition - movement;   
            }
        }
        int moveDown(int movement){
            if(yPosition + movement < 60){
                yPosition = yPosition + movement;   
            }
        }
        int moveLeft(int movement){
            if (xPosition - movement > 0){
                xPosition = xPosition - movement;   
            }
        }
        int moveRight(int movement){
            if (xPosition - movement < 40){
                xPosition = xPosition - movement;   
            }
        }
}; 
      
int main (){
    
    //Make monster 1 and position on map
    Monster monster1;
    monster1.xPosition =1;
    monster1.yPosition =1;
    
    //Make monster 2 and position on map
    Monster monster2;
    monster2.xPosition = 151;
    monster2.yPosition = 32;
    
    //Create 2 ints to store random numbers
    int randomX, randomY;
    srand(time(0));
    
    randomX = rand() % 40;
    randomY = rand() % 60;
    
    monster1.xPosition = randomX;
    monster1.yPosition = randomY;
    
    randomX = rand() % 40;
    randomY = rand() % 60;
    
    monster2.xPosition = randomX;
    monster2.yPosition = randomY;
    
    while(monster2.xPosition == monster1.xPosition || monster2.yPosition == monster1.yPosition){
        randomX = rand() % 40;
        randomY = rand() % 60;
        monster2.xPosition = randomX;
        monster2.yPosition = randomY;
    }
    
    cout << "Monster 1: X: " << monster1.xPosition << " Y: " << monster1.yPosition << endl;
    cout << "Monster 2: X: " << monster2.xPosition << " Y: " << monster2.yPosition << endl;
    

    cout <<monster2.xPosition << endl;
    //Move monster2 to the left by 21 places
    monster2.moveLeft(21);
    cout << "Monster 2: " << monster2.xPosition << endl;
    cout << "Monster 1: " << monster1.xPosition << endl;
    return 0;
}
