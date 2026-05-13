#include<bits/stdc++.h>
using ll=long long;
int d[100005];
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N,M;

	int l,r;
	std::cin>>N>>M;
	memset(d,0,sizeof(d));
    for(int i=1;i<=M;i++){
    	std::cin>>l>>r;
    	d[l]++,d[r+1]--;
    }

    int sum=0;
    int ans=0;
    for(int i=1;i<=N;i++){
    	sum+=d[i];
    	if(sum==M){
    		ans++;
    	}
    }
    std::cout<<ans<<'\n';

	return 0;
}