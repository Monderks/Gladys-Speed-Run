#include "Vidas.h"

void Vidas::setVidas(int recibido)
{
	vidas += recibido;
}
//-------------------------------------
void Vidas::RestablecerVidas()
{
	vidas = 5;
}
//-------------------------------------
int& Vidas::getVidas()
{
	return vidas;
}
