#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
using ill=__int128;
void solve(){
    ll n;
    std::cin>>n;
    if(n%4==0)std::cout<<n;
    else if(n%4==1)std::cout<<1;
    else if(n%4==2)std::cout<<n+1;
    else if(n%4==3)std::cout<<0;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int T=1;
    std::cin>>T;
    while(T--){
    	solve();
    }

	return 0;
}