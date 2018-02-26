#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int N,M,MM;           
/*
0
1  ��ʾ������   1 1��ʾ������
*/ 
bool firstline(int k)   //����һ�м����� 
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
/*   �����Լ�� 
���� 
1 1     0
1 1		1   �Ҳ������һ��
���� 
1 
0
*/
bool line(int k,int j)
{
	int i=0;
	while(i<M)
	{
		if(j&(1<<i))                       //(i,x)Ϊ1 
		{
			if(k&(1<<i))                   //(i-1,x)ҲΪ1 
			{
				if(k&(1<<(i+1))&&(j&(1<<(i+1)))&&i!=M-1) i+=2;  //�����¶��Ǻ�����ͻ 
				else return false;
			} 
			else i++;   //�����̵���ͷ 
		}
		else    //�����̵���ͷ��(i-1,x)��Ϊ1 
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
	MM=1<<M;        //��Ӧ��� 2^M-1��״̬ 
	long long dp[10][MM+5];    //10*10����Ҫlong long 
	memset(dp,0,sizeof(dp));
	for(int j=0;j<=MM;j++)
	{
		if(firstline(j)) dp[0][j]=1;
	}
	for(int i=1;i<N;i++)   //��N�� 
	{
		for(int j=0;j<MM;j++)   //j״̬ 
		{
			for(int k=0;k<MM;k++) //����һ��k״̬�������� 
			{
				if(line(k,j)) dp[i][j]+=dp[i-1][k];
			}
		}
	}
	cout<<dp[N-1][MM-1]<<endl;    //���һ�б�ȫΪ1 
	return 0;
}
