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

int getX() {
	return x;
}

int getY() {
	return y;
}

virtual void createTable(){

}

virtual bool validatecolor() {

}

//falta definir

virtual void eat() {

}

~Piece() {

}