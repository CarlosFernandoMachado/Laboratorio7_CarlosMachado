#pragma once

class Racional{
	int num, den;
public:
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
