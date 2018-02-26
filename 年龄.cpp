#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int ans=0;
	for(int i=10;i<100;i++)
	{
		int a1=i/10,a2=i%10;
		for(int j=10;j<100;j++)
		{
			int b1=j/10,b2=j%10;
			if(i==(b1+b2)*2&&j==(a1+a2)*3)
			{
				ans++;
				cout<<i<<' '<<j<<endl;
			}
		}
	}
	cout<<ans<<endl;
}
