#include<bits/stdc++.h>
#define endl '\n'
using ll=long long ;
const int N=1e5+5;
struct Node{
    int v,w;
}a[N];
int c[N],d[N];
int n;
bool cmp1(const int &a,const int &b){
    return a>b;
}
bool check(int mid){
    int cnt=0,cur=0;
   for(int i=1;i<=n;i++){
       if(a[i].v>=mid){
          c[++cnt]=a[i].v+a[i].w;
       }else{
          d[++cur]=a[i].w;
       }
   }
   if(cur>cnt){
     return false;
   }
   std::sort(c+1,c+1+cnt,cmp1);
   std::sort(d+1,d+1+cur,cmp1);
   int pos=1;
   for(int i=1;i<=cnt;i++){
       if(pos>cur){
          break;
       }
       if(c[i]-d[pos]<mid){
         return false;
       }
       pos++;
   }
   return true;
}
bool cmp(const Node &a,const Node &b){
    return a.v>b.v;
}
void solve(){
    std::cin>>n;
    int r;
    for(int i=1;i<=n;i++){
        std::cin>>a[i].v>>a[i].w;
        r=std::max(a[i].v,r);
    }
    std::sort(a+1,a+1+n,cmp);
    int l=1;
    int ans=0;
    while(l<=r){
       int mid=(l+r)>>1;
       if(check(mid)){
           ans=mid;
           l=mid+1;
       }else{
          r=mid-1;
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