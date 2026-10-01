#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int fa[maxn],n,m;
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int rx=find(x);
	int ry=find(y);
	fa[rx]=ry;
	return;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1,x,y,z;i<=m;i++){
		cin>>z>>x>>y;
		if(z==1){
			merge(x,y);
		}else{
	        int rx=find(x);
	        int ry=find(y);
	        cout<<(rx==ry?"Y\n":"N\n");
		}
	}
	return 0;
}