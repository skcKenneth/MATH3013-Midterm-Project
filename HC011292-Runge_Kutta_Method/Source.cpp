#include "RG4.h"
using namespace std;
int main() {
	double t0 = 0.;
	double tf = 40.;
	int n = 9e4; //Number of points in RK4, it can be changed
	double delta_t;
	double* values = new double[n];
	RungeKutta RG; // Using the function from the class
	double* val;
	double x_int[3] = { 1., 1., 1. }; // Initial points 
	vector<double> v1(n);
	vector<double> v2(n);
	delta_t = (tf - t0) / (double)(n);
	int j = 0;
	val = RG.RK4(t0, x_int, delta_t);
	//Open dataes to write output
	//.dat is for plotting by Gnuplot
	//I also has made a file that is .csv for plotting by matplotlib but I do not upload it 
	ofstream data("Data.dat");
	data << x_int[0] << "     " << x_int[1] << "     " << x_int[2] << "\n";//For writing the initial 3 points in data

	for (int i = 1; i < n; i++) {
		val =  RG.RK4(t0, val, delta_t);
		data << val[0] << "     " << val[1] << "     " << val[2] << "\n";

	}
	//Closing data
	data.close();
	delete[] val;
	return 0;
}
