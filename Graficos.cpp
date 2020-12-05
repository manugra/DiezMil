#include "Graficos.h"
#include "Funciones.h"
#include <cstdlib>

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

int menu() {
	int opcion;
	do {
		gotoxy(50, 2);  std::cout << "DIEZ MIL";
		gotoxy(4, 5); std::cout << "1.Modo un Jugador";
		gotoxy(4, 6); std::cout << "0.Salir";

		for (int y = 1; y < 20; y++)
		{
			gotoxy(0, y); printf("%c", 186);
			gotoxy(115, y); printf("%c", 186);
		}


		for (int x = 1; x < 115; x++) //Lineas Horizontales

		{
			gotoxy(0, 0); printf("%c", 201);//Esquina superior izquierda
			gotoxy(x, 0); printf("%c", 205); //Linea que va a lo largo por arriba
			gotoxy(115, 0); printf("%c", 187);//Esquina superior derecha

			//Hasta aca la linea de arriba

			gotoxy(0, 20); printf("%c", 200);
			gotoxy(x, 20); printf("%c", 205);
			gotoxy(115, 20); printf("%c", 188);
		}

		std::cout << "    Un jugador/salir(1/0): ";
		std::cin >> opcion;

		if (opcion == 1) return 1;
		else return 0;

	}

	while (opcion != 0);

	return opcion;
}


void game_over(bool primerJuego, std::string jugador, int rondas, std::string jugadorRecord, int record) {

	gotoxy(48, 4); std::cout << "FIN DEL JUEGO!";

	if (primerJuego) {
		gotoxy(4, 7); std::cout << "1." << jugador << " : " << rondas - 1 << " RONDAS";
	}
	else if (comparoRondas(rondas, record)==0) {
		gotoxy(4, 7); std::cout << "1." << jugador << " : " << rondas - 1 << " RONDAS";
		gotoxy(4, 8); std::cout << "2." << jugadorRecord << " : " << record - 1 << " RONDAS";

		gotoxy(4, 10); std::cout << "Felicitaciones! Superaste tu record!\n";
	}
	else if (comparoRondas(rondas, record)==1) {
		gotoxy(4, 7); std::cout << "1." << jugadorRecord << " : " << record - 1 << " RONDAS";
		gotoxy(4, 8); std::cout << "2." << jugador << " : " << rondas - 1 << " RONDAS";
		gotoxy(4, 10); std::cout << "Quedaste " << abs(record - rondas) << " por detras de tu record. \n";
	}
	else if (comparoRondas(rondas, record) == 2) {
		gotoxy(4, 7); std::cout << "1." << jugadorRecord << " : " << record - 1 << " RONDAS";
		gotoxy(4, 8); std::cout << "2." << jugador << " : " << rondas - 1 << " RONDAS";

		gotoxy(4, 10); std::cout << "Casi superas tu record!!!\n";
	}

	for (int y = 1; y < 20; y++)
	{
		gotoxy(0, y); printf("%c", 186);
		gotoxy(115, y); printf("%c", 186);
	}

	for (int x = 1; x < 115; x++) //Lineas Horizontales

	{
		gotoxy(0, 0); printf("%c", 201);//Esquina superior izquierda
		gotoxy(x, 0); printf("%c", 205); //Linea que va a lo largo por arriba
		gotoxy(115, 0); printf("%c", 187);//Esquina superior derecha

		//Hasta aca la linea de arriba

		gotoxy(0, 20); printf("%c", 200);
		gotoxy(x, 20); printf("%c", 205);
		gotoxy(115, 20); printf("%c", 188);
	}

}

void formaDeDado(int b) {//b es en que posicion de la pantalla se imprime el dado.
	for (int i = 0; i < 10; i++)//Linea Horizontal
	{
		gotoxy(i + 12 * b, 3); printf("%c", 220);
		gotoxy(i + 12 * b, 7); printf("%c", 220);

	}


	for (int i = 4; i < 8; i++) //Linea vertical
	{
		gotoxy(0 + 12 * b, i); printf("%c", 219);
		gotoxy(9 + 12 * b, i);  printf("%c", 219);
	}
}

/// SI TIENE dadito1, dadito2 o dadito3 NO HACE FALTA USAR formaDeDado!!


//EL PARAMETRO int a QUE RECIBEN LOS DADOS ES EN QUE POSICION VAN A MOSTRARSE EN LA PANTALLA
void dadito1(int a) {

	gotoxy(4 + 12 * a, 5); printf("%c", 254);//Puntito del centro

	formaDeDado(a);
}


void dadito2(int a) {

	gotoxy(7 + 12 * a, 6); printf("%c", 254);//Puntito esquina inferior derecha
	gotoxy(2 + 12 * a, 4); printf("%c", 254);//Puntito esquina superior izquierda

	formaDeDado(a);
}


void dadito3(int a) {

	dadito1(a);
	dadito2(a);

}


void dadito4(int a) {

	gotoxy(2 + 12 * a, 6); printf("%c", 254);//Puntito esquina inferior izquierda
	gotoxy(7 + 12 * a, 4); printf("%c", 254);//Puntito esquina superior derecha

	dadito2(a);

}


void dadito5(int a) {

	dadito1(a);
	dadito4(a);
}


void dadito6(int a) {

	gotoxy(2 + 12 * a, 5); printf("%c", 254);
	gotoxy(7 + 12 * a, 5); printf("%c", 254);

	dadito4(a);

}