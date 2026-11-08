#include<bits/stdc++.h>
using namespace std;
int v[65][3],p[65][3];
int f[65][32005];
int n,m;
int main(){
	cin>>n>>m;
	for(int i=1,a,b,c;i<=m;i++){
		cin>>a>>b>>c;
		if(!c){
			v[i][0]=a;
			p[i][0]=b;
		}else if(!v[c][1]){
			v[c][1]=a;
			p[c][1]=b;
		}else{
			v[c][2]=a;
			p[c][2]=b;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=n;j++){
			f[i][j]=f[i-1][j];
			if(v[i][0]<=j)
				f[i][j]=max(f[i][j],f[i-1][j-v[i][0]]+v[i][0]*p[i][0]);
			if(v[i][0]+v[i][1]<=j)
				f[i][j]=max(f[i][j],f[i-1][j-v[i][0]-v[i][1]]+v[i][0]*p[i][0]+v[i][1]*p[i][1]);
			if(v[i][0]+v[i][2]<=j)
				f[i][j]=max(f[i][j],f[i-1][j-v[i][0]-v[i][2]]+v[i][0]*p[i][0]+v[i][2]*p[i][2]);
			if(v[i][0]+v[i][1]+v[i][2]<=j)
				f[i][j]=max(f[i][j],f[i-1][j-v[i][0]-v[i][1]-v[i][2]]+v[i][0]*p[i][0]+v[i][1]*p[i][1]+v[i][2]*p[i][2]);
		}
	}
	cout<<f[m][n];
} 
