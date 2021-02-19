#include "Bala.h"

void Bala::setBala()
{
	Bullets.loadFromFile("Resources\\SpritesCharacters\\Bala.png");
	
	for (int i = 0; i < 6; i++)
	{
		Balls[i].setTexture(Bullets);
		Balls[i].setScale(0.5f, 0.5f);
	}

	Balls[0].setPosition(1475, 422);
	Balls[1].setPosition(2825, 422);
	Balls[2].setPosition(3175, 372);
	Balls[3].setPosition(3525, 422);
	Balls[4].setPosition(3775, 372);
	Balls[5].setPosition(4025, 422);

}
//-------------------------------------
void Bala::Movimiento()
{
	if (Balls[0].getPosition().x > 900)
	{
		
		Balls[0].move(-4, 0);
	}
	if (Balls[1].getPosition().x > 2450)
	{
		Balls[1].move(-3, 0);
	}
	if (Balls[2].getPosition().x > 2800)
	{
		Balls[2].move(-3, 0);
	}
	if (Balls[3].getPosition().x > 3150)
	{
		Balls[3].move(-3, 0);
	}
	if (Balls[4].getPosition().x > 3500)
	{
		Balls[4].move(-2, 0);
	}
	if (Balls[5].getPosition().x > 3750)
	{
		Balls[5].move(-2, 0);
	}
}
void Bala::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 6; i++)
	{
	window.draw(Balls[i]);
	}
}
void Bala::setPosition()
{
	Balls[0].setPosition(1475, 422);
	Balls[1].setPosition(2825, 422);
	Balls[2].setPosition(3175, 372);
	Balls[3].setPosition(3525, 422);
	Balls[4].setPosition(3775, 372);
	Balls[5].setPosition(4025, 422);
}
//-------------------------------------
sf::Sprite& Bala::getBala(int n)
{
	return Balls[n];
}


