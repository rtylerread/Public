#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void Decomp(vector<vector<float> >& a, vector<vector<float> >& l,
	    vector<vector<float> >& u);
int main()
{

  vector<vector<float> > A = {{2, 1, 4, 1},//change these lines
			      {3, 4,-1,-1},//for use with
			      {1,-4, 1, 5},//different matrices
			      {2,-2, 1, 3}};
  //cout<<A[0][0];
  vector<vector<float> >
    L = {{0, 0, 0, 0},
	 {0, 0, 0, 0},
	 {0, 0, 0, 0},
	 {0, 0, 0, 0}},
    U ={{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0}};

  Decomp(A,L,U);
  cout<<"Original Matrix: "<<endl;
  for(auto itr : A)
    {
      for(auto itr2 : itr)
	cout<<itr2<<'\t';
      cout<<endl;
    }
  cout<<"\nMatrix L:"<<endl;
  for(auto itr : L)
    {
      for(auto itr2 : itr)
	cout<<itr2<<'\t';
      cout<<endl;
    }
  cout<<"\nMatrix U:"<<endl;
  for(auto itr : U)
    {
      for(auto itr2 : itr)
	cout<<itr2<<'\t';
      cout<<endl;
    }

}
void Decomp(vector<vector<float> >& a, vector<vector<float> >& l,
	    vector<vector<float> >& u)
{
  int size = a.size();//all vectors are square and equal size.
  for(int i = 0; i < size; ++i)
    {
      for(int j = 0; j < size; ++j)
	{
	  if(j<i) l[j][i] = 0;
	  else
	    {
	      l[j][i] = a[j][i];
	      for(int k = 0; k < i; ++k)
		{
		  l[j][i] -= (l[j][k] * u[k][i]);
		}
	    }
	}
      for(int j = 0; j < size; ++j)
	{
	  if(j<i)
	    u[i][j]=0;
	  else if(j==i)
	    u[i][j] = 1;
	  else
	    {
	      u[i][j] = a[i][j]/l[i][i];
	      for(int k = 0; k < i; ++k)
		u[i][j] -= ((l[i][k] * u[k][j]) / l[i][i]);
	    }
	}
    }
}
