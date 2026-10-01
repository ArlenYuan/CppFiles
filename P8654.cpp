#include<bits/stdc++.h>
using namespace std;
const int maxn= 1e6+10;
int fa[maxn],n,m;
bool isrt[maxn];
void init(){
    for(int i=1;i<=n*m;i++) fa[i]=i;
}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    init();
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int x,y;
        cin>>x>>y;
        int fx=find(x),fy=find(y);
        fa[fx]=fy;
    }
    for(int i=1;i<=n*m;i++){
        isrt[find(i)]=1;
    }
    int ans=0;
    for(int i=1;i<=n*m;i++){
        if(isrt[i]) ans++;
    }
    cout<<ans<<'\n';
    return 0;
}