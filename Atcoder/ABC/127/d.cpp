#include<bits/stdc++.h>
using ll=long long;
int a[100005];
using PII=std::pair<int,int>;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

    int n,m;
    std::cin>>n>>m;
    for(int i=1;i<=n;i++){
    	std::cin>>a[i];
    }
    std::priority_queue<PII,std::vector<PII>,std::greater<PII>>pq;
    std::sort(a+1,a+1+n);
    
    std::vector<std::pair<int,int>>mergy;
    for(int i=1;i<=n;i++){
    	if(!mergy.empty()&&mergy.back().first==a[i]){
            mergy.back().second++;
    	}else{
    		mergy.emplace_back(a[i],1);
    	}
    }
    for(auto [x,y]:mergy){
    	//std::cout<<x<<" "<<y<<'\n';
    	pq.push({x,y});
    }

    int B,C;
    for(int i=1;i<=m;i++){
    	std::cin>>B>>C;
    	int num=0;
    	while(!pq.empty()&&pq.top().first<C&&B>0){
             auto [x,y]=pq.top();
             pq.pop();
             if(y>B){
                y-=B;
             	num+=B,B=0;
             	pq.push({x,y});
             }
             else{
             	num+=y;
             	B-=y;
             }
    	}
    	if(num!=0)pq.push({C,num});
    }

    ll ans=0;
    while(!pq.empty()){
    	auto [x,y]=pq.top();
    	pq.pop();
    	//std::cout<<x<<" "<<y<<'\n';
    	ans+=1ll*x*y;
    }
    std::cout<<ans<<'\n';
	return 0;
}