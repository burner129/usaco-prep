#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7; 
                                          
int main(){
	//freopen("talent.in", "r", stdin);
	//freopen("talent.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
	// if even number of 1s then automatic tie
	//   
	int N, M; cin>>N>>M;
	vector<vector<int>> adj(N);
	for(int i = 0; i < M; i++){
		int a, b; cin>>a>>b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 1e9; 
	for(int i = 0; i < N; i++){
		queue<int> q; 
		vector<int> dist(N, -1), parent(N, -1); 
		q.push(i);
		dist[i] = 0;
		while(!q.empty()){
			int l = q.front(); 
			q.pop();
			for(auto neighbor : adj[l]){
				if(dist[neighbor] == -1){
				dist[neighbor] = dist[l] + 1;
				parent[neighbor] = l;
				q.push(neighbor); }
				else if(neighbor != parent[l]){
					ans = min(ans, dist[l] + dist[neighbor] + 1);
				}  
			}
		}
	}
	if(ans == 1e9) cout<<-1;
	else cout<<ans; 		 
		             		
}     	
