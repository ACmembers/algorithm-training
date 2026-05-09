#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
using PII=std::pair<int,int>;
const int N=5e5+10;
const int Mod=998244353;
bool cmp(PII &a,PII &b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}
PII c[N];
ll dp[N];
void solve(){
    ll n,k;
    std::cin>>n>>k;
    for(int i=1;i<=n;i++){
        std::cin>>c[i].first>>c[i].second;
    }
    std::sort(c+1,c+1+n,cmp);
    ll cnt=0;
    dp[0]=1;
    std::priority_queue<int,std::vector<int>,std::greater<int>>q;
    for(int i=1;i<=n;i++){
         while(!q.empty()){
            int u=q.top();
            if(u<c[i].first){
                q.pop();
                cnt--;
            }else{
                break;
            }
        }
        dp[i]=dp[i-1]*(std::max(k-cnt,0ll))%Mod;
        cnt++;
        q.push(c[i].second);
    }
    if(dp[n]==0)std::cout<<0<<endl;
    else{
        std::cout<<dp[n]<<endl;
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
	return 0;
}