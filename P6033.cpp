#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
queue<int>q1,q2;
int a[100005];
signed main(){
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<=100000;i++){
		while(a[i]){
			q1.push(i);
			a[i]--;
		}
	}
	for(int i=1,x,y;i<n;i++){
		if(q2.empty()||(!q1.empty()&&q1.front()<q2.front())){
			x=q1.front();
			q1.pop();
		}else{
			x=q2.front();
			q2.pop();
		}
		if(q2.empty()||(!q1.empty()&&q1.front()<q2.front())){
			y=q1.front();
			q1.pop();
		}else{
			y=q2.front();
			q2.pop();
		}
		ans+=(x+y);
		q2.push(x+y);
	}
	cout<<ans;
	return 0;
}
