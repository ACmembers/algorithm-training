#include<bits/stdc++.h>
using ll=long long;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int r,d;
	ll x;
	//std::cin>>r>>d;
    std::cin>>r>>d>>x;
    for(int i=1;i<=10;i++){
    	std::cout<<x*r-d<<'\n';
    	x=x*r-d;
    }

	return 0;
}