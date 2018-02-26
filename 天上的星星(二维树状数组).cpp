#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int c[2005][2005];
int lowbit(int x)
{
	return x&(-x);
}
void insert(int x,int y,int num)
{
	for(int i=x;i<=2002;i+=lowbit(i))
		for(int j=y;j<=2002;j+=lowbit(j))
			c[i][j]+=num;
}
int getsum(int x,int y)
{
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			sum+=c[i][j];
	return sum;
}
int main()
{
	int n;
	memset(c,0,sizeof(c));
	cin>>n;
	int x,y,w;
	while(n--)
	{
		scanf("%d%d%d",&x,&y,&w);
		insert(x+2,y+2,w);
	}
	int q;
	scanf("%d",&q);
	int x1,x2,y1,y2;
	while(q--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1+=2;y1+=2;x2+=2;y2+=2;
		int ans=getsum(x2,y2)-getsum(x1-1,y2)-getsum(x2,y1-1)+getsum(x1-1,y1-1);
		printf("%d\n",ans);
	}
	return 0;
}
