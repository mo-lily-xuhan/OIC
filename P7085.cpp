#include<bits/stdc++.h>
using namespace std;
int w,h,x,y,ans;
int main(){
	cin>>w>>h>>x>>y;
	cout<<(int)
	(ceil((double)(w-x+0.000001)/(double)(x*2-0.000001))
	*ceil((double)(h-y+0.000001)/(double)(y*2-0.0000001)));
}
