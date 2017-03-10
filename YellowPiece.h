#pragma once
#include "Piece.h"
using namespace std;

class YellowPiece : public Piece{
	public:
		YellowPiece(int, int);
		virtual bool validatecolor();
		virtual void createTable();
		virtual void eat();
		~YellowPiece();


};