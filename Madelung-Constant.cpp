#include <iostream>
#include <cmath>

using namespace std;

int main()
{//calculates the Madelung constant for L=450 in 59.45 seconds
  ios_base::sync_with_stdio(false);//for optimization
  int L=0;//,eo = 1;
  double tot = 0;
  cout<<"Please provide a value for the components of L"<<endl;
  cin>>L;
  for(int i = -L; i <= L; ++i)
    {
      for(int j = -L; j <= L; ++j)
	{
	  for(int k = -L; k <= L; ++k)
	    {
	      if(i==0&&j==0&&k==0)
		continue;
	      if((i+j+k) % 2 == 0)//if even
		{
		  tot +=
		    pow(pow(i,2.)+pow(j,2.)+pow(k,2.),-1./2.);
		  //eo = 1;
		}
	      else//odd
		{
		  tot -=
		    pow(pow(i,2.)+pow(j,2.)+pow(k,2.),-1./2.);
		  //eo = -1;
		}
	      //tot +=eo*pow(pow(i,2.)+pow(j,2.)+pow(k,2.),-1./2.);
	    }
	}
    }
  cout<<"The calculated Madelung constant is: "<<tot<<endl;
}
