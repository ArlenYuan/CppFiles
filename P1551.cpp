#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int fa[maxn],n,m,p;
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
string YNq(int x,int y){
	int rx=find(x);
	int ry=find(y);
	return (rx==ry?"Yes\n":"No\n");
}
int main(){
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		merge(x,y);
	}
	for(int i=1,x,y;i<=p;i++){
		cin>>x>>y;
		cout<<YNq(x,y);
	}
	return 0;
}