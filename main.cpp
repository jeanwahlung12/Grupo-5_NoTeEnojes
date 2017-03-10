#include <iostream>
#include <ncurses.h>
#include "Piece.h"

string** initializeTable();// inicializa el tablero

int main(int argc, char const *argv[]) {
	string** matrix;

	matrix = initializeTable();
	
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
		
		cout << "" << endl;
		attroff(COLOR_PAIR(sub));
	}
	refresh();
	getch();
	endwin();
	
	return matrix;
}