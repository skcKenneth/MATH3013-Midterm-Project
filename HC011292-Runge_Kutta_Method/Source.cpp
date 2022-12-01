#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

double* rungekutta(double t0, double u0[], double h);
double* lorenz(double x[]);


//Lorenz System
double* lorenz(double x[]) {
	double b = 10. / 3.;
	double R = 28.;
	double sigma = 10.;

	double* dxdt = new double[3];

	dxdt[0] = sigma * (x[1] - x[0]);
	dxdt[1] = R * x[0] - x[1] - x[0] * x[2];
	dxdt[2] = x[0] * x[1] - b * x[2];
	return dxdt;
}

//Runge-Kutta-4
double* rungekutta(double t0, double x0[], double h) {
	double t1, t2, t3;
	double* f1, * f2, * f3, * f4;
	double* x, * x1, * x2, * x3;

	f1 = lorenz(x0);
	t1 = t0 + h / 2;
	x1 = new double[3];
	for (int i = 0; i < 3; i++) {
		x1[i] = x0[i] + h * f1[i] / 2.0;
	}

	f2 = lorenz(x1);
	t2 = t0 + h / 2;
	x2 = new double[3];
	for (int i = 0; i < 3; i++) {
		x2[i] = x0[i] + h * f2[i] / 2.0;
	}

	f3 = lorenz(x2);
	t3 = t0 + h;
	x3 = new double[3];
	for (int i = 0; i < 3; i++) {
		x3[i] = x0[i] + h * f3[i];
	}

	f4 = lorenz(x3);
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

int main() {
	double t0 = 0.;
	double tf = 40.;
	int n = 9e4;
	double dt;
	double* values = new double[n];
	double* val;
	double x[3] = { 1., 1., 1. };
	vector<double> xpos1(n);
	vector<double> xpos2(n);
	dt = (tf - t0) / (double)(n);
	int j = 0;
	val = rungekutta(t0, x, dt);
	//Open data to write output
	ofstream data("Data.dat");
	data << x[0] << "     " << x[1] << "     " << x[2] << "\n";

	//For n points run RK4 to solve Lorenz equations
	for (int i = 1; i < n; i++) {
		val = rungekutta(t0, val, dt);
		data << val[0] << "     " << val[1] << "     " << val[2] << "\n";
		if (i < n) {
			xpos1[i] = val[0];
		}
		if (i > 8 && j < n) {
			xpos2[j] = val[0];
			j++;
		}

	}

	//Closing data
	data.close();
	delete[] val;
	return 0;
}
