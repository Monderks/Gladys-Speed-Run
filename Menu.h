#pragma once

#include <SFML\Graphics.hpp>

#include "Juego.h"
#include "Statistic.h"

struct ESTADOS_MENU {
	bool Juego;
	bool Estadistica;
};

class Menu
{
private:
	sf::RenderWindow Ventana_Menu;
	sf::Event Evento_Menu;

	ESTADOS_MENU estado;

	sf::Texture Fondo_Menu;
	sf::Sprite Fondo_M;

	sf::Font fuente;
	sf::Text menu[3];
	int selectedItemIndex = 0;

public:
	Menu(sf::Vector2i dimension, std::string titulo);
	void gameLoop();
	void ProcesarEventos(sf::RenderWindow& ventana);
	void setMenu();
	void Draw();
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
};

