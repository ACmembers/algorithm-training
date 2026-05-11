#include<bits/stdc++.h>
#define endl '\n'
using ll=long long;
using ld=double;
int  a[10];
std::map<std::pair<std::vector<int>,int>,ld>f;
ld work(std::vector<int>p,int s){
    if(f.count({p,s})){//如果这个保留的集合已经被算过了则回溯
        return f[{p,s}];
    }
    if(!s){
        int sum=0,mx=0;
        for(int i=1;i<=6;mx=std::max(sum,mx),sum=0,i++){
           for(int x:p){
             if(x==a[i]){
                sum+=x;
             }
           }
        }
        f[{p,s}]=mx;//该集合情况的最大得分;
        return mx;
    }
    //在目前被锁这些元素的前提下
    int n=5-p.size(),o=1;
    while(n--)o*=6;//多少种不同方案
    n=5-p.size();
    ld sm=0;
    for(int st=0;st<o;st++){
        ld xx=0.00;
        int k=st;
        std::vector<int>v;
        v.clear();
        v.push_back(0);
        for(int i=1;i<=n;i++){
            v.push_back(a[k%6+1]),k/=6;
        }
        if(s==1){
            std::vector<int>w=p;//最后一次投无法有保留
            for(int i=1;i<=n;i++){
                w.push_back(v[i]);
            }
            xx=std::max(xx,work(w,0));
        }else{
        for(int bl=0;bl<(1<<n);bl++){
            std::vector<int>w=p;
            for(int i=1;i<=n;i++){
                if(bl&(1<<(i-1))){
                    w.push_back(v[i]);//选择被保留的集合
                }
            }
            xx=std::max(xx,work(w,s-1));
        }

     }
         sm+=xx;//所有的得分
    }
    f[{p,s}]=sm/o;
    return f[{p,s}];
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
    for(int i=1;i<=6;i++){
        std::cin>>a[i];
    }
    //dp[i][s]=第i次投掷和此时被锁定的骰子集合
    ld ans=work({},3);
    std::cout<<std::setprecision(10)<<std::fixed<<ans<<endl;
    return 0;
}