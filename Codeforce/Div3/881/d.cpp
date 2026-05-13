#include<bits/stdc++.h>
using ll=long long;
class Tree{
public:
    std::vector<std::vector<int>>adj;
    std::vector<int>pre,dep,siz;
    std::vector<std::array<int,30>>fa;
    int n;
    Tree(int n):n(n+1){
        init();
    }
    void init(){
        adj.resize(n+1),pre.resize(n+1),fa.resize(n+1);
        pre[1]=0;//给定1节点为根节点
        dep.assign(n+1,0);
        siz.assign(n+1,0);
    }
    void add(int u,int v){//加边操作
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u,int f){
        dep[u]=dep[f]+1;
        if(adj[u].size()==1&&u!=1){
        	  siz[u]=1;
           return ;
        }
        for(auto v:adj[u]){
            if(v==f)continue;
            dfs(v,u);
            pre[v]=u;
            siz[u]+=siz[v];
        }
    }
    void build(int  n){
        for(int i=1;i<=n;i++){
            fa[i][0]=pre[i];
        }
        for(int i=1;i<=22;i++){
            for(int u=1;u<=n;u++){
                fa[u][i]=fa[fa[u][i-1]][i-1];
            }
        }
    }//建立倍增表

    int LCA(int x,int y){
        if(dep[x]<dep[y]){//保证x处于深度较大的位置
            std::swap(x,y);
        }
        int pos=x;
        int len=dep[x]-dep[y];
        for(int i=22;i>=0;i--){
            if((len>>i)&1){
                pos=fa[pos][i];
                len-=(1<<i);
            }
            if(len==0)break;
        }
        x=pos;
        if(x==y)return x;
        for(int j=22;j>=0;j--){
            if(fa[x][j]==fa[y][j]){
                continue;
            }else{
                x=fa[x][j],y=fa[y][j];
            }
        }
        return fa[x][0];
    }
    int dis(int x,int y){//树上两点距离
        return dep[x]+dep[y]-2*dep[LCA(x,y)];
    }
};
void solve(){
	int n;
	std::cin>>n;
	Tree d(n);
	int u,v; 
	for(int i=0;i<n-1;i++){
		std::cin>>u>>v;
		d.add(u,v);
	}
	d.dfs(1,0);
	d.build(n);
   int q;
   std::cin>>q;
   while(q--){
   	ll ans=0;
   	std::cin>>u>>v;
   	int pre1=d.LCA(u,v);
   	if(u!=pre1&&v!=pre1){
   		ans=1ll*d.siz[u]*d.siz[v];
   		//ans+=1ll*d.siz[u]*d.siz[u]+1ll*d.siz[v]*d.siz[v];

   	}else if(u==pre1&&v!=pre1){
   		 ll ms=d.siz[u]-d.siz[v];
          ans=1ll*d.siz[v]*d.siz[v];
          ans+=1ll*ms*d.siz[v];
   	}else if(u!=pre1&&v==pre1){
   		 ll ms=d.siz[v]-d.siz[u];
          ans=1ll*d.siz[u]*d.siz[u];
          ans+=1ll*ms*d.siz[u];
   	}else{
   		ans=1ll*d.siz[u]*d.siz[u];
   	}
   	std::cout<<ans<<'\n';
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
}