#ifndef ODE_H
#define ODE_H

double Euler (double t0, double t1, double h, double x0, double (*f) (double t, double x));

double MidPoint (double t0, double t1, double h, double x0, double (*f) (double t, double x));

double RungeKutta (double t0, double t1, double h, double x0, double (*f) (double t, double x));

#endif
