#pragma once
#include "Piece.h"

class GreenPiece : public Piece{
	public:
		GreenPiece(int, int);
		virtual bool validatecolor();
		virtual void createTable();
		virtual void eat();
		~GreenPiece();


};