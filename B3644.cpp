#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n;
int indeg[maxn];
vector<int> g[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        while(cin>>x&&x!=0){
            g[i].push_back(x);
            indeg[x]++;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indeg[i]) q.push(i);
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        cout<<u<<" ";
        for(int v:g[u]){
            indeg[v]--;
            if(!indeg[v]) q.push(v);
        }
    }
    return 0;
}