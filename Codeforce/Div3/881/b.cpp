#include<bits/stdc++.h>
using ll=long long;
void solve(){
	int n;
	std::cin>>n;
	ll ans=0;
	std::vector<int>a(n);
	for(int i=0;i<n;i++){
		std::cin>>a[i];
		ans+=abs(a[i]);
	}
	int pk=0;
	for(int i=0;i<n;i++){
		int j=i;
		int cnt=0;
		while(j<n&&a[j]<=0){
			//std::cerr<<i<<'\n';
            cnt=std::min(cnt,a[j]);
            j++;
		}
		if(cnt<0)pk++;
		i=j;
	}
	std::cout<<ans<<" "<<pk<<'\n';


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