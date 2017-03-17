#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <stdlib.h>

#include "libsqlite.hpp"

using namespace std;


class Map
{
	public:
    
    // Takes a text file containing a map as input, and returns an array of arrays, with each array being a row and each element of the array being an element in the game
    array <array<string, 160>, 40> importMap(string fileName)
	{
        ifstream mapFile;  // Creates a file object for reading
		mapFile.open(fileName);  // Opens the text file containing the map and assigns it to the file object
		
		// Stores every character in the map in an array of arrays, with each array representing a row
        array <array<string, 160>, 40> mapData;
        for (int i = 0; i < 40; i++)  // For every line
		{
			string lineString;
			array<string, 160> lineArray;
			mapFile >> lineString;  // Stores the row as a string
            
            for (int j = 0; j < 160; j++)  // For every character in the line
            {
                lineArray[j] = lineString.substr(j, 1);  // Stores the character as a string in an array
            }

			mapData[i] = lineArray;
		}

        // Finds and replaces every 'o' in the array with ' '
        for (int i = 0; i < 40; i++)
        {
            array<string, 160> currentLine = mapData[i];
            for (int j = 0; j < 160; j++)
            {
                if(currentLine[j] == "o")
                {
                    currentLine[j] = " ";
                }
            }
            mapData[i] = currentLine;
        }
        
        return mapData;

		mapFile.close();
	}
    
    
    void getHealthPickups(std::string sqliteFile)
    {
        try
        {
            sqlite::sqlite db( sqliteFile );
            auto cur = db.get_statement();
            cur->step();
            cur->set_sql( "select * from Loot where Type = 'health';");  // Finds pickups of the 'health' type
            cur->prepare();
            while( cur->step())  // Moves to the next row in the table
            {
                string name = cur ->get_text(1);  // Gets the text from the second column and stores it as a variable
                cout << name << endl;
            }
        }
        
        catch( sqlite::exception e )      // Catches all SQL issues
        {
            std::cerr << e.what() << std::endl;
        }
    }
    
    // Takes the map as an array as input and adds pickups at random empty locations before returning the map
    array <array<string, 160>, 40> spawnPickups(array <array<string, 160>, 40> mapData)
    {
        
    }
    
    // Takes the map as an array as input, and prints it to the screen
    void drawMap(array <array<string, 160>, 40> mapData)
    {
        for (int i = 0; i < 40; i++)  // For every line
        {
            array<string, 160> currentLine = mapData[i];
            for (int j = 0; j < 160; j++)  // For every character in the line
            {
                cout << currentLine[j];
            }
            cout << endl;  // Moves to the next line after the loop is done with the row
        }
    }
};


class Player
{
    public:
    
    short health;
    
    // Constructor assigning health and a starting position to the player.  Checks to make sure starting values are valid 
    Player(short hp)
    {
        if(hp > 100 or hp < 0)
        {
            cout << "Starting values for player are invalid" << endl;
        }
        else
        {
            Player::health = hp;
        }
    }
    
