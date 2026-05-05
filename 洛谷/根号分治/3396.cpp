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
void init(){
}
const int N=3e5+10;
int a[N];
int b[1000][1000];
void solve(){
     int n,m;
     std::cin>>n>>m;
     memset(b,0,sizeof(b));
     //目标是去优化小于sqrt(n)的状况
     for(int i=1;i<=n;i++){
        std::cin>>a[i];
     }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=sqrt(n);j++){
            b[j][i%j]+=a[i];//取模于j时i所在的位置
        }
     }
     while(m--){
        char opt;
        int x,y;
        std::cin>>opt>>x>>y;
        if(opt=='A'){
            if(x>=sqrt(n)){
              ll sum=0;
              for(int i=y;i<=n;i+=x){
                  sum+=a[i];
              }  
              std::cout<<sum<<endl;
          }else{
            std::cout<<b[x][y]<<endl;
          }
        }else{
            for(int j=1;j<=sqrt(n);j++){
                b[j][x%j]-=a[x];
                b[j][x%j]+=y;
            }
            a[x]=y; 
        }
     }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T=1;
    //std::cin>>T;
    while(T--){
        solve();
    }

    return 0;
}