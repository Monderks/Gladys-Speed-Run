#include "Personaje.h"

#include <iostream>

void Personaje::setPersonaje()
{
    PersonajeTexture.loadFromFile("Resources\\SpritesCharacters\\Personaje.png");
    Personaje.setTexture(PersonajeTexture);

    Personaje.setPosition(100, 400);

    Personaje.setOrigin(30, 100);

    _velocidadSalto = 0;

    _estado.Quieto = true;
    _estado.Caminando_Adelante = false;
    _estado.Caminando_Atras = false;
    _estado.Adelante_Salto = false;
    _estado.Atras_Salto = false;
    _estado.Saltando = false;
}
//-------------------------------------
void Personaje::cmd()
{
    sf::Vector2u Tam = PersonajeTexture.getSize();

    Tam.x /= 8;
    Tam.y /= 1;

    static float frame = 0;

    frame += 0.15f;
    if (frame == 162.f)
    {
        frame = 0;
    }

    Personaje.setTextureRect(sf::IntRect(0, 0, Tam.x, Tam.y));

    if (_estado.Quieto) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            _estado.Quieto = false;
            _estado.Caminando_Adelante = false;
            _estado.Caminando_Atras = false;
            _estado.Adelante_Salto = false;
            _estado.Atras_Salto = false;
            _estado.Saltando = true;

            _velocidadSalto = 35;

        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        Personaje.setTextureRect(sf::IntRect(Tam.x * ((int)frame % 8), 0, Tam.x, Tam.y));
        Personaje.setScale(1, 1);
        _estado.Quieto = false;
        _estado.Caminando_Adelante = true;
        _estado.Caminando_Atras = false;
        _estado.Adelante_Salto = false;
        _estado.Atras_Salto = false;
        _estado.Saltando = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        Personaje.setTextureRect(sf::IntRect(Tam.x * ((int)frame % 8), 0, Tam.x, Tam.y));
        Personaje.setScale(-1, 1);

        _estado.Quieto = false;
        _estado.Caminando_Adelante = false;
        _estado.Caminando_Atras = true;
        _estado.Adelante_Salto = false;
        _estado.Atras_Salto = false;
        _estado.Saltando = false;
    }
    if (_estado.Quieto) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
        {
            _estado.Quieto = false;
            _estado.Caminando_Adelante = false;
            _estado.Caminando_Atras = false;
            _estado.Adelante_Salto = false;
            _estado.Atras_Salto = true;
            _estado.Saltando = false;

            _velocidadSalto = 35;
        }
    }
    if (_estado.Quieto) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
        {
            _estado.Quieto = false;
            _estado.Caminando_Adelante = false;
            _estado.Caminando_Atras = false;
            _estado.Adelante_Salto = true;
            _estado.Atras_Salto = false;
            _estado.Saltando = false;

            _velocidadSalto = 35;
        }
    }
}
void Personaje::update()
{
    if (_estado.Quieto)
    {
        Personaje.move(0, 0);
    }
    if (_estado.Caminando_Adelante)
    {
        Personaje.move(4, 0);
        _estado.Caminando_Adelante = false;
    }
    if (_estado.Caminando_Atras)
    {
        Personaje.move(-4, 0);
        _estado.Caminando_Atras = false;
    }
    if (_estado.Adelante_Salto)
    {
        Personaje.move(3, 0);
        _estado.Adelante_Salto = false;
    }
    if (_estado.Atras_Salto)
    {
        Personaje.move(-3, 0);
        _estado.Atras_Salto = false;
    }
    _velocidadSalto -= 2;
    Personaje.move(0, -_velocidadSalto);

}
//-------------------------------------
void Personaje::Quieto(float x, float y)
{
    _estado.Quieto = true;
    _velocidadSalto = 0;
    Personaje.setPosition(x, y);
}
//-------------------------------------
void Personaje::PerderVelocidad()
{
    _velocidadSalto = 0;
}
//-------------------------------------
sf::Sprite& Personaje::getPersonaje()
{
    return Personaje;
}
