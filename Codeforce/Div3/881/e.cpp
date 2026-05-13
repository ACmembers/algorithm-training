#include<bits/stdc++.h>
using ll=long long;
void solve(){
    int n,m;
    std::cin>>n>>m;
    int ls,rs;
    std::vector<std::vector<int>>vec(n+5);
    for(int i=1;i<=m;i++){
    	 std::cin>>ls>>rs;
    	 vec[rs].emplace_back(ls-1);
    }
    int l=1,r=n;
    int x;
    std::vector<int>vis(n+5,0);
    int q;
    std::cin>>q;
    for(int i=1;i<=q;i++){
       std::cin>>x;
       vis[x]=i;
    }
    auto check=[&](int mid)->bool{
        std::vector<int>sum(n+5);
        for(int r=1;r<=n;r++){
        	  sum[r]=sum[r-1];
        	  if(vis[r]<=mid&&vis[r]!=0)sum[r]+=1;
           for(auto l:vec[r]){
           	  int len=r-l;
              int cnt=sum[r]-sum[l];
              if(cnt*2>len){
              	  return true;
              }
           }
        }
        return false;
    };
    int ans=-1;
    while(l<=r){
    	 int mid=(l+r)>>1;
    	 if(check(mid)){
          ans=mid;
          r=mid-1;
    	 }else{
          l=mid+1;
    	 }
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