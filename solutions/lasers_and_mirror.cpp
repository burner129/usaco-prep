#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7; 


int N, xl, yl, xb, yb;
vector<pair<int, int>> lasers; 
map<int, vector<int>> vneighbors, hneighbors;

int bfs(int dir){
	queue<vector<int>> q; 
	map<int, vector<int>> vdist, hdist; 
	for(auto v : vneighbors){
		for(int i = 0; i < (int)v.second.size(); i++){
			vdist[v.first].push_back(-1);
		}
	}
	for(auto v : hneighbors){
		for(int i = 0; i < (int)v.second.size(); i++){
			hdist[v.first].push_back(-1);
		}
	}
	q.push({xl, yl, 0, dir});
	while(!q.empty()){
		vector<int> top = q.front(); 
		q.pop();
		int x = top[0], y = top[1], dist = top[2], dir = top[3];  
		if(dir == 0){
			if(y == yb){return dist;} 
			for(int i = 0; i < (int)hneighbors[y].size(); i++){
				if(hdist[y][i] == -1 && hneighbors[y][i] != x){
					hdist[y][i] = dist + 1; 
					q.push({hneighbors[y][i], y, dist + 1, (dir + 1)%2}); 
				}
			}
		}
		else if(dir == 1){
			if(x == xb) {return dist;}
			for(int i = 0; i < (int)vneighbors[x].size(); i++){
				if(vdist[x][i] == -1 && vneighbors[x][i] != y){
					vdist[x][i] = dist + 1; 
					q.push({x, vneighbors[x][i], dist + 1, (dir + 1)%2}); 
				}
			}
		}
	} 
	return 1e9; 
}
                                          
int main(){
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
	cin>>N>>xl>>yl>>xb>>yb;                     
	for(int i = 0; i < N; i++){
		int x, y; cin>>x>>y;
		lasers.emplace_back(x, y);
		vneighbors[x].push_back(y);
		hneighbors[y].push_back(x); 
	}
	int ans = min(bfs(0), bfs(1));
	if(ans == 1e9) cout<<-1<<'\n';
	else cout<<ans<<'\n'; 
}     	
