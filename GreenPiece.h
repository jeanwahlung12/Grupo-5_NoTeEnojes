#pragma once
#include "Piece.h"
using namespace std;

class GreenPiece : public Piece{
	public:
		GreenPiece(int,int)
		virtual bool validatecolor();
		virtual void createTable();
		virtual void eat();
		~GreenPiece();


};