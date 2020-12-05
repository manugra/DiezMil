#include "Funciones.h"

int numeroRandom() {

	return rand() % 6 + 1;
}

int jugadas(int tirada[6]) {//RECIBE COMO PARAMETRO EL ARRAY CON CADA UNO DE LOS DADOS LANZADOS

	int combinacion[9] = { 0 }; //Todas las jugadas. En cada indice sumo los puntos de su jugada correspondiente para despues buscar el mayor.
	int contador[6] = { 0 };//Cuenta cuantos dados hubo de cada valor.
	int mayorJugada = 0;//Guarda el elemento de mayor valor del array "combinacion".

	for (int i = 0; i < 6; i++)
	{
		if (tirada[i] == 1) contador[0]++;//Se suma uno al dado 1

		if (tirada[i] == 2) contador[1]++;//Se suma uno al dado 2

		if (tirada[i] == 3) contador[2]++;//etc.

		if (tirada[i] == 4) contador[3]++;

		if (tirada[i] == 5) contador[4]++;

		if (tirada[i] == 6) contador[5]++;

	}

	/****************Jugadas con el 1****************/
	if (contador[0] == 6) combinacion[8] = 10000;//Sexteto

	else if (contador[0] == 4 || contador[0] == 5) combinacion[5] = 2000;//Trio 1 ampliado

	else if (contador[0] == 3) combinacion[2] = 1000;//Trio 1


	else if (contador[0] == 2) combinacion[0] = 100 * 2;//Juego de 1

	else if (contador[0] == 1) combinacion[0] = 100;//Juego de 1
	/*************************************************/



	/**************Escalera Real**********************/

	//int nAnt = tirada[0];															
	bool escalera = true; //Si cambia a false es que no hay escalera				

	for (int i = 0; i < 6; i++)
	{
		if (contador[i] != 1)	escalera = false;

	}

	if (escalera) combinacion[7] = 1500;
	/*************************************************/



	/********************Trio X**********************/
	for (int i = 1; i < 6; i++)
	{
		if (contador[i] == 3) combinacion[3] = (i + 1) * 100;
	}
	/************************************************/



	/******************Trio X++*********************/
	for (int i = 1; i < 6; i++)
	{
		if (contador[i] == 4 || contador[i] == 5) combinacion[4] = tirada[i] * 200;
	}
	/***********************************************/



	/****************Juego de 5********************/
	if (contador[4] == 1) combinacion[1] = 50;

	else if (contador[4] == 2) combinacion[1] = 50 * 2;
	/**********************************************/



	/****************Tres Pares*********************/
	int cp = 0;//Contador de pares.
	bool seisIguales = false;


	for (int i = 0; i < 5; i++)
	{
		if (contador[i] == 2)
		{
			cp++;

		}
		else if (contador[i] == 6)
		{
			seisIguales = true;
		}

		if (cp == 3 || seisIguales == true) combinacion[6] = 1000;

	}
	/*************************************************/

	for (int i = 0; i < 9; i++)
	{
		if (combinacion[i] > mayorJugada)
		{
			mayorJugada = combinacion[i];

		}
	}

	return mayorJugada;
}

int indiceJugadas(int tirada[6]) {

	int combinacion[9] = { 0 }; //Todas las jugadas. En cada indice sumo los puntos de su jugada correspondiente para despues buscar el mayor.
	int contador[6] = { 0 };//Cuenta cuantos dados hubo de cada valor.
	int mayorJugada = 0;//Guarda el elemento de mayor valor del array "combinacion".

	for (int i = 0; i < 6; i++)
	{
		if (tirada[i] == 1) contador[0]++;//Se suma uno al dado 1

		if (tirada[i] == 2) contador[1]++;//Se suma uno al dado 2

		if (tirada[i] == 3) contador[2]++;//etc.

		if (tirada[i] == 4) contador[3]++;

		if (tirada[i] == 5) contador[4]++;

		if (tirada[i] == 6) contador[5]++;

	}

	/****************Jugadas con el 1****************/
	if (contador[0] == 6) combinacion[8] = 10000;//Sexteto

	else if (contador[0] == 4 || contador[0] == 5) combinacion[5] = 2000;//Trio 1 ampliado

	else if (contador[0] == 3) combinacion[2] = 1000;//Trio 1


	else if (contador[0] == 2) combinacion[0] = 100 * 2;//Juego de 1

	else if (contador[0] == 1) combinacion[0] = 100;//Juego de 1
	/*************************************************/



	/**************Escalera Real**********************/

	bool escalera = true; //Si cambia a false es que no hay escalera
				

	for (int i = 0; i < 6; i++)
	{
		if (contador[i] != 1)	escalera = false;

	}

	if (escalera) combinacion[7] = 1500;
	/*************************************************/



	/********************Trio X**********************/
	for (int i = 1; i < 6; i++)
	{
		if (contador[i] == 3) combinacion[3] = tirada[i] * 100;
	}
	/************************************************/



	/******************Trio X++*********************/
	for (int i = 1; i < 6; i++)
	{
		if (contador[i] == 4 || contador[i] == 5) combinacion[4] = tirada[i] * 200;
	}
	/***********************************************/



	/****************Juego de 5********************/
	if (contador[4] == 1) combinacion[1] = 50;

	else if (contador[4] == 2) combinacion[1] = 50 * 2;
	/**********************************************/



	/****************Tres Pares*********************/
	int cp = 0;//Contador de pares.
	bool seisIguales = false;


	for (int i = 0; i < 5; i++)
	{
		if (contador[i] == 2)
		{
			cp++;

		}
		else if (contador[i] == 6)
		{
			seisIguales = true;
		}

		if (cp == 3 || seisIguales == true) combinacion[6] = 1000;

	}
	/*************************************************/
	int indiceMayor = 9;//Guarda el indice de la combinacion con valor mas alto.

	for (int i = 0; i < 9; i++)
	{
		if (combinacion[i] > mayorJugada)
		{
			mayorJugada = combinacion[i];
			indiceMayor = i;

		}
	}


	return indiceMayor;
}

int comparoRondas(int rondasActual, int rondasRecord) {
	//0 Si rondasActual es mayor a rondasRecord, 1 si rondasActual es menor a rondasRecord, 2 si son iguales


	if (rondasActual < rondasRecord) {
		rondasRecord = rondasActual;
		return 0;
	}
	else if (rondasActual > rondasRecord) {
		return 1;
	}
	else if (rondasActual == rondasRecord) {
		return 2;
	}


}