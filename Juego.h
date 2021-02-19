#pragma once

#include <SFML\Graphics.hpp>

#include "Personaje.h"
#include "TileMap.h"
#include "Mapa.h"
#include "Puntos.h"
#include "Menu.h"
#include "Vidas.h"
#include "Animation.h"
#include "Bala.h"
#include "Juego_Terminado.h"
#include "Archivo.h"

#include <list>

class Juego
{
private:
	sf::RenderWindow ventana;
	sf::Event Evento;
	sf::View camara;
	//Textura - Sprite - Money
	sf::Texture Money;
	sf::Sprite Coin;
	//Textura - Sprite - Enemigos
	sf::Texture Hostiles;
	sf::Sprite Enemies;
	//--------------------------
	//ESTADOS estado;
	//--------------------------
	Vidas vidas;
	Personaje Personaje;
	Mapa mapa;
	Tiles Mapita;
	Puntos Punto;
	Bala Balls;

	int _time = 0;
	int ctime = 60;

	std::list<Entidades*> list_money;
	std::list<Entidades*> list_enemies;

public:
	Juego(sf::Vector2i dimension, std::string titulo);
	void Muerte(sf::View& Cam);
	void Dibujar_Juego();
	void gameLoop();
	void CheckCollision(sf::RenderWindow& ventana, sf::View& Cam);
	void ProcesarEventos(sf::RenderWindow& ventana);
};

