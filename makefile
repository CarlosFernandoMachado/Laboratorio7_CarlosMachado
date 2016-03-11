main: main.o Racional.o
	g++ main.o Racional.o -o a 
	
main.o:	main.cpp Racional.h
	g++ -c main.cpp 

Racional.o:	Racional.cpp Racional.h
	g++ -c Racional.cpp 
