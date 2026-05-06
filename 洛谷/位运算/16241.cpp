#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
using ill=__int128;
ll work(ll n){
    if(n%4==0)return n;
    else if(n%4==3)return 0ll;
    else if(n%4==1)return 1ll;
    else return n+1;
}
const int N=6e7+10;
int cnt[N],val[N],ansp[N];
void solve(){
    ll n;
    int q;
    std::cin>>n>>q;
    ll b=0;
    ll ans=0;
    //[n/2+1,n]中筛选过后集合将为空
    //提示:在删除某个极大值后集合将小于B[i]且所有小于等于N/2的数将会全部被删除掉(是否是最小次数？)
    if(n>=6e7){
      while(q--){
       std::cin>>b;
       b^=ans;
       ll m=n/2;
       ans=(work(m+b)^work(m));
       std::cout<<ans<<endl;
     }
   }else{
      if(n<6e7){
         for(int i=1;i<=n;i++){
            cnt[n%i]++;//某一时刻的元素数量
            val[n%i]^=i;//获取了每一个时刻的元素个数
         }
         int cur=0,tot=0,xr=0;//cur代表的是第一次小于cur时的一个答案
         for(int i=n;i>=0;i--){
            while(cur<=n&&cur<tot+cnt[i]){
                ansp[cur]=xr;
                cur++;
            }
            xr^=val[i],tot+=cnt[i];
         }
         while(cur<=n)ansp[cur]=xr,cur++;
         while(q--){
            std::cin>>b;
            b^=ans;
            ans=ansp[b];
            std::cout<<ans<<endl;
         }
      }
   }

}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T=1;
    //std::cin>>T;
    while(T--){
    	solve();
    }

	return 0;
}