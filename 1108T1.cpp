#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],num[200005];
set<int>st; 
int main(){
	freopen("idle.in","r",stdin);
	freopen("idle.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		num[a[i]]++;
	}
	for(int i=0;i<=200000;i++){
		if(!num[i]){
			st.insert(i);
		}
	}
	while(m--){
		int op,x;
		cin>>op>>x;
		if(op==1){
			num[a[x]]--;
			if(!num[a[x]])st.insert(a[x]);
			cin>>a[x];
			if(!num[a[x]])st.erase(a[x]);
			num[a[x]]++;
		}else{
			auto u=st.upper_bound(x);
			if(u==st.begin()){
				cout<<-1<<endl;
			}else{
				--u;
				cout<<*u<<endl;
			}
		}
	}
	return 0;
}
