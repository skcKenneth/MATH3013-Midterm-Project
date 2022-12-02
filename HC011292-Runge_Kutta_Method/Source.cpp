#include "RK4.h"
using namespace std;
int main() {
	double ti = 0.;
	double tf = 40.;
	int n = 9e4; //Number of points in RK4, it can be changed
	double delta_t;
	RungeKutta Runge; // Using the function from the class
	double* values;
	double x_int[3] = { 1., 1., 1. }; // Initial points 
	delta_t = (tf - ti) / (double)(n);
	values = Runge.RK4(ti, x_int, delta_t);
	//Open dataes to write output
	//.dat is for plotting by Gnuplot
	//I also has made a file that is .csv for plotting by matplotlib but I do not upload it 
	ofstream data("Data.dat");
	data << x_int[0] << "     " << x_int[1] << "     " << x_int[2] << "\n";//For writing the initial 3 points in data

	for (int i = 1; i < n; i++) {
		values =  Runge.RK4(ti, values, delta_t);
		data << values[0] << "     " << values[1] << "     " << values[2] << "\n";

	}
	//Closing data
	data.close();
	delete[] values;
	return 0;
}
