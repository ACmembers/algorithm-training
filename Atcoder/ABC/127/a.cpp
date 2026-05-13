#include<bits/stdc++.h>
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int a,b;
	std::cin>>a>>b;

	if(a<=5)std::cout<<0;
	else if(a>=13)std::cout<<b;
	else{
		std::cout<<b/2;
	}
}