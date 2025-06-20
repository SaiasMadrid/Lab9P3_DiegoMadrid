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
	cin.ignore();
	getline(cin, nombre);

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
		idioma != "italiano" && idioma != "Italiano" && idioma != "espanol" && idioma != "Espanol") {
		cout << "Idioma invalido" << endl;
		return;
	}
	
	// crear pelicula temporal para poder calcular popularidad
	Pelicula tempMovie(nombre, genero, duracion, clasificacion, idioma, 0.0);
	popularidad = tempMovie.caclularPopularidad(genero, duracion, clasificacion, idioma);
	// pelicula con popularidad y tipo puntero para mandar al vector
	Pelicula* newMovie = new Pelicula(nombre, genero, duracion, clasificacion, idioma, popularidad);
	peliculas.push_back(newMovie);

	cout << "Pelicula agregada" << endl;
}

void Cine::listarPeliculas() {
	if (peliculas.empty()) {
		cout << "No tenes peliculas bro" << endl;
		return;
	}
	
	// listar crudo sin sort
	cout << "----- Peliculas -----\n" << endl;
	int cont = 0;
	for (Pelicula* movies : peliculas) {
		cout << cont << ") ";
		movies->toString();
		cout << endl;
		cont++;
	}
}

void Cine::ordenarDesc() {
	if (peliculas.empty()) {
		cout << "No hay peliculas guardadas" << endl;
		return;
	}

	// bubble sort para ordenar
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
	cout << "Pelicuas ordenadas descendentemente" << endl;
}

void Cine::ordenarAsc() {
	if (peliculas.empty()) {
		cout << "No hay peliculas guardadas" << endl;
		return;
	}

	// bubble sort para ordenar
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
	cout << "Pelicuas ordenadas ascendentemente" << endl;
}

void Cine::guardarPeliculas() {
	if (peliculas.empty() == true) {
		cout << "No tenes pelicilas" << endl;
		return;
	}

	ofstream file("Peliculas.txt");
	if (!file.is_open()) {
		cout << "Error al abrir el arcivo" << endl;
		return;
	}

	string str;
	file << "--> Titulo - Genero - Duracion - Clasificacion - Idioma - Popularidad <--" << endl;
	for (Pelicula* movies : peliculas) {
		file << movies->getTitulo() << ","
			<< movies->getGenero() << ","
			<< movies->getDuracion() << ","
			<< movies->getClasificacion() << ","
			<< movies->getIdioma() << ","
			<< movies->getPopularidad() << endl;
	}
	file.close();
	cout << "Peliculas guardadas en Peliculas.txt" << endl;
}

void Cine::cargarPeliculas() {
	peliculas.clear(); // evitar bulto

	ifstream file("Peliculas.txt");
	if (!file.is_open()) {
		cout << "Error al abrir el archivo para cargar" << endl;
		return;
	}

	string linea;
	getline(file, linea); // se salta la primera linea

	while (getline(file, linea)) {
		istringstream print(linea);
		string titulo, genero, duracionStr, clasificacion, idioma, popularidadStr;

		getline(print, titulo, ',');
		getline(print, genero, ',');
		getline(print, duracionStr, ',');
		getline(print, clasificacion, ',');
		getline(print, idioma, ',');
		getline(print, popularidadStr, ',');

		int duracion = stoi(duracionStr);
		double popularidad = stod(popularidadStr); // para conseguir los ints y doubles

		Pelicula* newMovie = new Pelicula(titulo, genero, duracion, clasificacion, idioma, popularidad);
		peliculas.push_back(newMovie); // se manda la pelicula leida
	}
	file.close();

	cout << "Peliculas cargadas en el vector" << endl;
}