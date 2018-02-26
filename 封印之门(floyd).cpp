#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int main()
{
	int dis[30][30];
	int s1[1005],s2[1005];
	string s;
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++) s1[i]=s[i]-'a';
	cin>>s;
	for(int i=0;i<l;i++) s2[i]=s[i]-'a';
	int k;
	cin>>k;
	memset(dis,0x3f,sizeof(dis));
	
	char cu,cv;
	char ch=getchar();
	for(int i=0;i<k;i++)
	{
		scanf("%c  %c",&cu,&cv);
		char ch=getchar();
		int u=cu-'a',v=cv-'a';
		dis[u][v]=1;
	}
	for(int i=0;i<=26;i++) dis[i][i]=0;
	for(int x=0;x<26;x++)
	{
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<26;j++)
			{
				dis[i][j]=min(dis[i][x]+dis[x][j],dis[i][j]);
			}
		}
	}
	bool flag=true;
	long long ans=0;
	for(int i=0;i<l;i++)
	{
		if(dis[s1[i]][s2[i]]==INF)
		{
			flag=false;
			cout<<-1<<endl;
			break;
		}
		else ans+=dis[s1[i]][s2[i]];
	}
	if(flag) cout<<ans<<endl;
	return 0;
}
