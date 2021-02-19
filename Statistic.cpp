#include <iostream>
#include <cstdlib>
#include <stdio.h>

#include "Statistic.h"

Statistic::Statistic(sf::Vector2i dimension, std::string titulo) :Ventana_Sts(sf::VideoMode(dimension.x, dimension.y), titulo)
{
	Ventana_Sts.setFramerateLimit(60);

	setStatistic();

	Loop();
}
//-------------------------------------
void Statistic::Loop()
{
	while (Ventana_Sts.isOpen())
	{
		ProcesarEventos(Ventana_Sts);
		Draw();
	}
}
//-------------------------------------
void Statistic::ProcesarEventos(sf::RenderWindow& Ventana_Sts)
{
	//Abrir una ventana nueva
	while (Ventana_Sts.pollEvent(Evento_Sts))
	{
		switch (Evento_Sts.type)
		{
		case sf::Event::Closed:
		{
			Ventana_Sts.close();
		}
		break;

		case sf::Event::KeyPressed:
			case sf::Keyboard::Return:
				Ventana_Sts.close();
			case sf::Keyboard::Escape:
				Ventana_Sts.close();
				break;
			
			break;
		}
	}
}
//-------------------------------------
void Statistic::Draw()
{
	FILE* archivo;

	Sts sts;

	archivo = fopen("Resources\\HighScore\\Data.dat", "rb");

	if (archivo == NULL)
	{
		arch = false;
	}
	if (arch)
	{
		while (fread(&sts, sizeof(Sts), 1, archivo) == 1)
		{
			Ventana_Sts.clear();

			Ventana_Sts.draw(Fondo_E);
			Ventana_Sts.draw(menuE);

			getTime().setString(std::to_string(sts._time));
			getScore().setString(std::to_string(sts._score));

			Ventana_Sts.draw(getTime());
			Ventana_Sts.draw(getScore());

			Ventana_Sts.display();
		}

		fclose(archivo);
	}
	else
	{
		Ventana_Sts.clear();

		Ventana_Sts.draw(Fondo_E);
		Ventana_Sts.draw(menuE);

		Ventana_Sts.display();
	}
}
//-------------------------------------
void Statistic::setStatistic()
{
	//Menu Estadistica
	Fondo_Estadistica.loadFromFile("Resources\\SpritesMap\\Menu_Estadistica.png");
	Fondo_E.setTexture(Fondo_Estadistica);

	fuente.loadFromFile("Resources\\Font\\Fuente.ttf");

	menuE.setFont(fuente);
	menuE.setFillColor(sf::Color::Black);
	menuE.setString("Continuar");
	menuE.setPosition(sf::Vector2f(580, 555));
	menuE.setScale(0.8, 0.8);

	//Texto Estadisticas
	Score.setFont(fuente);
	Score.setCharacterSize(30);
	Score.setFillColor(sf::Color::White);
	Score.setPosition(625, 345);
	//Texto Estadisticas
	Time.setFont(fuente);
	Time.setCharacterSize(30);
	Time.setFillColor(sf::Color::White);
	Time.setPosition(625, 455);
}
//-------------------------------------
sf::Text& Statistic::getScore()
{
	return Score;
}
sf::Text& Statistic::getTime()
{
	return Time;
}
