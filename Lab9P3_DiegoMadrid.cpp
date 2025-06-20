#include <iostream>
#include "Cine.h"
using namespace std;

Cine absoluteCinema;

void menu() {

	int resp;
	bool menu = true; // Check para continuar con el menu
	while (menu == true) {
		cout << "---------- Menu ----------" << endl;
		cout << "1) Agregar Pelicula" << endl;
		cout << "2) Listar Peliculas" << endl;
		cout << "3) Ordenar Descendente" << endl;
		cout << "4) Ordenar Ascendente" << endl;
		cout << "5) Guardar Peliculas" << endl;
		cout << "6) Cargar Peliculas" << endl;
		cout << "7) Salir" << endl;
		cout << "Ingrese su seleccion: ";
		cin >> resp;
		cout << endl;

	
		switch (resp) {
		case 1:
			absoluteCinema.agregarPelicula();
			cout << endl;
			break;

		case 2:
			absoluteCinema.listarPeliculas();
			cout << endl;
			break;

		case 3:
			absoluteCinema.ordenarDesc();
			cout << endl;
			break;

		case 4:
			absoluteCinema.ordenarAsc();
			cout << endl;
			break;

		case 5:
			absoluteCinema.guardarPeliculas();
			cout << endl;
			break;

		case 6:
			absoluteCinema.cargarPeliculas();
			cout << endl;
			break;

		case 7:
			cout << "Cheque bro" << endl;
			menu = false; // Se rompe el while aca
			break;

		default:
			cout << "Invalido bro" << endl;
			return;
		}
	}
}

int main() {
	menu();
}