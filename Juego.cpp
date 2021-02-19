#include <iostream>

#include "Juego.h"

Juego::Juego(sf::Vector2i dimension, std::string titulo) :ventana(sf::VideoMode(dimension.x, dimension.y), titulo)
{
	ventana.setFramerateLimit(60);

	camara = sf::View(sf::FloatRect(0, 0, 800, 600));

	Personaje.setPersonaje();
	Balls.setBala();

	mapa.setMapa();

	//Cargo Tiles
	Mapita.LoadMap("Resources\\ConfigurationMap\\MapaSprite.txt");
	Mapita.LoadColisionMap("Resources\\ConfigurationMap\\MapaColision.txt");

	//Cargo de Monedas
	{
		Money.loadFromFile("Resources\\SpritesCharacters\\Moneda.png");

		Entidades* moneda[21];

		for (int i = 0; i < 21; i++)
		{
			moneda[i] = new Entidades();
			moneda[i]->animation = Animation(Money, 0, 0, 142, 141, 7, 0.2);
			moneda[i]->animation.setScale(0.2f, 0.2f);
		}
		//Posición de las monedas
		{
			moneda[0]->animation.setPosition(275, 420);
			moneda[1]->animation.setPosition(425, 420);
			moneda[2]->animation.setPosition(575, 420);
			moneda[3]->animation.setPosition(725, 420);
			moneda[4]->animation.setPosition(1000, 420);
			moneda[5]->animation.setPosition(1200, 420);
			moneda[6]->animation.setPosition(1400, 420);
			moneda[7]->animation.setPosition(1600, 270);
			moneda[8]->animation.setPosition(1750, 270);
			moneda[9]->animation.setPosition(1850, 70);
			moneda[10]->animation.setPosition(2000, 70);
			moneda[11]->animation.setPosition(2125, 420);
			moneda[12]->animation.setPosition(2275, 420);
			moneda[13]->animation.setPosition(2575, 420);
			moneda[14]->animation.setPosition(2825, 370);
			moneda[15]->animation.setPosition(2975, 220);
			moneda[16]->animation.setPosition(3175, 320);
			moneda[17]->animation.setPosition(3350, 420);
			moneda[18]->animation.setPosition(3525, 370);
			moneda[19]->animation.setPosition(3775, 320);
			moneda[20]->animation.setPosition(4025, 370);

		}
		for (int i = 0; i < 21; i++)
		{
			list_money.push_back(moneda[i]);
		}
	}
	//Cargo Enemigos
	{
	Hostiles.loadFromFile("Resources\\SpritesCharacters\\Planta.png");

	Entidades* enemigos[22];

	for (int i = 0; i < 22; i++)
	{
		enemigos[i] = new Entidades();
		enemigos[i]->animation = Animation(Hostiles, 0, 0, 50, 50, 2, 0.2);
		enemigos[i]->animation.setScale(0.75f, 0.75f);
	}
	//Posición de las Plantas
	{
		enemigos[0]->animation.setPosition(24 + 50 * 9, 481);
		enemigos[1]->animation.setPosition(24 + 50 * 10, 481);
		enemigos[2]->animation.setPosition(24 + 50 * 12, 481);
		enemigos[3]->animation.setPosition(24 + 50 * 13, 481);
		enemigos[4]->animation.setPosition(24 + 50 * 21, 481);
		enemigos[5]->animation.setPosition(24 + 50 * 26, 481);
		enemigos[6]->animation.setPosition(24 + 50 * 33, 481 - 50 * 4);
		enemigos[7]->animation.setPosition(24 + 50 * 38, 481 - 50 * 8);
		enemigos[8]->animation.setPosition(24 + 50 * 43, 481);
		enemigos[9]->animation.setPosition(24 + 50 * 44, 481);
		enemigos[10]->animation.setPosition(24 + 50 * 57, 481);
		enemigos[11]->animation.setPosition(24 + 50 * 58, 481);
		enemigos[12]->animation.setPosition(24 + 50 * 59, 481);
		enemigos[13]->animation.setPosition(24 + 50 * 60, 481);
		enemigos[14]->animation.setPosition(24 + 50 * 61, 481);
		enemigos[15]->animation.setPosition(24 + 50 * 62, 481);
		enemigos[16]->animation.setPosition(24 + 50 * 65, 481);
		enemigos[17]->animation.setPosition(24 + 50 * 68, 481);
		enemigos[18]->animation.setPosition(24 + 50 * 71, 481);
		enemigos[19]->animation.setPosition(24 + 50 * 74, 481);
		enemigos[20]->animation.setPosition(24 + 50 * 76, 481);
		enemigos[21]->animation.setPosition(24 + 50 * 79, 481);
	}

	//Cargo de Plantas

	for (int i = 0; i < 22; i++)
	{
		list_enemies.push_back(enemigos[i]);
	}
	}
	gameLoop();

}
//-------------------------------------
void Juego::Dibujar_Juego()
{
	ventana.clear(); //borra la ventana
	//Camara
	ventana.setView(camara);
	//Fondo
	ventana.draw(mapa.getFondo());
	//Castillo
	ventana.draw(mapa.getCastillo());
	//Monedas
	for (auto x : list_money)
	{
		ventana.draw(x->animation);
	}
	//balas
	Balls.draw(ventana);
	//Tiles del Mapa - Terreno/Estructuras
	for (int i = 0; i < Mapita.getMap().size(); i++)
	{
		for (int j = 0; j < Mapita.getMap()[i].size(); j++)
		{
			if (Mapita.getMap()[i][j].x != -1 && Mapita.getMap()[i][j].y != -1)
			{
				Mapita.getTiles().setPosition(j * 50, i * 50);
				Mapita.getTiles().setTextureRect(sf::IntRect(Mapita.getMap()[i][j].x * 50, Mapita.getMap()[i][j].y * 50, 50, 50));
				ventana.draw(Mapita.getTiles());
			}
		}
	}
	//Personaje Principal
	ventana.draw(Personaje.getPersonaje());
	//Enemigos
	for (auto y : list_enemies)
	{
		ventana.draw(y->animation);
	}
	//Mapa
	mapa.getTiempo().setString(std::to_string(ctime));
	mapa.getPuntaje().setString(std::to_string(Punto.getPuntos()));
	mapa.draw(ventana);
	mapa.getVidas().setString(std::to_string(vidas.getVidas()));

	ventana.display(); //muestra la ventana
}
//-------------------------------------
void Juego::gameLoop()
{
	while (ventana.isOpen())
	{
		ProcesarEventos(ventana);

		CheckCollision(ventana, camara);

		if (_time == 60 && ctime > 0)
			{
				_time = 0;
				ctime--;
			}

		//Cada 3 segundos 1 disparo torreta
		if (ctime % 3)
			{
				Balls.Movimiento();
			}
		else
			{
				Balls.setPosition();
			}
		_time++;

		Dibujar_Juego();
		
	}
}
//-------------------------------------
void Juego::ProcesarEventos(sf::RenderWindow& ventana)
{
	//Abrir una ventana nueva
	while (ventana.pollEvent(Evento))
	{
		switch (Evento.type) 
		{
		case sf::Event::Closed:
		{
			ventana.close();
		}
		break;
		}
	}
	for (auto x : list_money)
	{
		x->animation.update();
	}
	for (auto y : list_enemies)
	{
		y->animation.update();
	}

	if (vidas.getVidas() == 0 || ctime==0) 
	{
		Juego_Terminado game({ 800,600 }, "Juego Terminado", ctime, Punto.getPuntos(), 0);
		ventana.close();
	}

	Personaje.cmd();
	Personaje.update();
}
//-------------------------------------
void Juego::CheckCollision(sf::RenderWindow& ventana, sf::View& Cam)
{
	bool colision = false;

	//Personaje - Mundo/Tiles
	for (int i = 0; i < Mapita.getcolisionMap().size(); i++)
	{
		for (int j = 0; j < Mapita.getcolisionMap()[i].size(); j++)
		{
			//Para que no salga del mapa
			if (Personaje.getPersonaje().getPosition().x < 30)
			{
				Personaje.getPersonaje().move(4, 0.f);
			}

			if (Mapita.getcolisionMap()[i][j] == 1 || Mapita.getcolisionMap()[i][j] == 3)
			{
				int bottom, top, left, right;
				bottom = i * 50 + 50;
				top = i * 50;
				right = j * 50 + 50;
				left = j * 50;

				if (Personaje.getPersonaje().getPosition().y > top && Personaje.getPersonaje().getPosition().x - 29 < right - 1
					&& Personaje.getPersonaje().getPosition().x + 31 > left + 1 && Personaje.getPersonaje().getPosition().y < bottom
					)
				{
					Personaje.Quieto(Personaje.getPersonaje().getPosition().x, top);
				}
				else
				{
					if ((Personaje.getPersonaje().getPosition().x + 30 > left && Personaje.getPersonaje().getPosition().x - 28 < right - 40
						&& Personaje.getPersonaje().getPosition().y - 20 > top + 1 && Personaje.getPersonaje().getPosition().y - 80 < bottom - 1
						|| (Personaje.getPersonaje().getPosition().x + 30 > left && Personaje.getPersonaje().getPosition().x - 28 < right - 40
							&& Personaje.getPersonaje().getPosition().y - 40 > top + 1 && Personaje.getPersonaje().getPosition().y - 60 < bottom - 1)
						|| (Personaje.getPersonaje().getPosition().x + 30 > left && Personaje.getPersonaje().getPosition().x - 28 < right - 40
							&& Personaje.getPersonaje().getPosition().y - 60 > top + 1 && Personaje.getPersonaje().getPosition().y - 40 < bottom - 1)
						|| (Personaje.getPersonaje().getPosition().x + 30 > left && Personaje.getPersonaje().getPosition().x - 28 < right - 40
							&& Personaje.getPersonaje().getPosition().y - 80 > top + 1 && Personaje.getPersonaje().getPosition().y - 20 < bottom - 1)
						|| (Personaje.getPersonaje().getPosition().x + 30 > left && Personaje.getPersonaje().getPosition().x - 28 < right - 40
							&& Personaje.getPersonaje().getPosition().y - 90 > top + 1 && Personaje.getPersonaje().getPosition().y < bottom - 1))
						)
					{
						Personaje.Quieto(Personaje.getPersonaje().getPosition().x - 4, Personaje.getPersonaje().getPosition().y);
						colision = true;
					}
					else
					{
						if ((Personaje.getPersonaje().getPosition().x + 30 > left + 40 && Personaje.getPersonaje().getPosition().x - 28 < right
							&& Personaje.getPersonaje().getPosition().y - 20 > top + 1 && Personaje.getPersonaje().getPosition().y - 80 < bottom - 1
							|| (Personaje.getPersonaje().getPosition().x + 30 > left + 40 && Personaje.getPersonaje().getPosition().x - 28 < right
								&& Personaje.getPersonaje().getPosition().y - 40 > top + 1 && Personaje.getPersonaje().getPosition().y - 60 < bottom - 1)
							|| (Personaje.getPersonaje().getPosition().x + 30 > left + 40 && Personaje.getPersonaje().getPosition().x - 28 < right
								&& Personaje.getPersonaje().getPosition().y - 60 > top + 1 && Personaje.getPersonaje().getPosition().y - 40 < bottom - 1)
							|| (Personaje.getPersonaje().getPosition().x + 30 > left + 40 && Personaje.getPersonaje().getPosition().x - 28 < right
								&& Personaje.getPersonaje().getPosition().y - 80 > top + 1 && Personaje.getPersonaje().getPosition().y - 20 < bottom - 1)
							|| (Personaje.getPersonaje().getPosition().x + 30 > left + 40 && Personaje.getPersonaje().getPosition().x - 28 < right
								&& Personaje.getPersonaje().getPosition().y - 90 > top + 1 && Personaje.getPersonaje().getPosition().y < bottom - 1))
							)
						{
							Personaje.Quieto(Personaje.getPersonaje().getPosition().x + 4, Personaje.getPersonaje().getPosition().y);
							colision = true;
						}
					}
				}

			}

			if (Mapita.getcolisionMap()[i][j] == 2 || Mapita.getcolisionMap()[i][j] == 4)
			{
				int bottom, top, left, right;
				bottom = i * 50 + 50;
				top = i * 50;
				right = j * 50 + 50;
				left = j * 50;

				if (Personaje.getPersonaje().getPosition().y > top && Personaje.getPersonaje().getPosition().x - 29 < right - 1
					&& Personaje.getPersonaje().getPosition().x + 31 > left + 1 && Personaje.getPersonaje().getPosition().y - 100 < bottom - 5)
				{
					Personaje.PerderVelocidad();
				}
				if (Personaje.getPersonaje().getPosition().y > top && Personaje.getPersonaje().getPosition().x - 29 < right - 1
					&& Personaje.getPersonaje().getPosition().x + 31 > left + 1 && Personaje.getPersonaje().getPosition().y < bottom
					)
				{
					Personaje.Quieto(Personaje.getPersonaje().getPosition().x, top);
				}
				else
				{
					if ((Personaje.getPersonaje().getPosition().x + 30 > left && Personaje.getPersonaje().getPosition().x - 28 < right - 40
						&& Personaje.getPersonaje().getPosition().y - 20 > top + 1 && Personaje.getPersonaje().getPosition().y - 80 < bottom - 1
						|| (Personaje.getPersonaje().getPosition().x + 30 > left && Personaje.getPersonaje().getPosition().x - 28 < right - 40
							&& Personaje.getPersonaje().getPosition().y - 40 > top + 1 && Personaje.getPersonaje().getPosition().y - 60 < bottom - 1)
						|| (Personaje.getPersonaje().getPosition().x + 30 > left && Personaje.getPersonaje().getPosition().x - 28 < right - 40
							&& Personaje.getPersonaje().getPosition().y - 60 > top + 1 && Personaje.getPersonaje().getPosition().y - 40 < bottom - 1)
						|| (Personaje.getPersonaje().getPosition().x + 30 > left && Personaje.getPersonaje().getPosition().x - 28 < right - 40
							&& Personaje.getPersonaje().getPosition().y - 80 > top + 1 && Personaje.getPersonaje().getPosition().y - 20 < bottom - 1)
						|| (Personaje.getPersonaje().getPosition().x + 30 > left && Personaje.getPersonaje().getPosition().x - 28 < right - 40
							&& Personaje.getPersonaje().getPosition().y - 90 > top + 1 && Personaje.getPersonaje().getPosition().y < bottom - 1))
						)
					{
						Personaje.Quieto(Personaje.getPersonaje().getPosition().x - 4, Personaje.getPersonaje().getPosition().y);
						colision = true;
					}
					else
					{
						if ((Personaje.getPersonaje().getPosition().x + 30 > left + 40 && Personaje.getPersonaje().getPosition().x - 28 < right
							&& Personaje.getPersonaje().getPosition().y - 20 > top + 1 && Personaje.getPersonaje().getPosition().y - 80 < bottom - 1
							|| (Personaje.getPersonaje().getPosition().x + 30 > left + 40 && Personaje.getPersonaje().getPosition().x - 28 < right
								&& Personaje.getPersonaje().getPosition().y - 40 > top + 1 && Personaje.getPersonaje().getPosition().y - 60 < bottom - 1)
							|| (Personaje.getPersonaje().getPosition().x + 30 > left + 40 && Personaje.getPersonaje().getPosition().x - 28 < right
								&& Personaje.getPersonaje().getPosition().y - 60 > top + 1 && Personaje.getPersonaje().getPosition().y - 40 < bottom - 1)
							|| (Personaje.getPersonaje().getPosition().x + 30 > left + 40 && Personaje.getPersonaje().getPosition().x - 28 < right
								&& Personaje.getPersonaje().getPosition().y - 80 > top + 1 && Personaje.getPersonaje().getPosition().y - 20 < bottom - 1)
							|| (Personaje.getPersonaje().getPosition().x + 30 > left + 40 && Personaje.getPersonaje().getPosition().x - 28 < right
								&& Personaje.getPersonaje().getPosition().y - 90 > top + 1 && Personaje.getPersonaje().getPosition().y < bottom - 1))
							)
						{
							Personaje.Quieto(Personaje.getPersonaje().getPosition().x + 4, Personaje.getPersonaje().getPosition().y);
							colision = true;
						}
					}
				}
			}

		}
	}
	//Camara con el personaje
	if (ventana.hasFocus()) //si la ventana está activa
	{
		if (Personaje.getPersonaje().getPosition().x >= 400 /*&& Personaje.getPersonaje().getPosition().x <= 2600*/ && !colision) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				Cam.move(-4.0f, 0);
				mapa.getPuntaje().move(-4.0f, 0);
				mapa.getPuntuacion().move(-4.0f, 0);
				mapa.getText_Vidas().move(-4.0f, 0);
				mapa.getVidas().move(-4.0f, 0);
				mapa.getTiempo().move(-4.f, 0);
				mapa.getHora().move(-4.f, 0);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				Cam.move(4.0f, 0);
				mapa.getPuntaje().move(4.0f, 0);
				mapa.getPuntuacion().move(4.0f, 0);
				mapa.getText_Vidas().move(4.0f, 0);
				mapa.getVidas().move(4.0f, 0);
				mapa.getTiempo().move(4.f, 0);
				mapa.getHora().move(4.f, 0);
			}
		}
	}
	//Personaje - Vidas
	if (Personaje.getPersonaje().getPosition().y > 700)
	{
		vidas.setVidas(-1);
		Muerte(camara);
	}
	//Personaje - Moneda
	for (auto x = list_money.begin(); x!=list_money.end();)
	{
		Entidades*coin  = *x;

		if (Personaje.getPersonaje().getGlobalBounds().intersects(coin->animation.getGlobalBounds()))
		{
			Punto.setPuntos(10);
			x = list_money.erase(x);
		}
		else
		{
			x++;
		}
	}
	//Personaje - Plantas
	for (auto y = list_enemies.begin(); y!= list_enemies.end();)
	{
		Entidades*hostil = *y;

		if (Personaje.getPersonaje().getGlobalBounds().intersects(hostil->animation.getGlobalBounds()))
		{
			vidas.setVidas(-1);
			Muerte(camara);
		}
		y++;
	}
	//Personaje - Balas
	for (int i = 0; i < 6; i++)
	{
		if (Personaje.getPersonaje().getGlobalBounds().intersects(Balls.getBala(i).getGlobalBounds()))
		{
			vidas.setVidas(-1);
			Muerte(camara);
		}
	}
	//Personaje - Termino de Juego
	if (Personaje.getPersonaje().getGlobalBounds().intersects(mapa.getCastillo().getGlobalBounds()))
	{
		Juego_Terminado game({ 800,600 }, "Juego Terminado", ctime, Punto.getPuntos(), 1);
		Archivo archivo(ctime, Punto.getPuntos()+ctime*10);
		ventana.close();
	}
}
//-------------------------------------
void Juego::Muerte(sf::View& Cam)
{
	Cam.reset(sf::FloatRect(0, 0, 800, 600));
	Personaje.getPersonaje().setPosition(100, 400);
	mapa.getPuntaje().setPosition(630, 50);
	mapa.getPuntuacion().setPosition(545, 20);
	mapa.getText_Vidas().setPosition(100, 20);
	mapa.getVidas().setPosition(134, 50);
	mapa.getTiempo().setPosition(400, 50);
	mapa.getHora().setPosition(360, 20);
}
//-------------------------------------



