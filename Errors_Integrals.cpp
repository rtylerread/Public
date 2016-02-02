#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

long double funct(long double x);

int main()
{
  //This program calculates an integral approximation via Simpson's rule
  //information is outputted to cout and to a data file in gnuplot 
formatting
  int N = 5, n_generations = 21;
  long double T,S,e,I=0,a,b,h;
  a = 1;
  b = 2;
  h = (b-a)/N;

  S = T = 0;

  for(int i = 1; i<N; ++i)//calculating S_0
    {
      if(i%2==0)
	S += funct(a+i*h);
      else if(1%2==1)
	T += funct(a+i*h);
    }
  S *= 2;
  S += funct(a)+funct(b);
  S /= 3.;

  ofstream ifs ("output.dat");
  if(!ifs.is_open())
    {
      cout<<"Exiting."<<endl;
      exit(1);
    }

  ifs<<"#plotting_data1.dat"<<endl<<"h e"<<endl;

  I = h*(S+2*T);

  double S_last = S, T_last = T, I_last = I;
  cout<<"i\t|\tI\t\t|\te"<<endl;
  cout<<"-------------------------------------------------------"<<endl;

  for(int i = 1; i <= n_generations; ++i, N*=2)
    {
      h = (b-a)/N;
      for(int j = 1; j < N; ++j)
	if(j%2==1)
	  T +=funct(a+j*h);
      T *= (2./3.);//recalculation of T
      S = S_last + T_last;
      I = h*(S+2*T);
      e = (1/15.)*abs(I_last-I);
      cout<<i<<"\t|\t"<<I;
      if(i<3 || i == 9)
	cout<<'\t';

      cout<<"\t|\t"<<e<<endl;
      ifs<<h<<' '<<e<<endl;
    }
}

long double funct(long double x)
{
  long double val
    = 1./x;//change this line for different function
  return val;
}
