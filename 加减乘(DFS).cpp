#include<iostream>
#include<cstdio>
using namespace std;
int num[]={0,1,2,3,4,5,6,7,8,9,10};
int ans=0;
int a_b(int a,char o,int b)
{
	if(o=='+') return a+b;
	else return a-b;
}
void dfs(int a,char o,int b,int next)
{
	if(next==11)
	{
		if(a_b(a,o,b)==0) ans++;
		return;
	}
	dfs(a_b(a,o,b),'+',num[next],next+1);
	dfs(a_b(a,o,b),'-',num[next],next+1);
	dfs(a,o,b*num[next],next+1);
}
int main()
{
	dfs(0,'+',1,2);
	cout<<ans<<endl;
	return 0;
}
