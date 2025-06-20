#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Pelicula {
	string titulo;
	string genero;
	int duracion;
	string clasificacion;
	string idioma;
	double popularidad;
public:
	Pelicula(string titulo, string genero, int duracion, string clasificacion, string idioma, double popularidad);
	~Pelicula();
	double caclularPopularidad(const string& genero, int& duracion, const string& clasificacion, const string& idioma);
	string getTitulo();
	string getGenero();
	int getDuracion();
	string getClasificacion();
	string getIdioma();
	double getPopularidad();
	void toString();
};

