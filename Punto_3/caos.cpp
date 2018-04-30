#include "math.h"
#include "iostream"
#include "fstream"
using namespace std;

float epsilon2 = (1.0/1000)*(1.0/1000);
float dt = 0.006; int nt = 3000/dt + 1;

float k1[500000][4], k2[500000][4], k3[500000][4], k4[500000][4];
float X[500000][4], dX[500000][4];


float cambio_en_el_tiempo(int k, float q1, float q2, float p1, float p2){

	dX[k][0] = p1;
	dX[k][1] = p2;
	dX[k][2] = -2*q1/sqrt( pow(4*q1*q1+epsilon2,3) );

	float t1 = (q1-q2)/sqrt( pow( (q1-q2)*(q1-q2) +epsilon2/4 , 3) ); 
	float t2 = (q1+q2)/sqrt( pow( (q1+q2)*(q1+q2) +epsilon2/4 , 3) );
	dX[k][3] = t1-t2;}

int main(int argc, char const *argv[]){

	epsilon2 = (1.0/1000)*(1.0/1000); dt = 0.006;
	float a = 1.0/(2.0*sqrt(2.0));

	X[0][0] = a; X[0][1] = -a;
	X[0][2] = 0.0; X[0][3] = 0.0;


	FILE *caos = fopen("datos_caos.txt", "w");
	FILE *caos_cambio_signo = fopen("datos_caos_cambio_s.txt", "w");

	for (int k = 0; k < nt-1; ++k){

		cambio_en_el_tiempo(k, X[k][0], X[k][1], X[k][2], X[k][3]);
		for (int i = 0; i < 4; ++i){

			k1[k][i] = dX[k][i];}

		cambio_en_el_tiempo(k, X[k][0]+0.5*k1[k][0]*dt, X[k][1]+0.5*k1[k][1]*dt, X[k][2]+0.5*k1[k][2]*dt, X[k][3]+0.5*k1[k][3]*dt);

		for (int i = 0; i < 4; ++i){
			k2[k][i] = dX[k][i];}

		cambio_en_el_tiempo(k, X[k][0]+0.5*k2[k][0]*dt, X[k][1]+0.5*k2[k][1]*dt, X[k][2]+0.5*k2[k][2]*dt, X[k][3]+0.5*k2[k][3]*dt);
		for (int i = 0; i < 4; ++i){

			k3[k][i] = dX[k][i];}

		cambio_en_el_tiempo(k, X[k][0]+k3[k][0]*dt, X[k][1]+k3[k][1]*dt, X[k][2]+k3[k][2]*dt, X[k][3]+k3[k][3]*dt);
		for (int i = 0; i < 4; ++i){

			k4[k][i] = dX[k][i];}


		for (int i = 0; i < 4; ++i){

			X[k+1][i] = X[k][i] + 1.0/6.0*dt*( k1[k][i] + 2*k2[k][i] + 2*k3[k][i] + k4[k][i] );
			fprintf(caos, "%f ", X[k][i]);}

		fprintf(caos, "\n");

		if(X[k+1][0]*X[k][0]<0.0){

			fprintf(caos_cambio_signo,"%f %f\n", X[k][1],X[k][3]);}}
	
	fclose(caos);
	return 0;}
