#include "Pelicula.h"

Pelicula::Pelicula(string titulo, string genero, int duracion, string clasificacion, string idioma, double popularidad)
	: titulo(titulo), genero(genero), duracion(duracion), clasificacion(clasificacion), idioma(idioma), popularidad(popularidad) {
}

Pelicula::~Pelicula() {

}

double Pelicula::caclularPopularidad(const string& genero, int& duracion, const string& clasificacion, const string& idioma) {
	int basePopularidadGenero = 0;
	double factorDuracion = 0.5;
	int clasificacionFactor = 0;
	int factorClasificacion = 3;
	double factorIdioma = 0;

	if (genero == "Accion") {
		basePopularidadGenero = 100;
	}
	else if (genero == "Comedia") {
		basePopularidadGenero = 80;
	}
	else if (genero == "Drama") {
		basePopularidadGenero = 70;
	}

	if (clasificacion == "G") {
		clasificacionFactor = 0;
	}
	else if (clasificacion == "PG") {
		clasificacionFactor = 5;
	}
	else if (clasificacion == "PG-13") {
		clasificacionFactor = 10;
	}
	else if (clasificacion == "R") {
		clasificacionFactor = 15;
	}

	if (idioma == "Espaniol") {
		factorIdioma = 1.2;
	}
	else if (idioma == "Ingles") {
		factorIdioma = 1.0;
	}
	else if (idioma == "Frances") {
		factorIdioma = 0.9;
	}

	popularidad = (basePopularidadGenero + duracion * factorDuracion - clasificacionFactor * factorClasificacion) * factorIdioma;
	return popularidad;
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