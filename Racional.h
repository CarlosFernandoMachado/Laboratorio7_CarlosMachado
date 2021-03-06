#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

class Racional{
public:
	int num, den;
	Racional(int=0, int=1);
	string toString();
	Racional operator-(Racional);
	Racional operator+(Racional);
	Racional operator*(Racional);
	Racional operator/(Racional);
	void simplificar();
	friend ostream& operator<<(ostream&, Racional&);
	friend istream& operator>>(istream&, Racional&);
};
