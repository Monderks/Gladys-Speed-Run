#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML\Graphics.hpp>

#include <iostream>
#include <cstdlib>
#include <cstring>

#include <cctype>
#include <fstream>
#include <vector>
#include <sstream>

class Tiles
{
private:
	std::vector<std::vector<sf::Vector2i>>Map;
	std::vector<sf::Vector2i> tempMap;
	std::vector<std::vector<int>> colisionMap;
	sf::Texture tileTexture;
	sf::Sprite tiles;

public:
	void LoadMap(const char* filename)
	{
		std::ifstream openFile(filename);

		tempMap.clear();
		Map.clear();

		if (openFile.is_open()) //Comprobamos que está abierto
		{
			std::string tileLocation;
			openFile >> tileLocation;
			tileTexture.loadFromFile(tileLocation);
			tiles.setTexture(tileTexture);

			while (!openFile.eof()) //Mientras no se cierre
			{
				std::string str, value;
				std::getline(openFile, str);
				std::stringstream stream(str);

				while (std::getline(stream, value, ' '))
				{
					if (value.length() > 0) {
						std::string xx = value.substr(0, value.find(',')); //valores totales antes de la coma
						std::string yy = value.substr(value.find(',') + 1); //valores totales después de la coma

						int x, y, i, j;

						for (i = 0; i < xx.length(); i++)
						{
							if (!isdigit(xx[i]))
							{
								break;
							}
						}
						for (j = 0; j < yy.length(); j++)
						{
							if (!isdigit(yy[j]))
							{
								break;
							}
						}

						x = (i == xx.length()) ? atoi(xx.c_str()) : -1; //Si la cadena no es entero va negativo
						y = (j == yy.length()) ? atoi(yy.c_str()) : -1; //Si la cadena no es entero va negativo

						tempMap.push_back(sf::Vector2i(x, y));
					}
				}
				if (tempMap.size() > 0)
				{
					Map.push_back(tempMap);
					tempMap.clear();
				}
			}
		}
	}
	void LoadColisionMap(const char* fileName)
	{
		std::ifstream openFile(fileName);
		std::vector<int> tempMap;
		colisionMap.clear();

		if (openFile.is_open()) //Comprobamos que está abierto
		{
			while (!openFile.eof()) //Mientras no se cierre
			{
				std::string str, value;
				std::getline(openFile, str);
				std::stringstream stream(str);

				while (std::getline(stream, value, ' '))
				{
					if (value.length() > 0) {

						int a = atoi(value.c_str());
						tempMap.push_back(a);
					}
				}
				colisionMap.push_back(tempMap);
				tempMap.clear();
			}
		}
	}

	sf::Sprite& getTiles() { return tiles; };
	sf::Texture& getTileTexture() { return tileTexture; };
	std::vector<std::vector<int>>& getcolisionMap() { return colisionMap; };
	std::vector<std::vector<sf::Vector2i>>& getMap() { return Map; };
};

#endif // TILEMAP_H
