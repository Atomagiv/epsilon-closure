#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
map< int , set<int> > mp;
queue< int > q;
int edge[104];
int f[104][104];
bool w[104][104][200];
int n,m,p;
set<int> zt;
int cnt=0;
int ans[105][205]={0};
bool rec[1005]={0};
int main()
{
	freopen("1.in","r",stdin);
	for (int i=0;i<=100;i++)
		for (int j=0;j<=100;j++)
			f[i][j]=-1;
	cin>>n>>m>>p;
	getchar();
	char z;
	for (int i=1;i<=n;i++)
	{
		cin>>z;
		getchar();
		edge[i]=int(z);
	}
	int x,y;
	
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y;
		getchar();
		cin>>z;
		f[x][y]=int(z);
	}


	zt.insert(0);
	queue<int> q2;q2.push(0);
	bool vis1[200]={0};
			    while (!q2.empty())
			    {
			    	y=q2.front();q2.pop();
			    	for (int i=0;i<=100;i++)
			    		if (f[y][i]==48)
			    		{
			    			zt.insert(i);
			    			if (!vis1[i])
			    			{
				    			q2.push(i);
				    			vis1[i]=1;
				    		}
			    		}
			    }
	cnt++;
	mp[cnt]=zt;
	q.push(1);


	while (!q.empty())
	{
		int x1=q.front();q.pop();
		set<int> r=mp[x1];
		printf("From  %d :\n",x1);
		//move
		for (int j=1;j<=n-1;j++)
		{
			zt.clear();
			char a=edge[j]+'0'-48;
			cout<<"The edge is  "<<a<<":    ";



			set<int>::iterator iter=r.begin();  
		    while(iter!=r.end())  
		    {  
		        x=*iter;
		        for (int i=0;i<=100;i++)
		        	if (f[x][i]==edge[j])
		        		zt.insert(i);

		        ++iter;  
		    }
			queue<int> q1;



		    iter=zt.begin();  
		    while(iter!=zt.end())  
		    {  
		        x=*iter;
		        q1.push(x);
		        ++iter;  
		    }
		    bool vis[200]={0};
		    while (!q1.empty())
		    {
		    	y=q1.front();q1.pop();
		    	for (int i=0;i<=100;i++)
		    		if (f[y][i]==48)
		    		{
		    			zt.insert(i);
		    			if (!vis[i])
		    			{
		    				q1.push(i);
		    				vis[i]=1;
		    			}
		    		}
		    }
		    int cnt2;

		    bool b=1;
		    for (int i=1;i<=cnt;i++)
		    	if (mp[i]==zt)
		    	{
		    		b=0;
		    		cnt2=i;
		    		ans[x1][edge[j]]=i;
		    	}
		    if (b) 
		    {
		    	cnt++;
		    	cnt2=cnt;
		    	mp[cnt]=zt;
		    	ans[x1][edge[j]]=cnt;
		    	q.push(cnt);
		    }


		    iter=zt.begin();  
		    while(iter!=zt.end())  
		    {  
		        x=*iter;
		        if (x==p) rec[cnt2]=1;
		        cout<<x<<' ';
		        ++iter;  
		    }
		    cout<<endl;
		}
		cout<<endl;
	}
	for (int i=1;i<=cnt;i++)
	{
		cout<<i-1<<"  ";
		for (int j=49;j<=200;j++)
		{
			if (ans[i][j]==0) continue;
			cout<<ans[i][j]-1<<"  ";
		}
		cout<<rec[i]<<endl;
	}
	return 0;
}