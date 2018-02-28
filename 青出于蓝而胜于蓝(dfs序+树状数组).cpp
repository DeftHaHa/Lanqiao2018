#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct edge
{
	int v,next;
}e[200005];
int p[200005],eid;
int n,P;
int S[100005],E[100005],TIME;
void addedge(int u,int v)
{
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
void dfs(int u)
{
	S[u]=++TIME;
	for(int i=p[u];i!=-1;i=e[i].next)
	{
		if(!S[e[i].v])
		{
			dfs(e[i].v);
		}
	}
	E[u]=TIME;
}
int c[100005];
void modify(int x,int num)
{
	for(int i=x;i<=n;i+=(i&-i)) 
		c[i]+=num;
}
int sum(int x)
{
	int ans=0;
	for(int i=x;i>0;i-=(i&-i)) 
		ans+=c[i];
	return ans;
}
int main()
{
	cin>>n>>P;
	int u,v;
	memset(p,-1,sizeof(p));
	eid=0;
	int temp=n-1;
	while(temp--)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	TIME=0;
	dfs(P);
	memset(c,0,sizeof(c));
	printf("0");
	modify(S[1],1);
	for(int i=2;i<=n;i++)
	{
		printf(" %d",sum(E[i])-sum(S[i]));
		modify(S[i],1);
	}
	return 0;
}
