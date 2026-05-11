#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
using ill=__int128;
const int N=25;
ll dp[N][N];
std::vector<int>num;
ll f(int pos,int presum,int limit,bool zero){
    if(pos<0&&zero)return 0;
    if(pos<0)return 1;
    if(!limit&&presum>=0&&dp[pos][presum]!=-1)return dp[pos][presum];
    int mx=(limit?num[pos]:9);
    ll res=0;
    //对于贴着上界放的那么就一定得保证其不越过此时的数位值
    //如果不是的话,那么下一位显然是可以考虑任取一位判断
    for(int i=0;i<=mx;i++){
       if(abs(i-presum)<2)continue;
       if(!i&&zero){
           res+=f(pos-1,-2,limit&&(i==num[pos]),1);//取前导零状况
       }else{
           res+=f(pos-1,i,limit&&(i==num[pos]),0);//考虑是否有限制
       }
    }
    if(!limit&&!zero)dp[pos][presum]=res;
    return res;
}
void cal(ll x){
   while(x){
      num.push_back(x%10);
      x/=10;
   }
}
void solve(){
   ll a,b;
   std::cin>>a>>b;
   memset(dp,-1,sizeof(dp));
   cal(b);
   ll sum1=f(num.size()-1,-2,1,1);
   num.clear();
   cal(a-1);
   memset(dp,-1,sizeof(dp));
   ll sum2=f(num.size()-1,-2,1,1);
   std::cout<<sum1-sum2<<endl;
   //std::cerr<<sum1<<endl;

}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T=1;
  // std::cin>>T;
    while(T--){
    	solve();
    }

	return 0;
}