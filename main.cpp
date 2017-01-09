
#include <iostream>
#include <cmath>
#include"Funktion.h"
#include <stdexcept>
#include <fstream> 
#include <stdio.h>
using namespace std;

//SIEHE ANMERKUNG AM ENDE

// -----------------------DEFINITION ALLER IN DEN ANFORDERUNGEN VERLANGTEN FUNKTIONEN DIE VON DER KLASSE FUNKTION ABGELEITET WERDEN-----------------------------

// 2x^2+e^(-2x)
struct : Funktion {
	double value (double x) {
	    return (2*x*x + exp(-2*x));
	}
	double x (double x) {
	    return (4*x-2*exp(-2*x));
	}
	double xx (double x) {
	    return (4*exp(-2*x)+4);
	}
} f1;

// x^4/4-x^2+2x
struct : Funktion {
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

// 3x^2+y^2-3xy-3x
struct : Funktion {
    double value(double x, double y) {
        return(3*x*x+y*y-3*x*y-3*x);
    }
    double x (double x, double y) {
        return (6*x-3*y-3);
    }
    double y (double x, double y) {
        return (2*y-3*x);
    }
    double xx (double x, double y) {
        return (6);
    }
    double xy (double x, double y) {
        return (-3);
    }
    double yx (double x, double y) {
        return (-3);
    }
    double yy (double x, double y) {
        return (2);
    }
} g1;


// 100*(y-x^2)^2 + (x-1)^2
struct : Funktion {
    double value(double x, double y) {
        return(100*(y-x*x)*(y-x*x)+(x-1)*(x-1));
    }
    double x (double x, double y) {
        return(400*x*x*x-400*x*y+2*x-2);
    }
    double y (double x, double y) {
        return(200*y-200*x*x);
    }
    double xx (double x, double y) {
        return(1200*x*x-400*y+2);
    }
    double xy (double x, double y) {
        return(-400*x);
    }
    double yx (double x, double y) {
        return(-400*x);
    }
    double yy (double x, double y) {
        return(200);
    }

} g2;

// y^4+2x^2 -3xy+1
struct : Funktion {
    double value(double x, double y) {
        return(y*y*y*y+2*x*x-3*x*y+1);
    }
    double x (double x, double y) {
        return(4*x-3*y);
    }
    double y (double x, double y) {
        return(4*y*y*y-3*x);
    }
    double xx (double x, double y) {
        return(4);
    }
    double xy (double x, double y) {
        return(-3);
    }
    double yx (double x, double y) {
        return(-3);
    }
    double yy (double x, double y) {
        return(12*y*y);
    }

} g3;

// |xy|+x^2+y^2-2x-4y [WONT WORK]
struct : Funktion {
    double value(double x, double y) {
        return(abs(x*y)+x*x+y*y-2*x-4*y);
    }
    double x (double x, double y) {
        return(((abs(y)*x)/ abs(x))+2*x-2);
    }
    double y (double x, double y) {
        return(((abs(x)*y)/ abs(y))+2*y-4);
    }
    double xx (double x, double y) {
        return(2);
    }
    double xy (double x, double y) {
        return((y*x)/(abs(y)*abs(x)));
    }
    double yx (double x, double y) {
        return((y*x)/(abs(y)*abs(x)));
    }
    double yy (double x, double y) {
        return(2);
    }

} g4;

// (x^2+y-11)^2 + (x+y^2-7)^2
struct : Funktion {
    double value(double x, double y) {
        return((x*x+y-11)*(x*x+y-11)+(x+y*y-7)*(x+y*y-7));
    }
    double x (double x, double y) {
        return(4*x*x*x+4*x*y-42*x+2*y*y-14);
    }
    double y (double x, double y) {
        return(2*x*x+4*x*y+4*y*y*y-26*y-22);
    }
    double xx (double x, double y) {
        return(12*x*x+4*x-42);
    }
    double xy (double x, double y) {
        return(4*x+4*y);
    }
    double yx (double x, double y) {
        return(4*x+4*y);
    }
    double yy (double x, double y) {
        return(4*x+12*y*y-26);
    }

} g5;


//berechne x(k+1) aus x(k)
double calx(double oldx, Funktion &f) {
    double newx;
    newx=oldx-(f.x(oldx)/f.xx(oldx));
    return newx;
}
               
double gedCalx(double oldx, Funktion &f, double lambda) {
    double newx;
    newx=oldx-lambda*(f.x(oldx)/f.xx(oldx));
    return newx;
}

// Betragsmetrik; Abstand zwischen zwei reellen Zahlen
double d(double x, double y) {
	return abs(x-y);
}

// Euklidische Norm, Abstand zwischen zwei Vektoren im R^2
double d(double x1, double x2, double y1, double y2) {
	return sqrt(pow(x1-y1, 2) + pow(x2 - y2, 2));
}

//Gedämpftes 1-Dimensionales Newtonverfahren UNDER CONSTRUCTION
double gednewton1d(int precision, double startx, Funktion &f, double dn) {
    cout<< "Gedaempftes Newtonverfahren angewendet: ";
    int precisionten= pow(10,precision); //10^Kommastellenpräzision
    int m=-1;
    double lambda;  //Lambda wird mit steigendem m immer kleiner, so lange, bis sich nicht mehr von der Nullstelle entfernt wird
    double newx; 
    double dold=dn;
    double dnew=0;

    ofstream data("data.dat");
    data << "#x y" << endl 
	 << startx <<" " << f(startx) <<endl;
	
    do{      
        startx=newx;
	m++; //m wird auf 0 erhöht, und dann so lange, bis sich nicht mehr von dem Minimum entfernt wird
        lambda = pow(0.5, m);
	newx= gedCalx(startx, f, lambda); // neuer Punkt wird aus Startpunkt und Lambda errechnet
        dnew= d(startx, newx);
	    
    } while (dnew>=dold); // Wenn noch immer kleiner, wird Lambda nochmal verkleinert und nochmal durchlaufen
	                                                 // (Vergleich über f.value fehlerhaft, noch nicht final)
        
    do{     
        startx=newx;            // Aus letzter iteration berechnetes x wird zu neuem startwert
        newx= gedCalx(startx, f,lambda);  // Newtonverfahren-Formel anwenden
	data << newx <<" " << f(newx) <<endl;
   
    } while (int(d(newx,startx)*precisionten) > 0);              // Überprüfung ob der Fehler schon klein genug ist
        
    
        
        return newx;            // Rückgabe der Minimalstelle
    
}
               
               
//1-Dimensionales Newtonverfahren
double newton1d(int precision, double startx, Funktion &f){
    int precisionten= pow(10,precision); //10^Kommastellenpräzision
    double newx=startx; //x(k+1) initialisiert


    ofstream data("data.dat");
    data << "#x y" << endl 
	 << startx <<" " << f(startx) <<endl;
	 					 
   


    double dold=0;
    double dnew=0;
    int iterationcounter=0;
    do{            
        if(dnew>=dold && iterationcounter > 5)       //Wenn Werteabst寤e nach 5 Iteration gr�� werden, dann abbrechen und stattdessen gedämpftes Newtonveffahren anwenden
             break;
        startx=newx;            // Aus letzter iteration berechnetes x wird zu neuem startwert

;
        newx= calx(startx, f);  // Newtonverfahren-Formel anwenden
   	dold=dnew;
   	dnew = d(startx, newx);
   	iterationcounter++;
        data << newx <<" " << f(newx) <<endl;
	 					 
                
    } while (int(d(newx,startx)*precisionten) > 0);              // Überprüfung ob der Fehler klein genug ist

    if(dnew>=dold)
        newx = gednewton1d(precision, startx, f, dnew); // Wenn sich die Werte vom Minimum entfernen, dann gedämpftes Newtonverfahren anwenden (NOCH NICHT IMPLEMENTIERT!)
    
    data.close();  
    return f.value(newx);            // Rückgabe der Minimalstelle
}

double newton2d(int precision, double startx, double starty, Funktion &g) {
	double currentx=startx;
	double currenty=starty;
	double hessematrix [2][2];
	double gradient [2];
	double newabsvalue;
	double oldabsvalue;
	double invhessematrix[2][2];
	
        ofstream data("data.dat");
	
        data << "#x y z" << endl 
	     << startx <<" " << starty <<" " << g.value(startx, starty) <<endl;
	
	do{
	
	hessematrix[0][0] = g.xx(currentx, currenty);
	hessematrix[0][1] = g.xy(currentx, currenty);
	hessematrix[1][0] = g.yx(currentx, currenty);
	hessematrix[1][1] = g.yy(currentx, currenty);
	gradient[0] = g.x(currentx, currenty);
	gradient[1] = g.y(currentx, currenty);
	double invertdet= 1/(hessematrix[0][0] * hessematrix[1][1] - hessematrix[0][1] * hessematrix[1][0]);
	invhessematrix[0][0] = hessematrix[1][1] * invertdet;
	invhessematrix[0][1] = -hessematrix[0][1] * invertdet;
	invhessematrix[1][0] = -hessematrix[1][0] * invertdet;
	invhessematrix[1][1] = hessematrix[0][0] * invertdet;

	double newx= currentx - (invhessematrix[0][0]*gradient[0] + invhessematrix[0][1]*gradient[1]);
	double newy= currenty - (invhessematrix[1][0]*gradient[0] + invhessematrix[1][1]*gradient[1]);
	newabsvalue = sqrt(newx*newx + newy*newy);
	oldabsvalue = sqrt(currentx*currentx + currenty * currenty);
	
	cout << "Aktueller Punkt: (" << newx << "|" << newy << ") " << endl;
		
        data << newx <<" " << newy <<" " << g.value(newx, newy) <<endl;	
	     
		
	currentx = newx;
	currenty = newy;
	
	} while(int (d(newabsvalue, oldabsvalue)*pow(10, precision))> 0);

	return g.value(currentx, currenty);
}

//----------------------------------------ENDE DER FUNKTIONSDEFINITIONEN--------------------------
int main(){
    try{
    int choice=0;
    cout << "Waehlen Sie die Art ihrer Funktion:"<< endl << endl << "(1) Eindimensional" << endl << "(2) Mehrdimensional"<< endl;
    cin >> choice;

    if(choice==1) { //Programmabarbeitung fuer eindimensionale Funktionen
        choice=0;
        cout << "Waehlen Sie eine Funktion:" << endl << endl;
        cout << "(1) f1(x) = 2x^2 + e^(-2x)" << endl;
        cout << "(2) f2(x) = (x^4)/4 - x^2 + 2x" << endl;
        cout << "(3) f3(x) = x^5 + 5x^4 +5x^3 -5x^2 - 6x" << endl;
        cout << "(4) f4(x) = x^4 -16x^2 - 1" << endl;
        cout << "(5) f5(x) = ln(|x^3 + 5x -5|)" << endl;
        cout << "(6) f6(x) = ln(|x^4 - 16x^2 - 1|)" << endl;
        cout << "(7) (Eigene Funktion eintippen (Format: ------))" << endl;
        cin >> choice;
        cout << "Geben Sie die gewuenschte Rechengenauigkeit in Kommastellen an!" << endl;
        int precision=0;
        cin >> precision;
        if(precision<0)
                throw invalid_argument("Negative Praezision nicht erlaubt!"); // TODO auch prüfen, dass int nicht überläuft bei pow(10, precision)
        cout << "Geben Sie einen Startwert für x an." << endl;
        double startx = 0;
        cin >> startx;

        switch (choice) { //Auswahl der Funktion
            case 1: {
		    
		cout << "Extremwert: " << newton1d(precision, startx, f1) << endl;

                	
		ofstream plot("plot.gp");
				
		
	
		        	
                plot << "set term png" <<endl 
                     << "set output 'funktion.png'" <<endl
                     << "set xrange [-10:10]" <<endl  
                     << "set yrange [-5:20]" <<endl
                     << "plot 2*x*x + exp(-2*x) title 'Funktion', \\" <<endl 
		     << "'data.dat' with points title 'Punkte' pt 5" <<endl;
	             
					 
				
				   
                plot.close();                              
                break;
            }

            case 2: {
	        cout << "Extremwert: " << newton1d(precision, startx, f2) << endl;

		
	        ofstream plot("plot.gp");
				
	
	
		        	
                plot << "set term png" <<endl 
                     << "set output 'funktion.png'" <<endl
                     << "set xrange [-10:10]" <<endl  
                     << "set yrange [-5:20]" <<endl
                     << "plot (x*x*x*x)/4-x*x+2*x title 'Funktion', \\" <<endl 
		     << "'data.dat' with points title 'Punkte' pt 5" <<endl;
	             
					 
				
				   
                plot.close();                              
            }

                break;

            case 3: {
	        cout << "Extremwert: " << newton1d(precision, startx, f3) << endl;

               
		ofstream plot("plot.gp");
				
		
		        	
                plot << "set term png" <<endl 
                     << "set output 'funktion.png'" <<endl
                     << "set xrange [-10:10]" <<endl  
                     << "set yrange [-10:10]" <<endl
                     << "plot x*x*x*x*x+5*x*x*x*x+5*x*x*x-5*x*x-6*x title 'Funktion', \\" <<endl 
		     << "'data.dat' with points title 'Punkte' pt 5" <<endl;
	             
					 
				
				   
                plot.close(); 
            }
                break;

            case 4: {
		cout << "Extremwert: " << newton1d(precision, startx, f4) << endl;
		ofstream plot("plot.gp");
				
		
		        	
                plot << "set term png" <<endl 
                     << "set output 'funktion.png'" <<endl
                     << "set xrange [-10:10]" <<endl  
                     << "set yrange [-80:200]" <<endl
                     << "plot x*x*x*x-16*x*x-1 title 'Funktion', \\" <<endl 
		             << "'data.dat' with points title 'Punkte' pt 5" <<endl;
	             
					 
				
				   
                plot.close(); 
            }
                break;

            case 5:
		        cout << "Extremwert: " << newton1d(precision, startx, f5) << endl;
                break;

            case 6: {
		        cout << "Extremwert: " << newton1d(precision, startx, f6) << endl;
 
		        ofstream plot("plot.gp");
				
		
		        	
                plot << "set term png" <<endl 
                     << "set output 'funktion.png'" <<endl
                     << "set xrange [-10:10]" <<endl  
                     << "set yrange [-10:10]" <<endl
                     << "plot log(abs(x*x*x*x-16*x*x-1)) title 'Funktion', \\" <<endl 
		             << "'data.dat' with points title 'Punkte' pt 5" <<endl;
	             
					 
				
				   
                plot.close(); 
            }
            break;

            default: throw invalid_argument("Keine passende Auswahl getroffen!");
                break;
        }

    }
    else if(choice==2) { // Programmabarbeitung für mehrdimensionale Funktionen
        choice=0;
        cout << "Waehlen Sie eine Funktion:" << endl << endl;
        cout << "(1) g1(x,y) = 3x^2 + y^2 - 3xy - 3x" << endl;
        cout << "(2) g2(x,y) = 100 * (y - x^2)^2 + (x - 1)^2 " << endl;
        cout << "(3) g3(x,y) = y^4 + 2x^2 - 3xy + 1" << endl;
        cout << "(4) g4(x,y) = |xy| + x^2 + y^2 - 2x - 4y" << endl;
        cout << "(5) g5(x,y) = (x^2 + < - 11)^2 + (x + y^2 - 7)^2" << endl;
        cin >> choice;
        cout << "Geben Sie die gewünschte Rechengenauigkeit in Kommastellen an!" << endl;
        int precision=0;
        cin >> precision;
        if(precision<0)
                throw invalid_argument("Negative Präzision nicht erlaubt!");
        cout << "Geben Sie einen Startwert für x an." << endl;
        double startx =0;
        cin >> startx;
        cout << "Geben Sie einen Startwert für y an." << endl;
        double starty =0;
        cin >> starty;

       switch (choice) { //Auswahl der Funktion
            case 1: { //do something
                cout << "Zielwert: " << newton2d(precision, startx, starty, g1) << endl;
		    
		ofstream plot("plot.gp");    
		    
                plot << "set term png" <<endl 
                     << "set output 'funktion3d.png'" <<endl
                     << "set xrange [-10:10]" <<endl  
                     << "set yrange [-10:10]" <<endl
	             << "set ticslevel 0" <<endl
                     << "splot 3*x*x+y*y-3*x*y-3*x title '3x^2+y^2-3xy-3x', \\" <<endl 
		     << "'data.dat' with points title 'Punkte' pt 5" <<endl;
		    
		plot.close();    
					    
	    }
	        break;

            case 2: { //do something else
                cout << "Zielwert: " << newton2d(precision, startx, starty, g2) << endl;
		
		ofstream plot("plot.gp");    
		    
                plot << "set term png" <<endl 
                     << "set output 'funktion3d.png'" <<endl
                     << "set xrange [-10:10]" <<endl  
                     << "set yrange [-10:10]" <<endl
	             << "set ticslevel 0" <<endl
                     << "splot 100*(y-x*x)*(y-x*x)+(x-1)*(x-1) title '100*(y-x^2)^2 + (x-1)^2', \\" <<endl 
		     << "'data.dat' with points title 'Punkte' pt 5" <<endl;
		    
		plot.close();  		
				
	    }
		break;	 
			
            case 3: { //do something
                cout << "Zielwert: " << newton2d(precision, startx, starty, g3) << endl;
				
		ofstream plot("plot.gp");    
		    
                plot << "set term png" <<endl 
                     << "set output 'funktion3d.png'" <<endl
                     << "set xrange [-10:10]" <<endl  
                     << "set yrange [-10:10]" <<endl
	             << "set ticslevel 0" <<endl
                     << "splot y*y*y*y+2*x*x-3*x*y+1 title 'y^4+2x^2-3xy+1', \\" <<endl 
		     << "'data.dat' with points title 'Punkte' pt 5" <<endl;
		    
		plot.close();  				
				
	    }
		break;	
			
            case 4: { //do something
                cout << "Zielwert: " << newton2d(precision, startx, starty, g4) << endl;
				
		ofstream plot("plot.gp");    
		    
                plot << "set term png" <<endl 
                     << "set output 'funktion3d.png'" <<endl
                     << "set xrange [-10:10]" <<endl  
                     << "set yrange [-10:10]" <<endl
	             << "set ticslevel 0" <<endl
                     << "splot x title 'Platzhalter', \\" <<endl 
		     << "'data.dat' with points title 'Punkte' pt 5" <<endl;
		    
		plot.close();  				
				
	    }
		break;	
			
            case 5: { //do something
                cout << "Zielwert: " << newton2d(precision, startx, starty, g5) << endl;
			
		ofstream plot("plot.gp");    
		    
                plot << "set term png" <<endl 
                     << "set output 'funktion3d.png'" <<endl
                     << "set xrange [-10:10]" <<endl  
                     << "set yrange [-10:10]" <<endl
	             << "set ticslevel 0" <<endl
                     << "splot (x*x+y-11)*(x*x+y-11)+(x+y*y-7)*(x+y*y-7) title '(x^2+y-11)^2 + (x+y^2-7)^2', \\" <<endl 
		     << "'data.dat' with points title 'Punkte' pt 5" <<endl;
		    
		plot.close();  			
	    }		
		break;	









            default: throw invalid_argument("Keine passende Auswahl getroffen!");
                break;
		}
    }
    else {
        throw invalid_argument("Keine passende Auswahl getroffen! Tippen Sie die Zahl in Klammer ein, die Ihrem Wunschbefehl entspricht.");
    }
    } // Ende TRY
    catch(invalid_argument& a) {cerr << a.what() << endl;}
    
    system("gnuplot> load 'plot.gp'");
   
    
}   // Ende MAIN

