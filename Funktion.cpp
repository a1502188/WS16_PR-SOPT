#include <iostream>
#include <stdexcept>

#include "Funktion.h"


const std::string warnung = "nicht implementiert";

double Funktion::operator()(double x) {
    return this->value(x);
}
double Funktion::value(double x) { throw std::runtime_error("f.value(x) = f(x) " + warnung); }
double Funktion::x(double x) { throw std::runtime_error("f.x(x) " + warnung); }
double Funktion::xx(double x) { throw std::runtime_error("f.xx(x) " + warnung); }

double Funktion::operator()(double x, double y) {
    return this->value(x, y);
}
double Funktion::value(double x, double y) { throw std::runtime_error("f.value(x,y) = f(x,y) " + warnung); }
double Funktion::x(double x, double y) { throw std::runtime_error("f.x(x,y) " + warnung); }
double Funktion::y(double x, double y) { throw std::runtime_error("f.y(x,y) " + warnung); }
double Funktion::xx(double x, double y) { throw std::runtime_error("f.xx(x,y) " + warnung); }
double Funktion::yy(double x, double y) { throw std::runtime_error("f.yy(x,y) " + warnung); }
double Funktion::xy(double x, double y) { throw std::runtime_error("f.xy(x,y) " + warnung); }
double Funktion::yx(double x, double y) { throw std::runtime_error("f.yx(x,y) " + warnung); }
