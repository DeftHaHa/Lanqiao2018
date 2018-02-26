#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int ans=0;
	bool vis1[100005],vis2[100005];
	memset(vis1,false,sizeof(vis1));
	memset(vis2,false,sizeof(vis2));
	for(int num=100;num<100000;num++)
	{
		string s;
		int temp=num;
		while(temp)
		{
			s+=('0'+temp%10);
			temp/=10;
		}
		int i;
		for(i=0;i<s.size()-1;i++)
		{
			if(s[i]<=s[i+1]) break;
		}
		if(i>0&&i<s.size()-1)
		{
			for(;i<s.size()-1;i++)
			{
				if(s[i]>=s[i+1]) break;
			}
			if(i==s.size()-1)
			{
				vis1[num]=true;
				ans++;
			}
		}
		
	}
	cout<<ans<<endl;
	/*freopen("DATA.txt","r",stdin);
	int n;
	for(int i=0;i<8193;i++)
	{
		scanf("%d",&n);
		vis2[n]=true;
	}
	for(int i=1;i<=100000;i++)
	{
		if(vis1[i]&&!vis2[i]) cout<<"1  "<<i<<endl;
		else if(!vis1[i]&&vis2[i]) cout<<"2  "<<i<<endl;
	}*/
	return 0;
}
