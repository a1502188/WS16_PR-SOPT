#include <iostream>
#include <istream>
#include <cassert>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <limits>

#include "Funktion.h"	

using namespace std;

class polynom1d : public Funktion {
	uint64_t n; // Grad des Polynoms

	/*
	 * Die Koeffizienten und Exponenten des Polynoms werden in der mx2 Matrix
	 * poly gepeichert.
	 * Die Koeffizienten in der ersten Spalte, die zugehörigen Exponenten in 
	 * der zweiten Spalte.
	*/
	vector<vector<int64_t> > poly;

public:
	polynom1d() : n(0) {
		cerr << "Falscher Konstruktor" << endl;
	}

	polynom1d(istream& in) : n(0) {
	//	cout << "Richtiger Konstruktor" << endl;
		string a;
		int len;
		vector<uint8_t> n;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(in, a);
		len = a.length();

	//	cout << a << endl;

		// findet alle Exponenten und ermittelt die jeweiligen Koeffizienten
		for(int i=0; i<len; i++) {
			vector<int64_t> eintrag(2);
			// Exponent suchen und berechnen
			int x=0;
			int64_t exp=0;
			int64_t koef=0;
			while(a[i]!='^' and i<len) i++;
			if(a[i] != '^' and a[i] != '\0') {
				cerr << "Fehler: Kann Exponent nicht ermitteln" << endl;
				cout << "Anstatt \"^\": " << a[i] << endl;
				throw new invalid_argument("Kein zulässiger Exponent nach \"^\".");
			}
			while(i<len and a[i+1]>='0' and a[i+1] <='9') {
				i++; x++;
			}
			for(int j=0; j<x; j++) {
				exp += (a[i-j]-'0')*pow(10, j);
			}
		//	cout << "exp = " << exp << endl;

			if(exp > this->n) this->n = exp;

			// Koeffizient berechnen
			for(int j = 0; j<100 and i-x-j>=0; j++) {
				int k=i-x-j;
				if(a[k] != 'x' and a[k] != '*') {
					int basis = 0;
					while(a[k]>='0' and a[k] <='9' and k>=0) {
						koef += (a[k]-'0')*pow(10, basis);
						j++; basis++;
						k=i-x-j;
					}
				}
				if(a[k] == '-') {
					koef *= -1;
					break;
				} else if(a[k] == '+') {
					break;
				}
				if(j>19) {
					throw new invalid_argument("Integer Overflow.");
				}
			}
			eintrag[0] = koef;
			eintrag[1] = exp;
			poly.push_back(eintrag);
		//	cout << "Koeffizient: " << koef << endl;
		}
	/*	for(auto elem:poly) {
			cout << elem[0] << "x^" << elem[1] << endl;
		}
		cout << "Grad des Polynoms: " << this->n << endl;*/
	}

	int getGrad() {
		return n;
	}

	using Funktion::operator();

	virtual double value(double x) override {
		double fx=0;

		for(auto elem:poly) {
		//	cout << elem[0] << "*" << x << "^" << elem[1] << " = " << elem[0] << "*" << pow(x, elem[1]) << " = " << elem[0]*pow(x, elem[1]) << endl;
			fx += elem[0]*pow(x, elem[1]);
		}
	//	cout << "f(" << x << ") = " << fx << endl;
		return fx;
	}

	virtual double x(double x) {
		double fx=0;

		for(auto elem:poly) {
			if(elem[1] >= 1) {
				fx += elem[0]*elem[1]*pow(x, elem[1]-1);
			//	cout << "+ " << elem[0] << "*" << elem[1] << "*" << x << "^" << elem[1]-1;
			}
		}
	//	cout << endl;
	//	cout << "f'(" << x << ") = " << fx << endl;

		return fx;
	}

	virtual double xx(double x) {
		double fx=0;

		for(auto elem:poly) {
			if(elem[1] >= 2) fx += elem[0]*elem[1]*(elem[1]-1)*pow(x, elem[1]-2);
		}
	//	cout << "f''(" << x << ") = " << fx << endl;

		return fx;
	}
};
