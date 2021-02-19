#pragma once

class Vidas
{
private:
	int vidas = 5;
public:
	void setVidas(int recibido);
	void RestablecerVidas();
	int& getVidas();
};

