#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int> g[maxn];
bool vis1[maxn];
bool vis2[maxn];
void dfs(int rt){
	stack<int> stk;
	stk.push(rt);
	while(!stk.empty()){
		int u=stk.top();stk.pop();
		if(vis1[u]) continue;
		vis1[u]=true;
		printf("%d ",u);
		for(int i=(int)g[u].size()-1;i>=0;i--){
            int v=g[u][i];
			if(!vis1[v]) stk.push(v);
		}
	}
	return;
}
void bfs(int rt){
	queue<int> q;
	q.push(rt);
    vis2[rt]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		printf("%d ",u);
		for(int v:g[u]){
			if(!vis2[v]){
                vis2[v]=true;
                q.push(v);
            } 
		}
	}
	return;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
	}
    for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	dfs(1);
	printf("\n");
	bfs(1);
	printf("\n");
	return 0;
}
