#include<bits/stdc++.h>
#define endl '\n'
int a,b;
int pos1=0,pos2=0;
int vec[2]={1,4};
int vom[4]={2,3,5,6};
bool am=false;
int ans,ans1;
void  dfs(int step){
	 if(am)return ;
     if(step==4){
     	//std::cout<<ans<<" "<<ans1<<endl;
     	if(ans1==b&&ans==a){
     		am=true;
     	}
        return ;
     }
     if(ans!=a){
       for(int i=0;i<2;i++){
     	  ans+=vec[i];
     	  dfs(step+1);
     	  ans-=vec[i];
       }
     }else{
     	for(int i=0;i<4;i++){
             ans1+=vom[i];
             dfs(step+1);
             ans1-=vom[i];
     	}
     }
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
    //int a,b;
    ans=ans1=0;
    std::cin>>a>>b;
    dfs(1);
    if(am)std::cout<<"Yes"<<endl;
    else{
    	std::cout<<"No"<<endl;
    }

	return 0;
}