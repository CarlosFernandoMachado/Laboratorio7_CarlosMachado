#include <iostream>
#include "racional.h"

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
	if(den == 1){
		cout << num;
	}else{
		cout << num << "/" << den;
	}
}
Racional Racional::operator-(Racional r){
	if(den == r.den){
		return (num-r.num,den);
	}else{
		return ((num*r.den)-(r.num*den),den*r.den);
	}
}
Racional Racional::operator+(Racional r){
	if(den == r.den){
		return (num+r.num,den);
	}else{
		return ((num*r.den)+(r.num*den),den*r.den);
	}
}
Racional Racional::operator*(Racional r){
	return (num*r.num,den*r.den);
}
Racional Racional::operator/(Racional r){
	return (num*r.den,r.num*den);
}
void Racional::simplificar(){
	if(den==1){
		
	}else{
		int b=2;
		while(b<=num){
			if(den%b==0 && num%b==0){
				den=den/b;
				num=num/b;
			}else{
				b++;
			}
		}
	}
}
ostream& operator<<(ostream& output, Racional r){
	if(den == 1){
		output << num;
	}else{
		output << num << "/" << den;
	}
	return output;
}
istream& operator>>(istream& input, Racional r){
	input >> r.num >> r.den;
	return input;
}
