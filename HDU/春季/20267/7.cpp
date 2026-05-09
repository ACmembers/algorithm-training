#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
using ill=__int128;
const int N=550;
ll dp[N][N][3];
//最近的天数我考虑了第i天与i-1天
//最近两天购买0,1,2张股票
//1为本身去购买的情况
const ll MAXN=1e15;
void init(int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<3;k++){
                dp[i][j][k]=-MAXN;
            }
        }
    }
}

void solve(){
    int n;
    std::cin>>n;
    std::vector<ll>a(n+5);
    for(int i=1;i<=n+1;i++){
        std::cin>>a[i];
    }
    init(n+5);
    dp[0][0][0]=0;
    dp[1][1][1]=-a[1];
    dp[2][2][2]=-a[1]-a[2];
    dp[2][0][0]=-a[1]+a[2];
    if(n==1){
        std::cout<<-a[1]+a[n+1]<<endl;
        return ;
    }else if(n==2){
        std::cout<<std::max(-a[1]-a[2]+2*(a[n+1]),-a[1]+a[2])<<endl;
        return ;
    }
    ll ans=0;
    for(int i=3;i<=n;i++){
        for(int j=0;j<=i;j++){
             //buy
            if(j>0){
                dp[i][j][1]=std::max(dp[i-1][j-1][0]-a[i],dp[i][j][1]);
                dp[i][j][2]=std::max({dp[i-1][j-1][1]-a[i],dp[i-1][j-1][2]-a[i],dp[i][j][2]});
            }
            //sell
            if(j<i)dp[i][j][0]=std::max({dp[i][j][0],dp[i-1][j+1][1]+a[i],dp[i-1][j+1][0]+a[i]});
            if(a[i-1]<a[i-2]&&j<i)dp[i][j][0]=std::max(dp[i][j][0],dp[i-1][j+1][2]+a[i]);
        }
    }
    for(int i=0;i<=n;i++){
        ll maxn=std::max({dp[n][i][0],dp[n][i][1],dp[n][i][2]})+i*a[n+1];
        ans=std::max(ans,maxn);
    }
    std::cout<<ans<<endl;
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