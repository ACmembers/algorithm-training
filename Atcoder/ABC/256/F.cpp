#include<bits/stdc++.h>
const int Mod=998244353;
using ll=long long;
#define c1(i,a) (((1ll*i*i%Mod-3ll*i%Mod)%Mod+Mod)%Mod*a%Mod)
#define c2(i,a) (1ll*i*a%Mod)
#define c3(i,a) (a%Mod)
int N,Q;
int a[300005];

void pl(ll &x,ll y){
	x=((x+y)%Mod+Mod)%Mod;
}
struct Bit{
    ll tr[300005];
    Bit(){}
    void add(int x,ll k){
    	for(int i=x;i<=N;i+=(i&(-i))){
             pl(tr[i],k);
    	}
    }
    ll ask(int x){
    	ll ans=0;
        for(int i=x;i>=1;i-=(i&(-i))){
         pl(ans,tr[i]);
        }
        return ans;
    }
}pre,mid,last;
const int inv=499122177;
void ads(int x,ll k){
   pre.add(x,c1(x,k));
   mid.add(x,c2(x,k));
   last.add(x,c3(x,k));
}
signed main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
    std::cin>>N>>Q;
    for(int i=1;i<=N;i++){
    	std::cin>>a[i];
    }
    
    for(ll i=1;i<=N;i++){
       ads(i,a[i]);
    }  while(Q--){
       int opt;
       std::cin>>opt;
       if(opt==1){
          int x,v;
          std::cin>>x>>v;
         ads(x,(v-a[x]+Mod)%Mod);
         a[x]=v;
       }else{
        ll x;
        std::cin>>x;
         ll ans=0;
         ll p1=pre.ask(x),p2=mid.ask(x),p3=last.ask(x);
         ll t1=((x*x%Mod+3*x%Mod)%Mod+2)%Mod*inv%Mod;
         ll t2=p2*x%Mod;
         ans=p1*inv%Mod;
         ans=(ans-t2+Mod)%Mod;
         ans=(ans+(t1*p3%Mod))%Mod;
       	 std::cout<<ans<<'\n';
       }
    }
	return 0;
}