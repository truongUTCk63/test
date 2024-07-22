#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void path(int s,int f, int *p)
{
	if(s==f) cout<<s;
	else{
		path(s,p[f],p);
		cout<<"->"<<f;
	}
}
main(){
	int n,m,k,s,f;
	queue<int> q;
	cin>>n>>m>>s>>f;
	int d[n+5]={};
	p[n+5];
	d[s]=1;
	q.push(s);
	while(q.size() and d[f]==0)
	{
		int u=q.front();
		q.pop();
		for(int v:{u+k,u-m})
		if(1<=v && v<=n && d[v]==0)
		{
			d[v]=d[u]+1;
			
			q.push(v);
		}
	}
	cout<<d[f]-1;
}
