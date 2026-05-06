#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
const int N=55;
int ans[N][N];
void solve(){
    int n;
    std::cin>>n;
    std::cout<<"Yes"<<endl;
    int m=2*n;
    for(int i=1;i<=n-2;i++){
        for(int j=1;j<=n;j++){
            ans[i][j]=m;
        }
        //std::cout<<endl;
        m--;
    }
    ans[n-1][n-1]=4;
    ans[n-1][n]=1;
    ans[n][n-1]=3;
    ans[n][n]=2;
    for(int i=1;i<=n-2;i++){
        ans[n-1][i]=ans[n][i]=m;
        m--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            std::cout<<ans[i][j]<<" ";
        }
        std::cout<<endl;
    }
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
    int T=1;
  //  std::cin>>T;
    while(T--){
    	solve();
    }
	return 0;
}