#pragma once

class Puntos
{
private:
	int puntos = 0;
public:
	void setPuntos(int recibido);
	void restablecerPuntos();
	int &getPuntos();
};

