#pragma once

#include "SFML\Graphics.hpp"

#include "Menu.h"

class Statistic
{
private:
	sf::RenderWindow Ventana_Sts;
	sf::Event Evento_Sts;

	sf::Texture Fondo_Estadistica;
	sf::Sprite Fondo_E;
	sf::Font fuente;
	sf::Text menuE;

	sf::Text Score;
	sf::Text Time;

	bool arch = true;

public:
	Statistic(sf::Vector2i dimension, std::string titulo);
	void Loop();
	void Draw();
	void setStatistic();
	void ProcesarEventos(sf::RenderWindow& Ventana_Sts);

	sf::Text& getScore();
	sf::Text& getTime();
};

