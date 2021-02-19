#include <iostream>

#include "Juego_Terminado.h"

Juego_Terminado::Juego_Terminado(sf::Vector2i dimension, std::string titulo, int ctime, int puntos, int juego) :Ventana_Game(sf::VideoMode(dimension.x, dimension.y),titulo)
{
	Ventana_Game.setFramerateLimit(60);

	setJuego_Terminado();

	Loop(ctime, puntos, juego);
}
//-------------------------------------
void Juego_Terminado::setJuego_Terminado()
{
	lost.loadFromFile("Resources\\SpritesMap\\Menu_Perdiste.png");
	_lost.setTexture(lost);

	win.loadFromFile("Resources\\SpritesMap\\Menu_Ganaste.png");
	_win.setTexture(win);

	Fuente.loadFromFile("Resources\\Font\\Fuente.ttf");
	//Texto Score - Estadisticas - Perdida - Victoria
	Score.setFont(Fuente);
	Score.setCharacterSize(30);
	Score.setFillColor(sf::Color::White);
	Score.setPosition(625, 345);
	//Texto Time - Estadisticas - Perdida - Victoria
	Time.setFont(Fuente);
	Time.setCharacterSize(30);
	Time.setFillColor(sf::Color::White);
	Time.setPosition(625, 455);
}
//-------------------------------------
void Juego_Terminado::Loop(int ctime, int puntos, int juego)
{
	while (Ventana_Game.isOpen())
	{
		ProcesarEventos(Ventana_Game);
		Draw(ctime, puntos, juego);
	}
}
void Juego_Terminado::ProcesarEventos(sf::RenderWindow& Ventana_Game)
{
	//Abrir una ventana nueva
	while (Ventana_Game.pollEvent(Evento_Game))
	{
		switch (Evento_Game.type)
		{
		case sf::Event::Closed:
		{
			Ventana_Game.close();
		}
		break;

		case sf::Event::KeyPressed:
		case sf::Keyboard::Return:
			Ventana_Game.close();
		case sf::Keyboard::Escape:
			Ventana_Game.close();
			break;

			break;
		}
	}
}
void Juego_Terminado::Draw(int ctime, int Puntos, int juego)
{
	Ventana_Game.clear();

	getTime().setString(std::to_string(ctime));

	if (juego==1)
	{
		getScore().setString(std::to_string(Puntos + ctime * 10));
		Ventana_Game.draw(_win);
	}
	else
	{
		getScore().setString(std::to_string(Puntos));
		Ventana_Game.draw(_lost);
	}

	Ventana_Game.draw(getTime());
	Ventana_Game.draw(getScore());

	Ventana_Game.display();
}
//-------------------------------------
sf::Text& Juego_Terminado::getTime()
{
	return Time;
}
sf::Text& Juego_Terminado::getScore()
{
	return Score;
}






