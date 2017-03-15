#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <fstream>

using namespace std;


class map
{
	public:
    
    array <array<string, 160>, 40> importMap(string fileName)
	{
		ifstream mapFile;
		mapFile.open(fileName);
		
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
    
    void drawMap(array <array<string, 160>, 40> mapData)
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

int main()
{
	map currentMap;
	array <array<string, 160>, 40> mapInput = currentMap.importMap("level1.txt");
    currentMap.drawMap(mapInput);
    
    return 0;
}