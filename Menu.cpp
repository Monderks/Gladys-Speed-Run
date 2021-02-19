#include "Menu.h"

Menu::Menu(sf::Vector2i dimension, std::string titulo) :Ventana_Menu(sf::VideoMode(dimension.x, dimension.y), titulo)
{
	Ventana_Menu.setFramerateLimit(60);

	setMenu();

	gameLoop();
}
//-------------------------------------
void Menu::gameLoop()
{
	while (Ventana_Menu.isOpen())
	{
		ProcesarEventos(Ventana_Menu);
		Draw();
	}
}
void Menu::ProcesarEventos(sf::RenderWindow& Ventana_Menu)
{
	//Abrir una ventana nueva
	while (Ventana_Menu.pollEvent(Evento_Menu))
	{
		switch (Evento_Menu.type)
		{
		case sf::Event::Closed:
		{
			Ventana_Menu.close();
		}
		break;

		case sf::Event::KeyPressed:
			switch (Evento_Menu.key.code)
			{
			case sf::Keyboard::Up:
				MoveUp();
				break;
			case sf::Keyboard::Down:
				MoveDown();
				break;
			case sf::Keyboard::Return:
				switch (GetPressedItem())
				{
				case 0:
					estado.Juego = true;
					break;
				case 1:
					estado.Estadistica = true;
					break;
				case 2:
					Ventana_Menu.close();
				default:
					break;
				}
				break;
			}
			break;
		}
	}

	if (estado.Juego)
	{
		Ventana_Menu.setVisible(false);
		Juego juego({ 800,600 }, "Gladys Speed Run");
	}
	if (estado.Estadistica)
	{
		Ventana_Menu.setVisible(false);
		Statistic sts({ 800,600 }, "Estadisticas");
	}

	estado.Juego = false;
	estado.Estadistica = false;
	Ventana_Menu.setVisible(true);
}
//-------------------------------------
void Menu::Draw()
{
	Ventana_Menu.clear();

	Ventana_Menu.draw(Fondo_M);
	Ventana_Menu.draw(menu[0]);
	Ventana_Menu.draw(menu[1]);
	Ventana_Menu.draw(menu[2]);

	Ventana_Menu.display();
}
void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
	}
}
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < 3)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
	}
}
void Menu::setMenu()
{
	Fondo_Menu.loadFromFile("Resources\\SpritesMap\\Fondo_Menu.png");
	Fondo_M.setTexture(Fondo_Menu);

	fuente.loadFromFile("Resources\\Font\\Fuente.ttf");

	menu[0].setFont(fuente);
	menu[0].setFillColor(sf::Color::Black);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(610, 298));

	menu[1].setFont(fuente);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Statistics");
	menu[1].setPosition(sf::Vector2f(600, 425));
	menu[1].setScale(0.8, 0.8);

	menu[2].setFont(fuente);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(640, 535));

	estado.Juego = false;
	estado.Estadistica = false;
}


