#pragma once

#include <iostream>

using namespace std;

class Piece {
	protected:
		int x;
		int y;

	public:
		// Constructor.
		Piece(int, int);
		// Setters.
		void setX(int);
		void setY(int);
		// Getters.
		int getY();
		int getX();
		// Métodos polimórficos.
		virtual void createTable();
		virtual bool validatecolor();
		virtual void eat(); //falta definir
		// Destructor.
		~Piece();
};





