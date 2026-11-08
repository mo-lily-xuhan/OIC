#include<bits/stdc++.h>
using namespace std;
int n,m,g[2005][2005],ans;
int dp[2005][2005];
int main(){
	memset(dp,0x3f,sizeof dp);
	ans=dp[0][0];
	cin>>n>>m;
	for(int i=0;i<m;i++){
		dp[i][0]=0;
		for(int j=1,x;j<=n;j++){
			cin>>g[i][j];
			g[i][0]+=g[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			dp[j][i]=min(dp[j][i-1],dp[(j+m-1)%m][i-1])+g[j][i];
		}
	}
	for(int i=0;i<m;i++){
		ans=min(ans,dp[i][n]);
	}
	cout<<ans;
	return 0;
}  
