#pragma once

#include <SFML\Graphics.hpp>

class Bala
{
private:
	sf::Texture Bullets;
	sf::Sprite Balls[6];
public:
	void setBala();
	void Movimiento();
	void draw(sf::RenderWindow& window);
	void setPosition();
	sf::Sprite& getBala(int n);
};


