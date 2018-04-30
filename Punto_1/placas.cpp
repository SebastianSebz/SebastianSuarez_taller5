#include "iostream"
#include "fstream"
#include <math.h>
using namespace std;

int main(){

	int it; int n = 1024/2.0;
	float L = 5.0, alt = 5.0/float(n-1.0), l = 2.0, d = 1.0, V2 = 50.0, cons = 2.0;

	int plate_kx0 = int((L/cons-l/cons)/L*float(n)), plate_kxf = int((L/cons+l/cons)/L*float(n));
	int plate_jy0 = int((L/cons-d/cons)/L*float(n)), plate_jyf = int((L/cons+d/cons)/L*float(n));
	float Poten[n][n],Poten1[n][n],Poten2[n][n], campoE_x[n][n], campoE_y[n][n];
	int j,k;

	for (j = 0; j < n; j++){
		for (k = 0; k < n; k++){
			Poten[j][k], Poten1[j][k], Poten2[j][k], campoE_x[j][k], campoE_y[j][k] = 0.0;}}

	for (k = plate_kx0; k < plate_kxf+1; k++){

		Poten[plate_jy0][k],Poten1[plate_jy0][k],Poten2[plate_jy0][k] = V2;
		Poten[plate_jyf][k],Poten1[plate_jyf][k],Poten2[plate_jyf][k] = -V2;}

	int count = pow(n,2)/500;

	for (it = 0; it < count; it++){

		for (j = 1; j < n-1; j++){
			for (k = 1; k < n-1; k++){

				if ((j!=plate_jy0 & j!=plate_jyf)){ 
					Poten2[j][k] = (1.0/(pow(cons,2)))*(Poten1[j][k+1] + Poten1[j][k-1] + Poten1[j+1][k] + Poten1[j-1][k]);}

				else if ( k<plate_kx0 || k>plate_kxf ){
					Poten2[j][k] = (1.0/(pow(cons,2)))*(Poten1[j][k+1] + Poten1[j][k-1] + Poten1[j+1][k] + Poten1[j-1][k]);}}}

		for (j = 0; j < n; j++){
			for (k = 0; k < n; k++){
				Poten1[j][k] = Poten2[j][k];}}

		if (it==count-1){

			for (j = 1; j < n-1; j++){
				for (k = 1; k < n-1; k++){

					campoE_x[j][k] = ( Poten2[j][k+1]-Poten2[j][k-1] )/(cons*alt);
					campoE_y[j][k] = ( Poten2[j+1][k]-Poten2[j-1][k] )/(cons*alt);}

				campoE_x[0][j], campoE_x[n-1][j] = 0.0;

				campoE_x[j][0] = (Poten2[j][1]-Poten2[j][0])/alt;
				campoE_x[j][n-1] = (Poten2[j][n-1]-Poten2[j][n-2])/alt;

				campoE_y[0][j] = (Poten2[1][j]-Poten2[0][j])/alt;
				campoE_y[n-1][j] = (Poten2[n-1][j]-Poten2[n-2][j])/alt;
				campoE_y[j][0], campoE_y[j][n-1] = 0.0;}

			campoE_x[0][0] = campoE_x[1][1]; campoE_x[0][n-1] = campoE_x[1][n-2];
			campoE_x[n-1][n-1] = campoE_x[n-2][n-2]; campoE_x[n-1][0] = campoE_x[n-2][1];

			campoE_y[0][0] = campoE_y[1][1]; campoE_y[0][n-1] = campoE_y[1][n-2];
			campoE_y[n-1][n-1] = campoE_y[n-2][n-2]; campoE_y[n-1][0] = campoE_y[n-2][1];}}

	for (j = 0; j < n; j++){
		for (k = 0; k < n; k++){

			cout << Poten2[j][k] << " ";}
			cout << "\n";}	

	ofstream campoE("campoE.txt");
	for (j = 0; j < n; j++){
		for (k = 0; k < n; k++){
			campoE << campoE_x[j][k] << " ";}

		for (k = 0; k < n; k++){
			campoE << campoE_y[j][k] << " ";}
		campoE << "\n";}	

	return 0;}
