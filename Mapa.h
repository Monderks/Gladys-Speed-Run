#pragma once

#include <SFML\Graphics.hpp>
class Mapa
{
private:
	sf::Texture Fondo;
	sf::Sprite Fondito;

	sf::Texture Castillito;
	sf::Sprite Castillo;

	sf::Font Fuente;

	sf::Text Puntuacion;
	sf::Text Puntaje;
	sf::Text Text_Vidas;
	sf::Text Vida;
	sf::Text Tiempo;
	sf::Text Hora;

public:
	void setMapa();
	void draw(sf::RenderWindow& window);
	sf::Sprite& getFondo();
	sf::Sprite& getCastillo();
	sf::Text& getPuntuacion();
	sf::Text& getPuntaje();
	sf::Text& getVidas();
	sf::Text& getText_Vidas();
	sf::Text& getTiempo();
	sf::Text& getHora();
};

