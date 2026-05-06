#include<bits/stdc++.h>
#define endl '\n'
void solve(){
	int n;
	std::cin>>n;
	std::vector<int>a(n+1);
	std::vector<int>p(n+1);
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	p[n]=n-a[n];
	int minn=p[n];
	for(int i=n-1;i>=1;i--){
        int mex=minn;
        p[i]=mex-a[i];
        minn=std::min(minn,p[i]);
	}
	for(int i=1;i<=n;i++){
		std::cout<<p[i]<<" ";
	}
	std::cout<<endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T=1;
	std::cin>>T;
	while(T--){
		solve();
	}
	return 0;
}