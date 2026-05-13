#include<bits/stdc++.h>
using ll=long long;
using PII=std::pair<int,int>;
void solve(){
   int n,q;
   std::cin>>n;
   //维护区间子段和最小与最大
   std::vector<std::array<int,2>>dp(n+5);
   std::vector<PII>ans;
   int cnts=1;
   std::vector<int>a(n+5);
   std::vector<std::vector<int>>adj(n+5);
   q=n;
   while(q--){
      char opt;
      std::cin>>opt;
      if(opt=='+'){
         int u,c;
         std::cin>>u>>c;
         adj[u].push_back(++cnts);
         a[cnts]=c;
      }else{
         int u,v,k;
         std::cin>>u>>v>>k;
         ans.emplace_back(v,k);
      }
   }
   a[1]=1;
   auto dfs=[&](auto &&self,int u,int minn,int maxn,int pre,int sum,int premax,int premin)->void{
       int kem=sum+a[u];

       dp[u][0]=std::min(kem-maxn,premin);
       dp[u][1]=std::max(kem-minn,premax);
       int pre1=std::min(dp[u][0],premin);
       int pre2=std::max(dp[u][1],premax);
       int nmin=std::min(kem,minn),nmax=std::max(kem,maxn);
       for(auto v:adj[u]){
          if(v==pre){
             continue;
          }
          self(self,v,nmin,nmax,u,kem,pre2,pre1);
       }
   };
   dfs(dfs,1,0,1,0,0,1,0);
   for(auto [v,w]:ans){
      if(dp[v][0]<=w&&dp[v][1]>=w){
         std::cout<<"Yes"<<'\n';
      }else{
         std::cout<<"No"<<'\n';
      }
   }

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