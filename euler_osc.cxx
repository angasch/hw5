#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;


int main(){
  const double pi = 3.1415926535897;
  const double N = 200 ;			//Berechnung der Schrittanzahl N*pi/10=20*pi
  const double dt = pi/10;			  //Schrittgröße	
  double yfwd[2];
  double ybwd[2];
  double x;


  yfwd[0] = 1.0;				
  yfwd[1] = 0.0;
  ybwd[0] = 1.0;			
  ybwd[1] = 0.0;	
  double a;				
  double b;

  for(int i=0; i< N ; i++){
	x=cos(i*dt);
	a=yfwd[0];
	yfwd[0]=yfwd[0]+dt*yfwd[1];
	yfwd[1]=yfwd[1]-dt*a;
	b=ybwd[0];
	ybwd[0]=(ybwd[0]+dt*ybwd[1])/(1+dt*dt);
	ybwd[1]=ybwd[1]-dt*((b+dt*ybwd[1])/1+dt*dt);

  cout << i*dt << "\t" << x << "\t" << yfwd[0] << "\t" << ybwd[0] << endl;
}

 return 0;  
}
