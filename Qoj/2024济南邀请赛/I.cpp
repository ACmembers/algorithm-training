#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
void solve(){
    std::string s;
    std::cin>>s;
    std::deque<char>q;
    int n=s.size();
    for(auto x:s){
    	   q.push_back(x);
    }
    if(q.front()==q.back()){
    	   std::cout<<0<<endl;
    	 //  return ;
    }else{
    	   int cnt=0;
    	   while(cnt<=n-1){
            char u=q.front();
            char v=q.back();
            if(u==v){
            	std::cout<<cnt<<endl;
            	return ;
            }else{
            	q.pop_front();
            	q.push_back(u);
               cnt++;
            }
    	   }
    	   std::cout<<-1<<endl;
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
	return 0;
}