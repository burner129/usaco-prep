#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long long> &a, pair<long long, long long> &b){
	if(a.first != b.first){
		return a.first < b.first; 
	}
 	return a.second > b.second; 
}
long long h = 1e15; 
int main(){             
	long long N, M; cin>>N; 
	vector<vector<long long>> waypoints;
 	waypoints.push_back({0,0,0}); 
	for(long long i = 1; i < N; i++){
		long long p, d, e; cin>>p>>d>>e;
		p--;                                                                   
		waypoints.push_back({p, d, e}); 
	}
	for(long long i = 1; i < N; i++){
		waypoints[i][2] += waypoints[waypoints[i][0]][2]; 
	}
	vector<vector<pair<long long, long long>>> runs(N, vector<pair<long long, long long>>(11, make_pair(0, 0))); // given a courage and starting point returns the list has difficulty and enjoyment
	
	for(long long i = 0; i < N; i++){
		long long p = waypoints[i][0], d = waypoints[i][1], e = waypoints[i][2]; 	
		runs[i][0].second = e; 
		runs[i][0].first = max(runs[p][0].first, d); 
		for(long long c = 1; c <= 10; c++){
		    runs[i][c].second = e;
			if(d > runs[p][c].first){
				runs[i][c].first = min(d, runs[p][c - 1].first);	
			}
			else{
				runs[i][c].first = runs[p][c].first;  
			}
		}
	}                                                              
	vector<vector<pair<long long, long long>>> ans(11, vector<pair<long long, long long>>(N));
	for(long long i = 0; i < N; i++){
		for(long long j = 0; j <= 10; j++){
			ans[j][i] = runs[i][j]; 
		}
	}
	
	for(long long i = 0; i <= 10; i++){
		sort(ans[i].begin(), ans[i].end(), cmp);
		long long mxe = 0; 
		for(long long j = 0; j < N; j++){
			mxe = max(ans[i][j].second, mxe);
 			ans[i][j].second = mxe; 
		}	
	}
	
	
	cin>>M;
 	for(long long i = 0; i < M; i++){
		long long s, c; cin>>s>>c;
		auto out = upper_bound(ans[c].begin(), ans[c].end(), make_pair(s, h));
		if(out != ans[c].begin()){
			out = prev(out);   
		}
		cout<<out->second<<'\n';
	} 		

}
