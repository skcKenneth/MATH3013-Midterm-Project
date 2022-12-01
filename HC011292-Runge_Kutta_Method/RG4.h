#ifndef RG4_H // include guard
#define RG4_H
#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>

class RungeKutta {
protected:
	double sigma = 10.;
	double R = 28.;
	double b = 10. / 3.;
protected:
	double t1, t2, t3;
	double* f1, * f2, * f3, * f4;
	double* x, * x1, * x2, * x3;
public:
	double* RK4(double t0, double x0[], double h);
	double* ls(double x[]);
};

//Lorenz System
double* RungeKutta::ls(double x[]) {
	double* dxdt = new double[3];

	dxdt[0] = sigma * (x[1] - x[0]);
	dxdt[1] = R * x[0] - x[1] - x[0] * x[2];
	dxdt[2] = x[0] * x[1] - b * x[2];
	return dxdt;
}
//Runge-Kutta-Methods
double* RungeKutta::RK4(double t0, double x0[], double h) {

	f1 = ls(x0);
	t1 = t0 + h / 2;
	x1 = new double[3];
	for (int i = 0; i < 3; i++) {
		x1[i] = x0[i] + h * f1[i] / 2.0;
	}

	f2 = ls(x1);
	t2 = t0 + h / 2;
	x2 = new double[3];
	for (int i = 0; i < 3; i++) {
		x2[i] = x0[i] + h * f2[i] / 2.0;
	}

	f3 = ls(x2);
	t3 = t0 + h;
	x3 = new double[3];
	for (int i = 0; i < 3; i++) {
		x3[i] = x0[i] + h * f3[i];
	}

	f4 = ls(x3);
	x = new double[3];
	for (int i = 0; i < 3; i++) {
		x[i] = x0[i] + h * (f1[i] + 2.0 * f2[i] + 2.0 * f3[i] + f4[i]) / 6.0;
	}
	delete[] f1;
	delete[] f2;
	delete[] f3;
	delete[] f4;
	delete[] x1;
	delete[] x2;
	delete[] x3;
	return x;
}
#endif /* RG4_H */
