#include "Mapa.h"

void Mapa::setMapa()
{
	//Fondo
	Fondo.loadFromFile("Resources\\SpritesMap\\Fondo.png");
	Fondito.setTexture(Fondo);
	//Castillo
	Castillito.loadFromFile("Resources\\SpritesMap\\Castillo.png");
	Castillo.setTexture(Castillito);
	Castillo.setScale(0.3,0.3);
	Castillo.setPosition(4300, 380);
	//Texto Puntuacion
	Fuente.loadFromFile("Resources\\Font\\Fuente.ttf");
	Puntuacion.setFont(Fuente);
	Puntuacion.setString("Puntuacion");
	Puntuacion.setCharacterSize(30);
	Puntuacion.setFillColor(sf::Color(11, 94, 146));
	Puntuacion.setPosition(545, 20);
	//Texto Puntaje "0"
	Puntaje.setFont(Fuente);
	Puntaje.setCharacterSize(30);
	Puntaje.setFillColor(sf::Color(11,94,146));
	Puntaje.setPosition(630, 50);
	//Texto Vidas
	Text_Vidas.setFont(Fuente);
	Text_Vidas.setString("Vidas");
	Text_Vidas.setCharacterSize(30);
	Text_Vidas.setFillColor(sf::Color(11, 94, 146));
	Text_Vidas.setPosition(100, 20);
	//Texto Vidas "3"
	Vida.setFont(Fuente);
	Vida.setCharacterSize(30);
	Vida.setFillColor(sf::Color(11, 94, 146));
	Vida.setPosition(134, 50);
	//Texto Tiempo
	Tiempo.setFont(Fuente);
	Tiempo.setCharacterSize(30);
	Tiempo.setFillColor(sf::Color(11, 94, 146));
	Tiempo.setPosition(400, 50);
	//Texto Tiempo "Tiempo"
	Hora.setString("Tiempo");
	Hora.setFont(Fuente);
	Hora.setCharacterSize(30);
	Hora.setFillColor(sf::Color(11, 94, 146));
	Hora.setPosition(360, 20);
	

}
//-------------------------------------
void Mapa::draw(sf::RenderWindow& window)
{
	//Marcadores en el Mapa
	//Puntajes-------------
	window.draw(Puntaje);
	window.draw(Puntuacion);
	//Vidas----------------
	window.draw(Vida);
	window.draw(Text_Vidas);
	window.draw(Tiempo);
	window.draw(Hora);
}
//-------------------------------------
sf::Sprite& Mapa::getFondo()
{
	return Fondito;
}
sf::Sprite& Mapa::getCastillo()
{
	return Castillo;
}
//-------------------------------------
sf::Text& Mapa::getPuntuacion()
{
	return Puntuacion;
}
sf::Text& Mapa::getVidas()
{
	return Vida;
}
sf::Text& Mapa::getText_Vidas()
{
	return Text_Vidas;
}
sf::Text& Mapa::getTiempo()
{
	return Tiempo;
}
sf::Text& Mapa::getHora()
{
	return Hora;
}
sf::Text& Mapa::getPuntaje()
{
	return Puntaje;
}



