#include<bits/stdc++.h>
using namespace std;
int len,n,k;
int a[100005];
bool check(int x){
	int cnt=k;
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]>x){
			int u=(a[i]-a[i-1]-1)/x;
			cnt-=u;
		//	cout<<u<<' ';
			//max(1,(a[i]-a[i-1])/x-1);
		}
	}
//	cout<<endl<<cnt<<endl;
	return cnt>=0;
}
signed main(){
	cin>>len>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[++n]=len;
	sort(a+1,a+1+n);
	int l=1,r=len+1,mid;
	while(l<r){
		mid=l+r>>1;
	//	cout<<mid<<' '<<l<<' '<<r<<"\n";
		if(check(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}cout<<l;
	return 0;
} 
