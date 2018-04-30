#include "iostream"
#include "fstream"
#include "math.h"
using namespace std;

int main(int argc, char const *argv[])
{
	float c, dt, dx, tiempoF, x, r; float L = 100.0;
	int nx, nt;

	c = sqrt(40.0/10.0); nx = 20; dx = L/float(nx-1);r = 0.5;
	tiempoF = 200.0*3;dt = r*dx/c; nt = 1 + tiempoF/dt;

	int i;
	int k;
	float u[nt][nx];

	for (i = 0; i < nx; ++i){
		if (dx*i<0.8*L){

			u[0][i] = 1.25*dx*i/L;
			u[1][i] = 1.25*dx*i/L;}
		else{
			u[0][i] = 5.0-5.0*i*dx/L;
			u[1][i] = 5.0-5.0*i*dx/L;}}

	for (k = 2; k < nt; ++k){
		for (i = 0; i < nx; ++i){
			x = i*dx;

			if (x!=0 & x!=L){

				u[k][i] = r*( u[k-1][i-1] - 2.0*u[k-1][i] + u[k-1][i+1] );
				u[k][i] = u[k][i] + 2.0*u[k-1][i] - u[k-2][i];}

			else{ u[k][i] = 0.0;}}

		for (i = 0; i < nx; ++i){
			cout << u[k][i] << " ";}
			cout << endl;}

	return 0;}



	
