#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
int nxt[500005],pre[500005];
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
    int Q;
    std::cin>>Q;
    int i=0;
    nxt[0]=0;
    while(Q--){
        int opt,x;
        std::cin>>opt;
         ++i;
        if(opt==1){
          std::cin>>x;
          if(nxt[x]==x){
          	 nxt[x]=i;
             nxt[i]=i;
          }else{
          	 nxt[i]=nxt[x];
          	 nxt[x]=i;
          	
          }
          
        }else{
        	int x,y;
            std::cin>>x>>y;
            int p=x,q=y;
            ll sum=0,num=0;
            while(p!=y&&q!=x){
                p=nxt[p];
                sum+=p;
                q=nxt[q];
                num+=q;
            }
            sum-=y,num-=x;
            if(p==y){
            	std::cout<<sum<<endl;
            	nxt[x]=y;

            }else{
            	std::cout<<num<<endl;
            	nxt[y]=x;
            }
        }
    }

    return 0;
}