#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  cout<<"This program calculates the necessary height of a sattelite ";
  cout<<"for a given period. Physics 411 HW1, part 1. Author: rtylerr\n"<<endl;
  cout<<"Please enter a value for T (period of an orbiting satellite) in seconds."<<endl;
  double T = 0, R = 6371, G = 6.67 * pow(10,-11), M = 5.97 * pow(10,24);
  //Mars
  /*
    M *= 0.107;
    R = 3390;
  */
  //Jupiter
  
    M *= 317.8;
    R = 69911;
   
  cin >> T;
  cout<<"The orbit's altitude is: "<<pow(((G*M*pow(T,2))/(4*pow(M_PI,2)))-R,1.0/3.0);
 cout<<" meters"<<endl;
}
