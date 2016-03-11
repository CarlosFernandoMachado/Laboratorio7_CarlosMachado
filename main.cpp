#include<iostream>
#include<vector>
#include<string>
#include "Racional.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

void historial(vector<string>&);
Racional dividir(vector<Racional>&,int,int,vector<string>&);
Racional multiplicar(vector<Racional>&,int,int,vector<string>&);
Racional restar(vector<Racional>&,int,int,vector<string>&);
Racional sumar(vector<Racional>&,int,int,vector<string>&);
void imprimir(vector<Racional>&);
void nuevo(vector<Racional>&);

int main(int argc, char*argv[]){
	int choice1,choice2;
	Racional resp;
	bool valida = true;
	vector<Racional> numeros;
	vector<string> operaciones;
	int menu = 1;
	while(menu){
		cout << "\n0-Salir\n1-Crear Racionales\n2-Sumar Racionales\n3-restar Racionales\n4-Multiplicar Racionales\n5-Dividir Racionales\n6-Historial" << endl;
		cin >> menu;
		if(menu == 1){
			nuevo(numeros);
			cout << "Se ha agregado con exito!!" << endl;
		}else if(menu == 2){
			while(valida){
				imprimir(numeros);
				cout << "Escoja la posicion de un Racional: ";
				cin >> choice1;
				cout << "Escoja la posicion de otro Racional: ";
				cin >> choice2;
				if((choice1 > -1 && choice1 < numeros.size()) && (choice2 > -1 && choice2 < numeros.size()))
					valida = false;
			}
			valida = true;
			resp = sumar(numeros,choice1,choice2,operaciones);
			cout << "El resultado de la suma es: " << resp;
		}else if(menu == 3){
			while(valida){
				imprimir(numeros);
				cout << "Escoja la posicion de un Racional: ";
				cin >> choice1;
				cout << "Escoja la posicion de otro Racional: ";
				cin >> choice2;
				if((choice1 > -1 && choice1 < numeros.size()) && (choice2 > -1 && choice2 < numeros.size()))
					valida = false;
			}
			valida = true;
			resp = restar(numeros,choice1,choice2,operaciones);	
			cout << "El resultado de la resta es: " << resp;		
		}else if(menu == 4){
			while(valida){
				imprimir(numeros);
				cout << "Escoja la posicion de un Racional: ";
				cin >> choice1;
				cout << "Escoja la posicion de otro Racional: ";
				cin >> choice2;
				if((choice1 > -1 && choice1 < numeros.size()) && (choice2 > -1 && choice2 < numeros.size()))
					valida = false;
			}
			valida = true;
			resp = multiplicar(numeros,choice1,choice2,operaciones);		
			cout << "El resultado de la multiplicacion es: " << resp;	
		}else if(menu == 5){
			while(valida){
				imprimir(numeros);
				cout << "Escoja la posicion de un Racional: ";
				cin >> choice1;
				cout << "Escoja la posicion de otro Racional: ";
				cin >> choice2;
				if((choice1 > -1 && choice1 < numeros.size()) && (choice2 > -1 && choice2 < numeros.size()))
					valida = false;
			}
			valida = true;
			resp = dividir(numeros,choice1,choice2,operaciones);	
			cout << "El resultado de la division es: " << resp;		
		}else if(menu == 6){
			historial(operaciones);
		}
	}
	return 0;
}
void historial(vector<string>& operaciones){
	for(int i = 0; i < operaciones.size(); i++){
		cout << operaciones[i] << endl;
	}
}
Racional dividir(vector<Racional>& numeros,int choice1,int choice2,vector<string>& operaciones){
	Racional resp = numeros[choice1] / numeros[choice2];
	resp.simplificar();
	string operacion = numeros[choice1].toString() + " / " + numeros[choice2].toString() + " = " + resp.toString();
	operaciones.push_back(operacion);
	return resp;
}
Racional multiplicar(vector<Racional>& numeros,int choice1,int choice2,vector<string>& operaciones){
	Racional resp = numeros[choice1] * numeros[choice2];
	resp.simplificar();
	string operacion = numeros[choice1].toString() + " * " + numeros[choice2].toString() + " = " + resp.toString();
	operaciones.push_back(operacion);
	return resp;
}
Racional restar(vector<Racional>& numeros,int choice1,int choice2,vector<string>& operaciones){
	Racional resp = numeros[choice1] - numeros[choice2];
	resp.simplificar();
	string operacion = numeros[choice1].toString() + " - " + numeros[choice2].toString() + " = " + resp.toString();
	operaciones.push_back(operacion);
	return resp;
}
Racional sumar(vector<Racional>& numeros,int choice1,int choice2,vector<string>& operaciones){
	Racional resp = numeros[choice1] + numeros[choice2];
	resp.simplificar();
	string operacion = numeros[choice1].toString() + " + " + numeros[choice2].toString() + " = " + resp.toString();
	operaciones.push_back(operacion);
	return resp;
}
void imprimir(vector<Racional>& numeros){
	for(int i = 0; i < numeros.size(); i++){
		cout << "Posicion: " << i << " " << numeros[i].toString() << endl;
	}
}
void nuevo(vector<Racional>& numeros){
	int num,den;
	cout << "Ingrese el numerador: ";
	cin >> num;
	cout << "Ingrese el denominador: ";
	cin >> den;
	Racional neww(num,den);
	neww.simplificar();
	numeros.push_back(neww);
}
