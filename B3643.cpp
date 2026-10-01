#include<bits/stdc++.h>
using namespace std;
vector<int> g[1005];
int gr[1005][1005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		gr[u][v]=1;
		gr[v][u]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<gr[i][j]<<" ";
		}
		cout<<endl;
	} 
	for(int i=1;i<=n;i++){
		cout<<g[i].size()<<" ";
		sort(g[i].begin(),g[i].end());
		for(int x:g[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}
