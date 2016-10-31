#ifndef FUNKTION_H
#define FUNKTION_H


struct Funktion
{
    //1D
    double operator()(double x);
    virtual double value(double x);
    virtual double x(double x);
    virtual double xx(double x);

    //2D
    double operator()(double x, double y);
    virtual double value(double x, double y);
    virtual double x(double x, double y);
    virtual double y(double x, double y);
    virtual double xx(double x, double y);
    virtual double yy(double x, double y);
    virtual double xy(double x, double y);
    virtual double yx(double x, double y);
};

#endif // FUNKTION_H
