#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
/*
0 2 6 0 0 0 0 0 0
0 0 0 5 0 2 0 0 4
0 0 0 1 0 0 0 0 7
0 3 0 0 2 0 1 8 0
0 0 0 3 0 9 0 0 0
0 5 4 0 1 0 0 7 0
5 0 0 0 0 1 0 0 0
6 0 0 9 0 7 0 0 0
0 0 0 0 0 0 7 5 0
*/
bool visi[10][10],visj[10][10],VIS[10][10];
int m[10][10];
set<int> S;
bool check(int x,int y,int num)
{
	if(visi[x][num]||visj[y][num]) return false;
	int xx=x/3*3,yy=y/3*3;
	for(int i=xx;i<xx+3;i++)
	{
		for(int j=yy;j<yy+3;j++)
		{
			if(m[i][j]==num&&i!=x&&j!=y) return false;
		}
	}
	return true;
}
void display()
{
	for(int ansi=0;ansi<9;ansi++)
	{
		for(int ansj=0;ansj<9;ansj++)
		{
			cout<<m[ansi][ansj]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}
void dfs(int tot)
{
	if(tot==81)
	{
		display();
		return;	
	}
	int x=tot/9;
	int y=tot%9;
	if(!m[x][y])
	{
		for(int num=1;num<=9;num++)
		{
			if(check(x,y,num))
			{
				visi[x][num]=true;
				visj[y][num]=true;
				m[x][y]=num;
				dfs(tot+1);
				m[x][y]=0;
				visi[x][num]=false;
				visj[y][num]=false;
			}
		}
	}
	else dfs(tot+1);
}
int main()
{
	freopen("DATA.txt","r",stdin);
	char ch;
	memset(visi,false,sizeof(visi));
	memset(visj,false,sizeof(visj));
	memset(m,0,sizeof(m));
	memset(VIS,false,sizeof(VIS));
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			scanf("%d ",&m[i][j]);
			int n=m[i][j];
			if(n) visi[i][n]=visj[j][n]=VIS[i][j]=true;		
		}
	}
	dfs(0);
	return 0;
}