    // Moves the player in the specified direction and returns the updated map
    array<array<string, 160>, 40> move(array<int, 2> currentPosition, string direction, array <array<string, 160>, 40> mapData)
    {
        // Calculates what the next position of the player would be, in order to check it for collisions
        array<int, 2> tentativePosition;
        if (direction == "right")
        {
            tentativePosition = {currentPosition[0] + 1, currentPosition[1]};
        }
        else if (direction == "left")
        {
            tentativePosition = {currentPosition[0] - 1, currentPosition[1]};
        }
        else if (direction == "up")
        {
            tentativePosition = {currentPosition[0], currentPosition[1] - 1};
        }
        else if (direction == "down")
        {
            tentativePosition = {currentPosition[0], currentPosition[1] + 1};
        }
        
        // Checks for collisions and updates map accordingly
        if (mapData[tentativePosition[1]][tentativePosition[0]] == "#")
        {
            cout << "You hit a wall!" << endl;  // Leaves map unchanged if player collides with a wall
        }
        else if (mapData[tentativePosition[1]][tentativePosition[0]] == "E")
        {
            mapData[0][0] = "next level";  // Adds a tag which tells the game to go to the next level, if the player reached the end of the level
        }
        else if (mapData[tentativePosition[1]][tentativePosition[0]] == "+")
        {
            if(Player::health > 70)  // Ensures player health will never go above 100
            {
                Player::health = 100;
            }
            else
            {
                Player::health = Player::health + 30;  // Adds 30 to player health
            }
            mapData[currentPosition[1]][currentPosition[0]] = " ";  // Sets the previous position to empty space
            mapData[tentativePosition[1]][tentativePosition[0]] = "p";  // Puts player in the next position, removing the health pack
        }
        else if (mapData[tentativePosition[1]][tentativePosition[0]] == "x")
        {
            Player::health = Player::health - 50;  // Subtracts 50 from player health if player walks over mine
            mapData[currentPosition[1]][currentPosition[0]] = " ";  // Sets the previous position to empty space
            mapData[tentativePosition[1]][tentativePosition[0]] = "p";  // Puts player in the next position, removing the mine
        }
        else
        {
            mapData[currentPosition[1]][currentPosition[0]] = " ";  // Sets the previous position to empty space
            mapData[tentativePosition[1]][tentativePosition[0]] = "p";  // Puts player in the next position
        }
        
        return mapData;
    }
    
    // Gets the player's current position
    array<int, 2> getPosition(array <array<string, 160>, 40> mapData)
    {
        array<int, 2> currentPosition;
        for (int i = 0; i < 40; i++)
        {
            for (int j = 0; j < 160; j++)
            {
                if(mapData[i][j] == "p")
                {
                    currentPosition = {j, i};
                    return currentPosition;
                }
            }
        }
    }
};


int main()
{
	
    Map map;
    Player player(100);
	array <array<string, 160>, 40> mapData = map.importMap("level1.txt");
    
    array<int, 2> currentPosition;
    
    bool gameOver = false;
    string nextMove;
    
    short currentLevel = 1;
    
    // Main game loop
    while(gameOver == false)
    {
        system("clear");  // Clears the console
        
        // Checks if the game should load the next map
        if (mapData[0][0] == "next level")
        {
            if (currentLevel == 1)
            {
                currentLevel = 2;
                mapData = map.importMap("level2.txt");
            }
            else if (currentLevel == 2)
            {
                currentLevel == 3;
                mapData = map.importMap("level3.txt");
            }
            else if (currentLevel == 3)
            {
                currentLevel = 4;
                mapData = map.importMap("level4.txt");
            }
            else if (currentLevel == 4)
            {
                currentLevel = 5;
                mapData = map.importMap("level5.txt");
            }
            else if (currentLevel == 5)
            {
                cout << "Congratulations!" << endl;
                gameOver = true;
            }
        }
        
        currentPosition = player.getPosition(mapData);
        map.drawMap(mapData);  // Draws the map
        
        cout << endl << "Your health is " << player.health << "." << endl;
        if (player.health < 0)  // Checks if player has died
        {
            gameOver = true;
            cout << "Game over!" << endl;
        }
        else
        {
            cout << "What is your next move?: ";
            cin >> nextMove;
        
            if (nextMove == "d")
            {
                mapData = player.move(currentPosition, "right", mapData);
            }
            else if (nextMove == "a")
            {
                mapData = player.move(currentPosition, "left", mapData);
            }
            else if (nextMove == "w")
            {
                mapData = player.move(currentPosition, "up", mapData);
            }
            else if (nextMove == "s")
            {
                mapData = player.move(currentPosition, "down", mapData);
            }
            else if (nextMove == "end")
            {
                gameOver = true;
                cout << "You ended the game" << endl;
            }
        }
        
    }
    
    
    return 0;
}
