#include<bits/stdc++.h>
using namespace std;
int a[13],sum,cun;
int main(){
	for(int i=1;i<=12;i++){
		cin>>a[i];
		sum+=300;
	//	cout<<": "<<sum<<endl;
		if(sum<a[i]){
			cout<<"-"<<i;
			return 0;
		}
		int mis=(sum-a[i])/100*100;
	//	cout<<"mis: "<<mis<<endl;
		cun+=mis;
		sum-=mis;
		sum-=a[i];
	}
	cout<<sum+(int)1.0*cun*(1.2);
}
