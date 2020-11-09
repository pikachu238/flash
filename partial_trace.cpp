#include<iostream>
#include <cmath>
#include<cstdlib>
using namespace std;
float tensorproduct(float,float);
main()
{
	float c[500],m[500][500],p=0,m1[500],r[500][500];
	int i,j,k,d,e,l=1,f,g,h;
	cout<<"Give the dimenson:";
	cin>> d;
	for(i=1;i<=d*d;i++)
	{
		c[i]=rand()%10;
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
	cout<<"Partial trace 2nd system:"<<endl;
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
	cout<<"\n"<<" ";
	for(i=1;i<=d;i++)
	{
		for(j=1;j<=d;j++)
		{
			cout<<r[i][j]<<" ";
		}
		cout<<"\n"<<" ";
	}
	//Von Neumann Entropy
	cout<<"\n"<<" ";
	cout<<"The Von Neumann Entropy is:"<<endl;
	
}
//float tensorproduct(float,float)
//{
//	float a[50][50],b[50][50];
//	int i,j,k;
	
//}

