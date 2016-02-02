#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main()
{
  cout<<"This program outputs all prime numbers between 1 and 
1000."<<endl;
  vector<int> primes;
  primes.push_back(2);
  bool prime = true;
  for(int i = 3; i <= 10000; ++i)
    {
      prime = true;
      for(auto j : primes)
	{
	  if(j > sqrt(i))
	    break;
	  if(i % j == 0)
	    {
	      prime = false;
	      break;
	    }
	}
      if(prime)
	{
	  primes.push_back(i);
	}
    }
  for(int i = 0; i < primes.size(); i+=10)
    {
      for(int j = 0; j<10; ++j)
	{
	  if(i+j>=primes.size())
	    break;
	  cout<<primes[i+j]<<'\t';
	}
      cout<<endl;
    }
}
