#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct edge
{
	int v,next;
}e[200005];
int p[200005],eid;
int n,P;
int S[100005],E[100005],TIME;
int Rank[100005];
int rmax[400005],rmin[400005];
void addedge(int u,int v)
{
	e[eid].v=v;
	e[eid].next=p[u];
	p[u]=eid++;
}
void dfs(int u)
{
	S[u]=++TIME;
	Rank[TIME]=u;
	for(int i=p[u];i!=-1;i=e[i].next)
	{
		if(!S[e[i].v])
		{
			dfs(e[i].v);
		}
	}
	E[u]=TIME;
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		rmax[p]=rmin[p]=Rank[l];
		return;
	}
	int mid=(r+l)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	rmax[p]=max(rmax[p<<1],rmax[p<<1|1]);
	rmin[p]=min(rmin[p<<1],rmin[p<<1|1]);
}
int query(int p,int x,int y,int l,int r,int num)
{
	int mid=(r+l)>>1;
	if(x<=l&&r<=y)
	{
		if(rmax[p]<num) return r-l+1;
		else
		{
			if(rmin[p]>=num) return 0;
			else return query(p<<1,x,y,l,mid,num)+query(p<<1|1,x,y,mid+1,r,num); 
		}
	}
	int ans=0;
	if(x<=mid) ans+=query(p<<1,x,y,l,mid,num);
	if(y>mid) ans+=query(p<<1|1,x,y,mid+1,r,num);
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
	build(1,1,n);
	for(int i=1;i<n;i++)
	{
		printf("%d ",query(1,S[i],E[i],1,n,i));
	}
	printf("%d\n",query(1,S[n],E[n],1,n,n));
	return 0;
}
