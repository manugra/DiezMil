// DiezMil.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <cstring>

#include <stdio.h>

#include <cstdlib>

#include <time.h>

#include <stdio.h>

#include <string>

#include <Windows.h>

using namespace std;

#include "Graficos.h"

#include "Funciones.h"



int main() {

	srand(time(NULL));

	int menuMain;

	menuMain = menu();

	std::system("cls");


	int tirada[6];//Contiene los dados que salieron.
	string nombres[] = { "Juego de 1", "Juego de 5", "Trio 1", "Trio X", "Trio X++", "Trio 1 Ampliado", "Tres pares", "Escalera larga", "Sexteto" ,"Nula" };

	char jugador[25];

	//Donde guardo los datos de la mejor partida
	char jugadorRecord[25];
	int record;
	//



	int cr = 1;//Contador de rondas
	int puntos = 0;//Puntos de la ronda
	int puntos_ronda = 0;//Puntos acumulados de la ronda
	int puntos_totales = 0;



	int opcion1=1;//Si se lanza de nuevo o se termina la ronda.
	int menu_final = 1; //Si se juega de nuevo o se cierra el programa en el menu "game_over"

	bool primerJuego = true;


	while (menu_final == 1) {


		if (menuMain == 0) {
			std::system("cls");
			return 0; //Si elige salir se termina el programa
		}


		std::system("cls");

		std::cout << "----------------------------------------------------------------------------------\n";
		std::cout << "Ingrese su nombre(sin espacios): ";//SOLO PERMITE NOMBRES SIN ESPACIOS
		std::cin >> jugador;

		std::system("pause");
		std::system("cls");


		while (puntos_totales != 10000) {


			while (opcion1 == 1) {


				std::cout << "TURNO DE " << jugador; std::cout << "      |   RONDA N " << cr << "     " << endl; //POR ACA SE MUESTRA EL PUNTAJE(LINEA 151)
				std::cout << "-----------------------------------------------------------------------------------------------------------------";

				for (int i = 0; i < 6; i++)//TIRO LOS 6 DADOS
				{
					
					tirada[i] = numeroRandom();
					

					switch (tirada[i])
					{
					case(1): dadito1(i); break;//En la primer vuelta se imprimen en la primer posicion(i=0), en la segunda vuelta en la segunda posicion(i=1),etc.

					case(2): dadito2(i); break;

					case(3): dadito3(i); break;

					case(4): dadito4(i); break;

					case(5): dadito5(i); break;

					case(6): dadito6(i); break;

					default: std::cout << "ERROR";  return 0;
						break;
					}
				}
					

				std::cout << endl;
				//puntos = jugadas(tirada);
				puntos = puntosJugada(tirada);
				puntos_totales += puntos;
				puntos_ronda += puntos;

				if (puntos == 0) {

					
					puntos_totales -= puntos_ronda;
					
					//puntos_ronda = 0; //Si no hay combinacion ganadora, el jugador pierde todos los puntos.
					//opcion1 = 0;//Mas abajo pregunto el valor de esto para cortar el while
					std::cout << "\nJugada nula. Perdiste tus puntos acumulados. Lo siento campeon!\n";
					std::cout << "Continua para lanzar de nuevo!\n";
					system("pause");
					break;
				}
			

				if (puntos_totales > 10000) {

					puntos_totales -= puntos_ronda;
					//Los puntos no se suman y pierdo el turno
					//opcion1 = 0;
					gotoxy(0, 14); std::cout << "Te excediste de diez mil. Perdiste tus puntos acumulados! :(\n";
					gotoxy(0, 15); std::cout << "Continua para lanzar de nuevo. \n";
					system("pause");
					break;
					
				}

				gotoxy(43, 0); std::cout << "|    PUNTAJE TOTAL " << puntos_totales;

				gotoxy(0, 10); std::cout << "La jugada es " << nombres[jugada(tirada)] << "!  +" << puntos << "!" << endl;

				gotoxy(0, 12); std::cout << "Puntaje de la ronda: "<< puntos_ronda << endl;


				if (puntos_totales == 10000) {

					cout << "Felicitaciones! Has Ganado el Diez Mil. Digite el 0 para salir..."; cin >> opcion1;
				}

				else {
					std::cout << "Lanzar de nuevo/Finalizar ronda(1/0): "; std::cin >> opcion1;
				}

				
				std::system("pause");
				std::system("cls");

			}
			std::system("cls");
			if (puntos_totales != 10000) {
				
				opcion1 = 1;
			}

			puntos_ronda = 0;
		
			cr++;

		}

		if (primerJuego == true) {
			strcpy(jugadorRecord, jugador);
			record = cr;
		}
	
		game_over(primerJuego, jugador, cr, jugadorRecord, record);
			primerJuego = false;


		std::cout << "\nJugar de nuevo/Salir del juego(1/0): "; std::cin >> menu_final;

		puntos_totales = 0;
		opcion1 = 1;
		cr = 1;
		std::system("cls");
	}
}//FIN DEL MAIN













