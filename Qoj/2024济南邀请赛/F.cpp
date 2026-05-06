#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
const int N=5e5+10;
ll sum[N];
void init(int n){
     for(int i=1;i<=n;i++){
     	sum[i]=0;
     }
}
void solve(){
	int n;
	std::cin>>n;
	std::vector<int>a(n+5);
	sum[0]=0;
	init(n);
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	std::sort(sum+1,sum+n);
	std::vector<ll>num(n+5);
	num[0]=0;
	for(int i=1;i<=n;i++){
		num[i]=num[i-1]+sum[i];
	}
	for(int i=1;i<=n;i++){
		ll ans=0;
		ans=1ll*i*sum[n]-num[i-1];
		std::cout<<ans<<" ";
	}
	std::cout<<endl;

}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
    int T;
    std::cin>>T;
    while(T--){
    	solve();
    }
	return 0;
}