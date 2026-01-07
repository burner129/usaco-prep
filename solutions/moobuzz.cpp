#include <bits/stdc++.h>
using namespace std;

long long n; 
bool check(long long x){
   x = x - x/3 - x/5 + x/15; 
   return x >= n; 
}
int main(){
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);
	//change to long long 
	cin>>n;
	long long ans, lo = 1, hi = 1e10, m;
	while(lo <= hi){
		m = lo + (hi - lo)/2; 
		if(check(m)){
			ans = m; 
			hi = m - 1;  
		}
		else{
			lo = m + 1; 
		}
	}
	cout<<ans<<'\n'; 
}
