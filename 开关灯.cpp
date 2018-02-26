#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	bool l[1005];
	memset(l,true,sizeof(l));
	for(int i=1;i<=1000;i++) if(i%3==0) l[i]=!l[i];
	for(int i=1;i<=1000;i++) if(i%5==0) l[i]=!l[i];
	for(int i=1;i<=1000;i++) if(i%7==0) l[i]=!l[i];
	int ans=0;
	for(int i=1;i<=1000;i++) if(l[i]) ans++;
	cout<<ans<<endl;
	
	//ÈÝ³â½â·¨£º 
	int a=1000;
	int a1=a/3+a/5+a/7,a2=a/15+a/21+a/35,a3=a/3/5/7;
	ans=a-a1+a2-a3 + a2-3*a3;
	cout<<ans<<endl;
	return 0;
}
