#include "Puntos.h"

void Puntos::setPuntos(int recibido)
{
	puntos += recibido;
}
//-------------------------------------
void Puntos::restablecerPuntos()
{
	puntos = 0;
}
//-------------------------------------
int &Puntos::getPuntos()
{
	return puntos;
}
