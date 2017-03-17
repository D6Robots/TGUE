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
    
    array <array<string, 160>, 40> importMap(string fileName)
    /* Takes a text file containing a map as input, and returns an array of arrays, with each array being a row and each element of the array being an element in the game */
	{
		ifstream mapFile;
		mapFile.open(fileName);  // Opens the text file containing the map for reading
		
		array <array<string, 160>, 40> mapData;  // The array of arrays containing the data for each coordinate on the map

		for (int i = 0; i < 40; i++)  // For every line
		{
			string lineString;  // Stores the row as a string
			array<string, 160> lineArray;
			mapFile >> lineString;
            
            for (int j = 0; j < 160; j++)  // Splits the string into characters which will be stored in an array for the row
            {
                lineArray[j] = lineString.substr(j, 1);
            }

			mapData[i] = lineArray;

		}
        
        // Finds and replaces 'o' in the array with ' '
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
    
    // void getHealthPickups(std::string sqliteFile)
    // {
    // try
    // {
    // sqlite::sqlite db( sqliteFile );
    // auto cur = db.get_statement();
    // cur->step();
    //     cur->set_sql( "select * from Loot where Type = 'health';");
    // cur->prepare();
    //    while( cur->step())
    //    {
    //        string name = cur ->get_text(1);
    //        cout << name << endl;
    //    }
    // }
    // catch( sqlite::exception e )      // catch all sql issues
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    // }
    
    void spawnPickups(array <array<string, 160>, 40> mapData)
    /* Takes the map as an array as input and adds pickups at random empty locations before returning the map */
    {
        
    }
    
    void drawMap(array <array<string, 160>, 40> mapData)
    /* Takes the map as an array as input, and prints it to the screen */
    {
        for (int i = 0; i < 40; i++)  // For every line
        {
            array<string, 160> currentLine = mapData[i];
            for (int j = 0; j < 160; j++)  // For every character in the line
            {
                cout << currentLine[j];
            }
            cout << endl;
        }
    }
};

class Player
{
    public:
    
    /* Constructor assigning health and a starting position to the player.  Checks to make sure starting values are valid */
    Player(short hp)
    {
        if(hp > 100 or hp < 0)
        {
            cout << "Starting values for player are invalid" << endl;
        }
        else
        {
            short health = hp;
        }
    }
    
    /* Moves the player in the specified direction */
    array<array<string, 160>, 40> move(array<int, 2> currentPosition, string direction, array <array<string, 160>, 40> mapData)
    {
        // Calculates the next position of the player
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
        
        // Updates map with new position, leaving it unchanged if the position the player chose is invalid
        if (mapData[tentativePosition[1]][tentativePosition[0]] == "#")
        {
            return mapData;  // Leaves map unchanged
        }
        else if (mapData[tentativePosition[1]][tentativePosition[0]] == "E")
        {
            mapData[0][0] = "next level";
            return mapData;
        }
        else
        {
            mapData[currentPosition[1]][currentPosition[0]] = " ";  // Sets the previous position to empty space
            mapData[tentativePosition[1]][tentativePosition[0]] = "p";  // Puts player in the next position
            return mapData;
        }
    }
    
    /* Gets the player's current position */
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
    
    /* Main game loop */
    while(gameOver == false)
    {
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
                gameOver = true;
            }
        }
        
        currentPosition = player.getPosition(mapData);
        map.drawMap(mapData);
        
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
        }
        
        system("clear");
    }
    
    
    return 0;
}