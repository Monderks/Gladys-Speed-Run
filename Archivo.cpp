#include <iostream>
#include <cstdlib>
#include <stdio.h>

#include "Archivo.h"

Archivo::Archivo(int time, int puntos)
{
	FILE* archivo;

	archivo=fopen("Resources\\HighScore\\Data.dat", "rb");

	if (archivo == NULL)
	{
		alta_datos(time, puntos);

		return;
	}

	fclose(archivo);

	bool cargado = modificar_datos(time, puntos);

}
//-------------------------------------
Sts Archivo::ingreso_datos(int time, int score)
{
	Sts sts;

	sts._time = time;
	sts._score = score;

	return sts;
}
//-------------------------------------
void Archivo::alta_datos(int time, int score)
{
	Sts sts;
	sts = ingreso_datos(time, score);

	bool guardado = guardar_datos(sts);

	bool modificar = modificar_datos(time, score);
}
bool Archivo::guardar_datos(Sts sts)
{
	FILE* arc;
	bool guardado;
	arc = fopen("Resources\\HighScore\\Data.dat", "ab");

	if (arc == NULL)
	{
		return false;
	}

	guardado = fwrite(&sts, sizeof sts, 1, arc);

	fclose(arc);

	return guardado;
}
bool Archivo::modificar_datos(int time, int score)
{
	FILE* archivo;

	Sts sts;

	archivo = fopen("Resources\\HighScore\\Data.dat", "rb+");

	if (archivo == NULL)
	{
		return false;
	}

	while (fread(&sts, sizeof sts, 1, archivo) == 1)
	{
		if (score > sts._score || (score == sts._score && time > sts._time))
		{
			sts._score = score;
			sts._time = time;
			fseek(archivo, ftell(archivo) - sizeof sts, 0);
			fwrite(&sts, sizeof sts, 1, archivo);

			fclose(archivo);
			return true;
		}
	}

	fclose(archivo);
	return false;

}