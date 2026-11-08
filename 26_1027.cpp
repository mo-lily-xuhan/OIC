#include<bits/stdc++.h>
using namespace std;
#define int long long
//typedef long long ll; 
const int N=2e5+7;
struct T{
	int a,w;
}a[N];
int ans[N],f[N],p,n,m;
bool cmp(T a,T b){
	return a.a>b.a;
}
bool check(int k,int x){
	if(a[k].a+x<a[m].a)return 0;
	int l=1,r=m,mid;
	while(l<r){
		mid=l+r>>1;
		if(a[k].a+x>=a[mid].a)r=mid;
		else l=mid+1;
	}
	return (a[k].a+x+1)*(m-l+1)-(f[m]-f[l-1])+(k<=m&&m<n)*(a[k].a-a[m+1].a)>p-x;
}
signed main(){
	cin>>n>>m>>p;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		a[i].a=x;
		a[i].w=i;
		p-=x;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i].a;
	for(int i=1;i<=n;i++){
		if(a[i].a+p<a[m].a){
			ans[a[i].w]=-1;
			continue;
		}
		int l=0,r=p,mid;
		while(l<r){
			mid=l+r>>1;
			if(check(i,mid))r=mid;
			else l=mid+1;
		}
		ans[a[i].w]=l;
	}
	if(m==n)memset(ans,0,sizeof ans);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<' ';
	}
}
