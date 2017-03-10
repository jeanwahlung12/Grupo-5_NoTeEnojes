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

bool Piece::validatecolor() {

}

//falta definir

void Piece::eat() {

}

Piece::~Piece() {

}