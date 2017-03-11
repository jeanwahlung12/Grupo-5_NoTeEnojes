#include "Piece.h"

Piece::Piece(int x ,int y){
	this -> x = x;
	this -> y = y;

}

void Piece::setX(int x){
	this -> x = x;
}

void Piece::setY(int y) {
	this -> y = y;
}

int Piece::getX() {
	return x;
}

int Piece::getY() {
	return y;
}

void Piece::createTable(){

}

bool Piece::validateColor() {

}

string** Piece::move(string** matrix, int X, int Y, int dices) {
	int difference;

	if (X == 0) { // Arriba.
		difference = dices - Y;

		if (Y - dices < 0) { // Si se pasa de la izquierda.
			matrix[difference][0];
			setX(difference);
			setY(0);
		} else {
			matrix[X][difference];
			setY(difference);
		}
	} else if (X == 14) { // Abajo.
		difference = X - dices;

		if (Y + dices > 14) {
			matrix[difference][14];
			setX(difference);
			setY(14);
		} else {
			matrix[X][Y + dices + 1];
			setY(Y + dices);
		}
	} else if (Y == 0) { // Izquierda.
		difference = 14 - X;

		if (X + dices > 14) {
			matrix[14][difference];
			setY(difference);
			setX(14);
		} else {
			matrix[X + dices][Y];
			setX(X + dices);
		}
	} else if (Y == 14) { // Derecha.
		difference = 14 - dices + 1;

		if (X - dices < 0) {
			cout << "Diferencia: " << difference << endl;
			matrix[0][difference];
			setY(difference);
			setX(0);
		} else {
			matrix[X - dices][Y];
			setX(X - dices);
		}
	}

	cout << "Dices: " << dices << endl;
	cout << "X: " << getX() << " Y: " << getY() << endl;
}

//falta definir

void Piece::eat() {

}

Piece::~Piece() {

}