#include "Cine.h"

Cine::Cine() {
}

Cine::~Cine() {
	for (Pelicula* pelis : peliculas) {
		delete pelis;
	}
}

void Cine::agregarPelicula() {

}

void Cine::listarPeliculas() {

}

void Cine::ordenarDesc() {

}

void Cine::ordenarAsc() {

}

void Cine::guardarPeliculas() {

}

void Cine::cargarPeliculas() {

}