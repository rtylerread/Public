#include<iostream>
#include<cmath>

using namespace std;

int main()
{
  cout<<"This program calculates the time it takes to travel from earth";
  cout<<" to another distance in space given a speed and a distance.\n";
  cout<<"Physics 411 HW1, part 2. Author: rtylerr"<<endl;
  cout<<"\nPlease input a velocity (fraction of c) and a distance (ly).\n";
  double x,v;
  cin >> v >> x;
  cout << "To an earth observer, it takes: "<<x/v<<" years."<<endl;
  cout << "To an observer on the ship, it takes: "<<(x/v)/(pow(1.-pow(v,2.),-1./2.))<<" years."<<endl;
}
