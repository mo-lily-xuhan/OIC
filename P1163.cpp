#include<bits/stdc++.h>
using namespace std;
long long M,P;
int t;
bool check(double r){
	double rest=P;
	for(int i=1;i<=t;i++){
		rest=rest*(1+r)-M;
	}
	return rest<=0;
}
signed main(){
	cin>>P>>M>>t;
	double l=0,r=3.5;
	for(int it=0;it<100;it++){
		double mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	printf("%.1f\n",l*100);
}
