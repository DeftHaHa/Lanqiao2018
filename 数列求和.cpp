#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double c[1005],A[1005];
int n;
int main()
{
	cin>>n;
	cin>>A[0]>>A[n+1];
	for(int i=1;i<=n;i++) cin>>c[i];
	double sum=0;
	for(int i=n,j=2;i>=1;i--,j+=2)
	{
		sum+=j*c[i];
	}
	double ans=(A[n+1]+n*A[0]-sum)/(n+1);
	printf("%.2f\n",ans);
	return 0;
}
