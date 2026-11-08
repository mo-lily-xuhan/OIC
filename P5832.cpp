#include<bits/stdc++.h>
using namespace std;
int n;
string s,s0;
int main(){
	cin>>n>>s; 
	for(int i=1;i<=n;i++){
		bool f=0;
		for(int j=0;j<n-i;j++){
			s0=s.substr(j,i);
			if(s.find(s0,j+1)<=n){
				f=1;
				break;
			}
		}
		if(!f){
			cout<<i;
			return 0;
		}
	}
}
