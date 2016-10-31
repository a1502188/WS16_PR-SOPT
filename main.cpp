#include <iostream>
#include <cmath>
#include"Funktion.h"
#include <stdexcept>
using namespace std;

//SIEHE ANMERKUNG AM ENDE

// -----------------------DEFINITION ALLER IN DEN ANFORDERUNGEN VERLANGTEN FUNKTIONEN DIE VON DER KLASSE FUNKTION ABGELEITET WERDEN-----------------------------

// 2x^2+e^(-2x)
struct: Funktion {
    double value (double x) {
        return (2*x*x + exp(-2*x));
    }
    double x(double x){
        return (4*x-2*exp(-2*x));
    }
    double xx(double x) {
        return (4*exp(-2*x)+4);
    }
} f1;

// x^4/4-x^2+2x
struct: Funktion {
    double value (double x) {
        return ((x*x*x*x)/4-x*x+2*x);
    }
    double x (double x) {
        return (x*x*x-2*x+2);
    }
    double xx (double x) {
        return (3*x*x-2);
    }
} f2;

// x^5+5x^4+5x^3-5x^2-6x
struct: Funktion {
    double value (double x) {
        return(x*x*x*x*x+5*x*x*x*x+5*x*x*x-5*x*x-6*x);
    }
    double x (double x) {
        return(5*x*x*x*x+20*x*x*x+15*x*x-10*x-6);
    }
    double xx (double x) {
        return (20*x*x*x+60*x*x+30*x-10);
    }

} f3;

// x^4-16x^2-1
struct : Funktion {
    double value (double x) {
        return(x*x*x*x-16*x*x-1);
    }
    double x (double x) {
        return(4*x*x*x-32*x);
    }
    double xx (double x) {
        return(12*x*x-32);
    }
} f4;

//ln(|x^3+5x-5|)  [WILL NOT WORK]
struct : Funktion {
    double value (double x) {
        return (log(abs(x*x*x+5*x-5)));
    }
    double x (double x) {
        return ((3*x*x+5)/(x*x*x+5*x-5));
    }
    double xx (double x) {
        return ((-3*x*x*x*x-30*x-25)/(x*x*x*x*x*x+10*x*x*x*x-10*x*x*x+25*x*x-50*x+25));
    }
} f5;

//ln(|x^4-16x^2-1|)  [WILL NOT WORK]
struct : Funktion {
    double value (double x) {
        return (log(abs(x*x*x*x-16*x*x-1)));
    }
    double x (double x) {
        return ((4*x*x*x-32*x)/(x*x*x*x-16*x*x-1));
    }
    double xx (double x) {
        return ((-4*x*x*x*x*x*x+32*x*x*x*x-524*x*x+32)/(x*x*x*x*x*x*x*x-32*x*x*x*x*x*x+254*x*x*x*x+32*x*x+1));
    }
} f6;
//----------------------------------------ENDE DER FUNKTIONSDEFINITIONEN--------------------------
int main(){
    try{
    int choice=0;
    cout << "Wählen Sie die Art ihrer Funktion:"<< endl << endl << "(1) Eindimensional" << endl << "(2) Mehrdimensional"<< endl;
    cin >> choice;
    if(choice==1) { //Programmabarbeitung für eindimensionale Funktionen
        choice=0;
        cout << "Geben Sie die gewünschte Rechengenauigkeit in Kommastellen an!" << endl;
        int precision=0;
        cin >> precision;
        cout << "Geben Sie einen Startwert für x an." << endl;
        double startx =0;
        cin >> startx;
        cout<< "Waehlen Sie eine Funktion:" << endl << endl;
        cout << "(1) f1(x) = 2x^2 + e^(-2x)" << endl;
        cout << "(2) f2(x) = (x^4)/4 - x^2 + 2x" << endl;
        cout << "(3) f3(x) = x^5 + 5x^4 +5x^3 -5x^2 - 6x" << endl;
        cout << "(4) f4(x) = x^4 -16x^2 - 1" << endl;
        cout << "(5) f5(x) = ln(|x^3 + 5x -5|)" << endl;
        cout << "(6) f6(x) = ln(|x^4 - 16x^2 - 1|)" << endl;
        cout << "(7) Eigene Funktion eintippen (Format: ------)" << endl;
        cin >> choice;
        switch (choice) { //Auswahl der Funktion
            case 1: cout << "1" //do something
                break;

            case 2: cout <<"2"//do something else
                break;



        }

    }
    else if(choice==2) { // Programmabarbeitung für mehrdimensionale Funktionen
        choice=0;
        cout << "Geben Sie die gewünschte Rechengenauigkeit in Kommastellen an!" << endl;
        int precision=0;
        cin >> precision;
        cout << "Geben Sie einen Startwert für x an." << endl;
        double startx =0;
        cin >> startx;
        cout << "Geben Sie einen Startwert für y an." << endl;
        double starty =0;
        cin >> starty;










    }
    else {
        throw invalid_argument("Keine passende Auswahl getroffen! Tippen Sie die Zahl in Klammer ein, die Ihrem Wunschbefehl entspricht.");
    }
    } // Ende TRY
    catch(invalid_argument& a) {cerr << a.what() << endl;}
}   // Ende MAIN

/*
Die Funktionen haben die Variablen namen f1, f2 etc.
Es werden im Client zwei bzw. drei Variablen definiert die für die Berechnung benötigt werden
Der User gibt einerseits die Präzision in Kommastellen mit der Variable "int precision" an.
Weiters gibt er den Startwert/die Startwerte "double startx" und "double starty" an.

*/
