// RedPiece.h

#pragma once

#include "Piece.h"

class RedPiece : public Piece {
	public:
		// Constructor.
		RedPiece(int, int);
		// Métodos polimórficos
		virtual void createTable();
		virtual bool validateColor();
		virtual void eat();
		// Destructor.
		~RedPiece();
};