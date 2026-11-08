#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500005],ans[2][500005],cnt[2],sum[2];
struct node{
	int w,id;
}b[500005];
bool cmp(node x,node y){return x.w>y.w;}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}//sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		cin>>b[i].w;
		b[i].id=i;
	}sort(b+1,b+1+n,cmp);
	cnt[0]+=b[1].w;
	ans[0][b[1].id]=0;
	ans[1][b[1].id]=1;
	sum[0]+=a[b[1].id];
	for(int i=2;i<=n;i++){
		if(cnt[0]<=cnt[1]){
			cnt[0]+=b[i].w;
			ans[0][b[i].id]=0;//gei a
			ans[1][b[i].id]=1;//gei b
			sum[0]+=a[b[i].id];//fangan0
		}else{
			cnt[1]+=b[i].w;
			ans[1][b[i].id]=0;
			ans[0][b[i].id]=1;
			sum[1]+=a[b[i].id];//fangan1
		}
	}//ruguo fangan1>fangan0,ze xuanze ans[1]
	for(int i=1;i<=n;i++){
		cout<<ans[(sum[0]<sum[1])][i]<<' ';
	}
}
