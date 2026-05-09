#include<bits/stdc++.h>
#define endl '\n'
using ll=long long ;
void solve(){
    int n;
    std::cin>>n;
    std::map<ll,std::vector<ll>>q;
    std::vector<ll>a(n+5);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
        q[a[i]-i].push_back(a[i]);
    }
    ll ans=0;
    int cm=0;
    std::vector<std::vector<ll>>vec(n+5);
    for(auto [v,w]:q){
        ++cm;
        for(auto s:q[v]){
           vec[cm].push_back(s);
        }
    }
   // std::cout<<cm<<endl;
    for(int i=1;i<=cm;i++){
        std::sort(vec[i].begin(),vec[i].end());
    }
    for(int i=1;i<=cm;i++){
        int cnt=1;
        ll sum=0;
        for(int j=vec[i].size()-1;j>=0;j--){
            if(sum<0){
                break;
            }
            if(cnt%2==0){
              sum+=vec[i][j];
              if(sum<0)break;
              ans+=sum;
              sum=0;
            }else{
              sum+=vec[i][j];
            }
            cnt++;
        }
    }
    std::cout<<ans<<endl;
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