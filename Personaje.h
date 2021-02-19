#pragma once

#include <SFML\Graphics.hpp>

struct ESTADOS{
	bool Quieto;
	bool Caminando_Adelante;
	bool Caminando_Atras;
	bool Saltando;
	bool Adelante_Salto;
	bool Atras_Salto;
};

class Personaje
{
private:
	sf::Texture PersonajeTexture;
	sf::Sprite Personaje;

	ESTADOS _estado;
	float _velocidadSalto;
public:
	void setPersonaje();
	void cmd();
	void update();

	sf::Sprite& getPersonaje();
	void Quieto(float x, float y);
	void PerderVelocidad();
};

