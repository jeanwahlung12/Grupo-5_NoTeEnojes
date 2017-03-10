#pragma once
#include <iostream>
using namespace std;

class Piece(){
	protected:
		int x;
		int y;
	public :
		
		Piece(x,y);
		void setX(int);
		void setY(int);
		int getY();
		int getX();
		virtual void createTable();
		virtual bool validatecolor();
		//falta definir
		virtual void eat();
		~Piece();



};





