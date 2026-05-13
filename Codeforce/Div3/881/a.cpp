#include<bits/stdc++.h>
void solve(){
	int n;
	std::cin>>n;
	std::vector<int>a(n);
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	std::sort(a.begin(),a.end());
	int l=0,r=n-1;
	int ans=0;
	while(l<r){
       ans+=a[r]-a[l];
       l++,r--;
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