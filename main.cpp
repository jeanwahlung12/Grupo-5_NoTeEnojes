#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "Piece.h"
#include "BluePiece.h"
#include "GreenPiece.h"
#include "YellowPiece.h"
#include "RedPiece.h"

// Inicializa el tablero.
string** initializeTable();
// Aleatorio del dado.
int getDice();
// Hacer movimientos.
string** move(string**, int, int);
// Para iniciar pieza.
bool setNewPiece(int);

int main() {
	string** matrix;
	vector<Piece*> player1;
	vector<Piece*> player2;
	int dice1, dice2, dices, option, turn = 0, COUNT1 = 0, COUNT2 = 0;

	cout << "(Jugador 1) Ingrese color de fichas:";
	cout << "\n1) Verde. \n2) Rojo. \n3) Azul. \n4) Amarillo. \nOpción: ";
	cin >> option;

	if (option == 1) {
		for (int i = 0; i < 4; ++i) {
			Piece* greenPiece = new GreenPiece(0, 0);
			player1.push_back(greenPiece);
		}
	} else if (option == 2) {
		for (int i = 0; i < 4; ++i) {
			Piece* redPiece = new RedPiece(0, 14);
			player1.push_back(redPiece);
		}
	} else if (option == 3) {
		for (int i = 0; i < 4; ++i) {
			Piece* bluePiece = new BluePiece(14, 14);
			player1.push_back(bluePiece);
		}
	} else if (option == 4) {
		for (int i = 0; i < 4; ++i) {
			Piece* yellowPiece = new YellowPiece(14, 0);
			player1.push_back(yellowPiece);
		}
	} else {
		main();
	}

	cout << "(Jugador 2) Ingrese color de fichas:";
	cout << "\n1) Verde. \n2) Rojo. \n3) Azul. \n4) Amarillo. \nOpción: ";
	cin >> option;

	if (option == 1) {
		for (int i = 0; i < 4; ++i) {
			Piece* greenPiece = new GreenPiece(0, 0);
			player2.push_back(greenPiece);
		}
	} else if (option == 2) {
		for (int i = 0; i < 4; ++i) {
			Piece* redPiece = new RedPiece(0, 14);
			player2.push_back(redPiece);
		}
	} else if (option == 3) {
		for (int i = 0; i < 4; ++i) {
			Piece* bluePiece = new BluePiece(14, 14);
			player2.push_back(bluePiece);
		}
	} else if (option == 4) {
		for (int i = 0; i < 4; ++i) {
			Piece* yellowPiece = new YellowPiece(14, 0);
			player2.push_back(yellowPiece);
		}
	} else {
		main();
	}

	matrix = initializeTable();

	Piece* piece;

	do {
		dice1 = getDice();
		dice2 = getDice();
		dices = dice1 + dice2;
		cout << dices;

		if (turn % 2 == 0) { // Turno jugador 1.
			if (setNewPiece(dices) && COUNT1 < 4) {
				piece = player1.at(COUNT1);

				matrix[piece -> getX()][piece -> getY()] = "+";
				cout << "PLAYER1";
				COUNT1++;
			} else {
				cout << "NO!";
			}
		} else { // Turno jugador 2.
			if (setNewPiece(dices) && COUNT2 < 4) {
				piece = player2.at(COUNT2);

				matrix[piece -> getX()][piece -> getY()] = "-";
				cout << "PLAYER2";
				COUNT2++;
			} else {
				cout << "BYE!";
			}
		}

		turn++;
	} while (!setNewPiece(dices));

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			cout << matrix[i][j];
		}
	}
	return 0;
}

string** initializeTable(){
	string** matrix = new string*[15];

	for (int i = 0; i < 15; ++i) {
		matrix[i]= new string[15];// inicializando matriz
	}

	initscr();
   	start_color();

	//llenar Matriz
	int sub;
	init_pair(1, COLOR_WHITE, COLOR_GREEN);
	init_pair(2, COLOR_WHITE, COLOR_RED);
	init_pair(3, COLOR_WHITE, COLOR_YELLOW);
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_BLACK, COLOR_BLACK);


	for (int i = 0; i < 15; ++i){
		for (int j = 0; j < 15; ++j){
			if ((i == 0 && j == 0) || (i == 7 && j < 7)) { // Verde.
				sub = 1;
				attron(COLOR_PAIR(sub));
    			mvprintw(i,j," ");
			} else if ((i == 0 && j == 14) || (i < 7 && j == 7)) { // Rojo.
    			sub = 2;
    			attron(COLOR_PAIR(sub));
    			mvprintw(i,j," ");
			} else if ((i == 14 && j == 0)|| (i > 7 && j == 7)) { // Amarillo.
    			sub = 3;
    			attron(COLOR_PAIR(sub));
    			mvprintw(i,j," ");
			} else if ((i == 14 && j == 14) || (i == 7 && j > 7)) { // Azul.
				sub = 4;
    			attron(COLOR_PAIR(sub));
    			mvprintw(i,j," ");
			} else if(i==0 || j==0 || i==14 || j==14) { // Blanco.
				sub = 5;
    			attron(COLOR_PAIR(sub));
    			mvprintw(i,j," ");
			} else { // Negro.
				sub = 6;
    			attron(COLOR_PAIR(sub));
    			mvprintw(i,j," ");
			}
		}
		
		attroff(COLOR_PAIR(sub));
	}

	refresh();
	getch();
	endwin();
	
	return matrix;
}

int getDice() {
	int dice;

	srand(time(NULL));

	dice = rand() % 7 + 1;

	return dice;
}

bool setNewPiece(int dices) {
	if (dices == 12 || dices == 2) {
		return true;
	} else {
		return false;
	}
}