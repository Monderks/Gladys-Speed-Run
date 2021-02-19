#pragma once

#include <SFML\Graphics.hpp>

struct Sts
{
	int _time;
	int _score;
};
class Archivo
{
private:
	Sts sts;

public:
	Archivo(int time, int puntos);
	Sts ingreso_datos(int time, int score);
	void alta_datos(int time, int score);
	bool guardar_datos(Sts sts);
	bool modificar_datos(int time, int score);
};

