#include<bits/stdc++.h>
#define fi first
#define sc second
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using ll=long long ;
using ull=unsigned long long;
using i128=__int128;
using PII=std::pair<int,int>;
using Pll=std::pair<int,ll>;
using std::string;
const string s1="Yes";
const string s2="No";
const int Mod=998244353;
const int N=1e5+400;
ll b[N][335],c[N][335];
void init(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<335;j++){
            b[i][j]=0,c[i][j]=0;
        }
    }
}
void solve(){
    int n,q;
    std::cin>>n>>q;
    std::vector<int>a(n+5);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    init(n+335);
    //二阶后缀和求等差类似物
    
    for(int i=n;i>=1;i--){
        for(int j=1;j<=sqrt(n);j++){
            if(i+j>n){
                b[i][j]+=a[i];
                continue;
            }
            b[i][j]=b[i+j][j]+a[i];
          //  std::cout<<i<<" "<<b[i][j]<<endl;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=sqrt(n);j++){
            if(i+j>n){
                c[i][j]+=b[i][j];
                continue;
            }
            c[i][j]=c[i+j][j]+b[i][j];//等差数列类似物
        }
    }
    while(q--){
        int s,d,k;
        std::cin>>s>>d>>k;
        if(d>=sqrt(n)){
            ll ans=0;
            int cnt=1;
            for(int i=s;i<=(s+d*(k-1));i+=d){
                ans+=1ll*cnt*a[i];
                ++cnt;
            }
            std::cout<<ans<<" ";
        }else{
            if(d*k>n){
                std::cout<<c[s][d]<<" ";
            }else{
                 ll ans=c[s][d]-c[s+d*k][d]-1ll*k*b[s+d*k][d];
                std::cout<<ans<<" ";
            }
        }
    }
    std::cout<<endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T=1;
    std::cin>>T;
    while(T--){
        solve();
    }

    return 0;
}