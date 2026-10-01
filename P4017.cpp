#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5,mod=80112002;
int n,m;
vector<int> g[maxn];
int indeg[maxn],outdeg[maxn];
long long dp[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        indeg[v]++;
        outdeg[u]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indeg[i]){q.push(i);dp[i]=1;}
    }
    long long ans=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        if(!outdeg[u]) ans=(ans+dp[u])%mod;
        for(int v:g[u]){
            dp[v]=(dp[v]+dp[u])%mod;
            if(--indeg[v]==0) q.push(v);
        }
    }
    cout<<ans<<endl;
    return 0;
}