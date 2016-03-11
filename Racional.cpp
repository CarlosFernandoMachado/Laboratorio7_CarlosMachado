#include <iostream>
#include "Racional.h"
#include <string>
#include<sstream>

using std::stringstream;
using std::cout;
using std::string;
using std::ostream;
using std::istream;

Racional::Racional(int num, int den){
	if(den == 0){
		this->den = 1;
		this->num = num;
	}else if(den < 0){
		this->den = den*-1;
		this->num = num*-1;
	}else{
		this->num = num;
		this->den = den;
	}
	
}
string Racional::toString(){
	stringstream ss;
	if(den == 1){
		ss << num;
	}else{
		ss << num << "/" << den;
	}
	return ss.str();
}
Racional Racional::operator-(Racional r){
	if(den == r.den){
		Racional retval(num-r.num,den);
		return retval;
	}else{
		Racional retval((num*r.den)-(r.num*den),den*r.den);
		return retval;
	}
}
Racional Racional::operator+(Racional r){
	if(den == r.den){
		Racional retval(num+r.num,den);
		return retval;
	}
	else{
		Racional retval((num*r.den)+(r.num*den),den*r.den);
		return retval;
	}
}
Racional Racional::operator*(Racional r){
	Racional retval(num*r.num,den*r.den);
	return retval;
}
Racional Racional::operator/(Racional r){
	Racional retval(num*r.den,r.num*den);	
	return retval;
}
void Racional::simplificar(){
	if(den == 1){
		
	}else{
		int b = 2;
		while(b <= num){
			if(den % b == 0 && num % b == 0){
				den = den / b;
				num = num / b;
			}else{
				b++;
			}
		}
	}
}
ostream& operator<<(ostream& output, Racional& r){
	if(r.den == 1){
		output << r.num;
	}else{
		output << r.num << "/" << r.den;
	}
	return output;
}
istream& operator>>(istream& input, Racional& r){
	input >> r.num >> r.den;
	return input;
}
