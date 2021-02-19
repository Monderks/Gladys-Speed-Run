#pragma once

#include "SFML\Graphics.hpp"

class Juego_Terminado
{
private:
	sf::RenderWindow Ventana_Game;
	sf::Event Evento_Game;

	sf::Texture lost;
	sf::Sprite _lost;

	sf::Texture win;
	sf::Sprite _win;

	sf::Font Fuente;

	sf::Text Time;
	sf::Text Score;

public:
	Juego_Terminado(sf::Vector2i dimension, std::string titulo, int ctime, int puntos, int juego);
	void setJuego_Terminado();
	void Loop(int ctime, int puntos, int juego);
	void Draw(int ctime, int puntos, int juego);
	void ProcesarEventos(sf::RenderWindow& Ventana_Game);

	sf::Text& getTime();
	sf::Text& getScore();
};

