// BluePiece.h

#pragma once

#include "Piece.h"

class BluePiece : public Piece {
	public:
		// Constructor.
		BluePiece(int, int);
		// Métodos polimórficos
		virtual void createTable();
		virtual bool validateColor();
		virtual void eat();
		// Destructor.
		~BluePiece();
};