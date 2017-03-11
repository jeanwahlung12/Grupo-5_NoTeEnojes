#pragma once

#include <iostream>
#include <vector>

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
		virtual bool validateColor();
		virtual string** move(string**, int, int, int, string);
		virtual void eat(); //falta definir
		// Destructor.
		~Piece();
};





