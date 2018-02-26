#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int N,M,MM;           
/*
0
1  表示竖着铺   1 1表示横着铺
*/ 
bool firstline(int k)   //检测第一行兼容性 
{
	int i=0;
	while(i<M)
	{
		if(k&(1<<i))
		{
			if(! (k&(1<<(i+1))) ||i ==M-1) return false;
			else i+=2;
		}
		else i+=1;
	}
	return true;
}
/*   兼容性检测 
横铺 
1 1     0
1 1	1   且不是最后一个
竖铺 
1 
0
*/
bool line(int k,int j)
{
	int i=0;
	while(i<M)
	{
		if(j&(1<<i))                       //(i,x)为1 
		{
			if(k&(1<<i))                   //(i-1,x)也为1 
			{
				if(k&(1<<(i+1))&&(j&(1<<(i+1)))&&i!=M-1) i+=2;  //则上下都是横着右突 
				else return false;
			} 
			else i++;   //竖着铺的下头 
		}
		else    //竖着铺的上头则(i-1,x)必为1 
		{
			if(k&(1<<i)) i++;
			else return false;
		}
	}
	return true;
}
int main()
{
	cin>>N>>M;
	MM=1<<M;        //对应最大 2^M-1种状态 
	long long dp[10][MM+5];    //10*10就需要long long 
	memset(dp,0,sizeof(dp));
	for(int j=0;j<=MM;j++)
	{
		if(firstline(j)) dp[0][j]=1;
	}
	for(int i=1;i<N;i++)   //第N行 
	{
		for(int j=0;j<MM;j++)   //j状态 
		{
			for(int k=0;k<MM;k++) //与上一行k状态检测兼容性 
			{
				if(line(k,j)) dp[i][j]+=dp[i-1][k];
			}
		}
	}
	cout<<dp[N-1][MM-1]<<endl;    //最后一行必全为1 
	return 0;
}
