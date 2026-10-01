#include<bits/stdc++.h>
using namespace std;
vector<int> g[10005];
int indeg[10005],t[10005],dp[10005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int id,x;
        cin>>id>>t[i];
        while(cin>>x&&x!=0){
            g[x].push_back(id);
            indeg[id]++;
        }
    }
    int ans=0;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){q.push(i);dp[i]=t[i];}
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        ans=max(ans,dp[u]);
        for(int v:g[u]){
            dp[v]=max(dp[v],dp[u]+t[v]);
            if(--indeg[v]==0) q.push(v);
        }
    }
    cout<<ans<<endl;
    return 0;
}