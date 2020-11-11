#include<iostream>
#include <cmath>
#include<cstdlib>
#include <armadillo>

using namespace std;
using namespace arma;
float tensorproduct(float,float);
int main()
{
	
	double c[500],m[500][500],p,m1[500],r[500][500],x[500];
	int i,j,k,d,e,f,g,h,n=1;
	cout<<"Give the dimenson:";
	cin>> d;
	default_random_engine genrator (0);
	normal_distribution <double> distribution (0.0,1.0);
	while(n!=100)
	{
	p=0;
	for(i=1;i<=d*d;i++)
	{
		
		c[i]={distribution(genrator)};
		p=p+c[i]*c[i];
	}
	for(i=1;i<=d*d;i++)
	{
		c[i]=c[i]/sqrt(p);
	}
	for(i=1;i<=d*d;i++)
	{
		for(j=1;j<=d*d;j++)
		{
			 m[i][j]=c[i]*c[j];
		}
	}
	//Partial Trace Part
	//cout<<"Partial trace 2nd system:"<<endl;
	f=0;k=0;h=0;
	while(f!=d*d)
	{
		g=0;e=0;
		while(e!=d*d)
		{
			if(g%d==0)
			{
				k++;
				m1[k]=0;
				for(i=1;i<=d;i++)
				{
					for(j=1;j<=d;j++)
					{
						if(i==j)
						{
							m1[k]=m1[k]+m[i+h][j+g];	
						}
					}
				}
			}
			e++;
			g++;
		}
		f++;
		h=h+d;
	}
	e=0;
	for(i=1;i<=d;i++)
	{
		for(j=1;j<=d;j++)
		{
			r[i][j]=m1[j+e*d];
		}
		e++;
	}
	//Von Neumann Entropy
	mat A(d,d,fill::zeros);
	for(i=0;i<d;i++)
	{
	for(j=0;j<d;j++)
	{
	A(i,j)=r[i+1][j+1];
	}
	}
	// Eigenvalue
	vec B=eig_sym(A);
	//cout<<"The Von Neumann Entropy is:"<<endl;
	p=0;
	for(i=0;i<d;i++)
	{
	    p=p-B(i)*log2(B(i));
	 }
	x[n]=p;
	n++;
	}
	cout<<"Eigenvalues are:"<<endl;
	for(i=1;i<100;i++)
	{
	  cout<<x[i]<<" ";
	  }
	
}
//float tensorproduct(float,float)
//{
//	float a[50][50],b[50][50];
//	int i,j,k;
	
//}
