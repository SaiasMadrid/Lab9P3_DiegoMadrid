#include "Pelicula.h"

Pelicula::Pelicula(string titulo, string genero, int duracion, string clasificacion, string idioma, double popularidad)
	: titulo(titulo), genero(genero), duracion(duracion), clasificacion(clasificacion), idioma(idioma), popularidad(popularidad) {
}

Pelicula::~Pelicula() {

}

double Pelicula::caclularPopularidad(const string& genero, int& duracion, const string& clasificacion, const string& idioma) {
	int basePopularidadGenero = 0;
	double factorDuracion = 0.5; // constante
	int clasificacionFactor = 0;
	double factorIdioma = 0;

	if (genero == "Accion" || genero == "accion") {
		basePopularidadGenero = rand() % 21 + 80;
	}
	else if (genero == "Comedia" || genero == "comedia") {
		basePopularidadGenero = rand() % 11 + 70;
	}
	else if (genero == "Drama" || genero == "drama") {
		basePopularidadGenero = rand() % 21 + 50;
	}

	if (clasificacion == "G" || clasificacion == "g") {
		clasificacionFactor = 0;
	}
	else if (clasificacion == "PG" || clasificacion == "pg") {
		clasificacionFactor = 5;
	}
	else if (clasificacion == "PG-13" || clasificacion == "pg-13") {
		clasificacionFactor = 10;
	}
	else if (clasificacion == "R" || clasificacion == "r") {
		clasificacionFactor = 15;
	}

	if (idioma == "Espaniol" || idioma == "espaniol" || idioma == "Español" || idioma == "español") {
		factorIdioma = 1.2;
	}
	else if (idioma == "Ingles" || idioma == "ingles") {
		factorIdioma = 1.0;
	}
	else if (idioma == "Italiano" || idioma == "italiano") {
		factorIdioma = 0.9;
	}

	popularidad = (basePopularidadGenero + duracion * factorDuracion - clasificacionFactor * clasificacionFactor) * factorIdioma;
	return abs(popularidad); // abs() porque me tira negativos por multiplicar clasificacionFactor 2 veces
}

string Pelicula::getTitulo() {
	return titulo;
}

string Pelicula::getGenero() {
	return genero;
}

int Pelicula::getDuracion() {
	return duracion;
}

string Pelicula::getClasificacion() {
	return clasificacion;
}

string Pelicula::getIdioma() {
	return idioma;
}

double Pelicula::getPopularidad() {
	return popularidad;
}

void Pelicula::toString() {
	cout << "Titulo: " << titulo << endl;
	cout << "Genero: " << genero << endl;
	cout << "Duracion: " << duracion << " minutos" << endl;
	cout << "Clasificacion: " << clasificacion << endl;
	cout << "Idioma: " << idioma << endl;
	cout << "Popularidad: " << popularidad << endl;
}