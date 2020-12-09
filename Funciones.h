#pragma once

#include <iostream>

#include <cstring>

#include <stdio.h>

#include <cstdlib>

#include <time.h>

#include <stdio.h>

#include <string>

#include <Windows.h>

using namespace std;

int numeroRandom();

int jugadas(int tirada[6]);//Busca las jugadas que se formaron y devuelve la de mayor puntaje.

int indiceJugadas(int tirada[6]);

int comparoRondas(int rondasActual, int rondasRecord);

int puntosJugada(int tirada[6]);

int jugada(int tirada[6]);
