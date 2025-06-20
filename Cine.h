#pragma once
#include "Pelicula.h"
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Cine {
	vector<Pelicula*> peliculas;
public:
	Cine();
	~Cine();
	void agregarPelicula();
	void listarPeliculas();
	void ordenarDesc();
	void ordenarAsc();
	void guardarPeliculas();
	void cargarPeliculas();
};

