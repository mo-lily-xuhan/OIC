#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int>g[10004];
int vis[10004];
queue<int>q;
int find(int x,int col){
	int ct[2]={1,0};
	vis[x]=1;
	q.push(x);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(vis[v]==vis[u]){
				return -1;
			}else if(!vis[v]){
				vis[v]=(vis[u]==1?2:1);
				ct[vis[v]-1]++;
				q.push(v);
			}
		}
	}
	return min(ct[0],ct[1]);
}
int main(){
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			int k=find(i,1);
			if(k<0){
				cout<<"Impossible";
				return 0;
			}
			ans+=k;
		}
	}
	cout<<ans;
	return 0;
} 
