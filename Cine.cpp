#include "Cine.h"

Cine::Cine() {
}

Cine::~Cine() {
	for (Pelicula* pelis : peliculas) {
		delete pelis;
	}
}

void Cine::agregarPelicula() {
	srand(time(0));
	string nombre, genero, clasificacion, idioma;
	int duracion = rand() % 121 + 60;
	double popularidad;

	cout << "Ingrese el nombre de la pelicula: ";
	cin >> nombre;
	cout << "Ingrese el genero (Accion, Comedia, Drama): ";
	cin >> genero;
	if (genero != "Accion" && genero != "Comedia" && genero != "Drama" &&
		genero != "accion" && genero != "comedia" && genero != "drama") {
		cout << "Genero invalido" << endl;
		return;
	}
	cout << "Ingrese la clasificacion (G, PG, PG-13, R): ";
	cin >> clasificacion;
	if (clasificacion != "g" && clasificacion != "G" && clasificacion != "pg" && clasificacion != "PG" &&
		clasificacion != "pg-13" && clasificacion != "PG-13" && clasificacion != "r" && clasificacion != "R") {
		cout << "Clasificacion Invalida" << endl;
		return;
	}
	cout << "Ingrese el idioma (Espaniol, Ingles, Italiano): ";
	cin >> idioma;
	if (idioma != "espaniol" && idioma != "Espaniol" && idioma != "ingles" && idioma != "Ingles" &&
		idioma != "frances" && idioma != "Frances" && idioma != "español" && idioma != "Español") {
		cout << "Idioma invalido" << endl;
		return;
	}

	Pelicula tempMovie(nombre, genero, duracion, clasificacion, idioma, 0.0);
	popularidad = tempMovie.caclularPopularidad(genero, duracion, clasificacion, idioma);
	Pelicula* newMovie = new Pelicula(nombre, genero, duracion, clasificacion, idioma, popularidad);
	peliculas.push_back(newMovie);
}

void Cine::listarPeliculas() {
	if (peliculas.empty()) {
		cout << "No tenes peliculas bro" << endl;
		return;
	}

	for (Pelicula* movies : peliculas) {
		movies->toString();
	}
}

void Cine::ordenarDesc() {
	if (peliculas.empty()) {
		cout << "No hay peliculas guardadas" << endl;
		return;
	}

	int pelis = peliculas.size();
	for (int i = 0; i < pelis - 1; i++) {
		for (int j = 0; j < pelis - i - 1; j++) {
			if (peliculas[j]->getPopularidad() > peliculas[j + 1]->getPopularidad()) {
				Pelicula* temp = peliculas[j];
				peliculas[j] = peliculas[j + 1];
				peliculas[j + 1] = temp;
			}
		}
	}
}

void Cine::ordenarAsc() {
	if (peliculas.empty()) {
		cout << "No hay peliculas guardadas" << endl;
		return;
	}

	int pelis = peliculas.size();
	for (int i = 0; i < pelis - 1; i++) {
		for (int j = 0; j < pelis - i - 1; j++) {
			if (peliculas[j]->getPopularidad() < peliculas[j + 1]->getPopularidad()) {
				Pelicula* temp = peliculas[j];
				peliculas[j] = peliculas[j + 1];
				peliculas[j + 1] = temp;
			}
		}
	}
}

void Cine::guardarPeliculas() {

}

void Cine::cargarPeliculas() {

}