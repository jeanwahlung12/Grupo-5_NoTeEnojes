main:	Piece.o BluePiece.o RedPiece.o GreenPiece.o YellowPiece.o main.o
	g++ Piece.o BluePiece.o RedPiece.o GreenPiece.o YellowPiece.o main.o -o main

main.o:	main.cpp
	g++ -c main.cpp

# Piezas.

BluePiece.o:	BluePiece.h BluePiece.cpp Piece.h
	g++ -c BluePiece.cpp

RedPiece.o:	RedPiece.h RedPiece.cpp Piece.h
	g++ -c RedPiece.cpp

GreenPiece.o:	GreenPiece.h GreenPiece.cpp Piece.h
	g++ -c GreenPiece.cpp

YellowPiece.o:	YellowPiece.h YellowPiece.cpp Piece.h
	g++ -c YellowPiece.cpp

Piece.o:	Piece.h Piece.cpp
	g++ -c Piece.cpp

# Clean.

clean:	
	rm *.o main