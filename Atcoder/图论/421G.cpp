#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
const ll INF=std::numeric_limits<ll>::max();
template<class T>
struct MinCostFlow
{
   struct _Edge{
      int to;
      T cap;
      T cost;
      _Edge(int to_, T cap_, T cost_):to(to_),cap(cap_),cost(cost_){}
   };
   int n;
   std::vector<_Edge>e;
   std::vector<std::vector<int>>g;
   std::vector<T>h,dis;
   std::vector<int>pre;
   bool dij(int s,int t){
      dis.assign(n,std::numeric_limits<T>::max());
      pre.assign(n,-1);
      std::priority_queue<std::pair<T,int>,std::vector<std::pair<T,int>>,std::greater<std::pair<T,int>>>que;
      dis[s]=0;
      que.emplace(0,s);
      while(!que.empty()){
        T d=que.top().first;
        int u=que.top().second;
        que.pop();
        if(dis[u]!=d){
            continue;
        }
        for(int i:g[u]){
            int v=e[i].to;
            T cap=e[i].cap,cost=e[i].cost;
            if(cap>0&&dis[v]>d+h[u]-h[v]+cost){
                dis[v]=d+h[u]-h[v]+cost;
                pre[v]=i;
                que.emplace(dis[v],v);
            }
        }
      }
     return dis[t]!=std::numeric_limits<T>::max();
   }
   MinCostFlow(){}
   MinCostFlow(int n_){
      init(n_);
   }
   void init(int n_){
      n=n_;
      e.clear();
      g.assign(n,{});
   }
   void addEdge(int u,int v,T cap,T cost){
      g[u].push_back(e.size());
      e.emplace_back(v,cap,cost);
      g[v].push_back(e.size());
      e.emplace_back(u,0,-cost);
   }
   std::pair<T,T>flow(int s,int t){
       T flow=0;
       T cost=0;
       h.assign(n,0);
       while(dij(s,t)){
          for(int i=0;i<n;i++){
            h[i]+=dis[i];
          }
          T aug=std::numeric_limits<T>::max();
          for(int i=t;i!=s;i=e[pre[i]^1].to){
             aug=std::min(aug,e[pre[i]].cap);
          }
          for(int i=t;i!=s;i=e[pre[i]^1].to){
            e[pre[i]].cap-=aug;
            e[pre[i]^1].cap+=aug;

          }
          flow+=aug;
          cost+=aug*h[t];
       }
    return std::make_pair(flow,cost);
  }
};
int a[305];
int d[305];
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
    int n,m;
    std::cin>>n>>m;
    int s=0,t=n+2,k=n+3;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    MinCostFlow<ll>sp(n+10);
    a[0]=0;
    int sum=0;
    for(int i=1;i<=n;i++){
        d[i]=a[i]-a[i-1];
       // std::cerr<<d[i]<<" ";
        if(d[i]<=0){
            sum-=d[i];
           sp.addEdge(s,i,0,0);
        }else{
           sp.addEdge(s,i,d[i],0);
        }
    }
   // std::cout<<endl;
    sp.addEdge(s,n+1,INF,0);
    for(int i=1;i<=m;i++){
        int l,r;
        std::cin>>l>>r;
        sp.addEdge(r+1,l,INF,1);
    }
    for(int i=1;i<=n;i++){
         if(d[i]<0)sp.addEdge(i,k,-d[i],0);
    }
   // sp.addEdge(t,k,sum,0);
    std::pair<ll,ll> ans=sp.flow(s,k);
   // std::cout<<ans.first<<endl;
    if(ans.first<sum){
        std::cout<<-1<<endl;
    }else{
        std::cout<<ans.second<<endl;
    }
    return 0;
}