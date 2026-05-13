#include<bits/stdc++.h>
using ll=long long;
void solve(){
   ll n;
   std::cin>>n;
   ll ans=0;
   while(n){
      ans+=n;
      n/=2;
   }
   std::cout<<ans<<'\n';
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin>>T;
	while(T--){

		solve();
	}
}