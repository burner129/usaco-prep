#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7; 

class DSU{
	private:
		vector<int> parents, sizes; 
	public:
		DSU(int size) : parents(size), sizes(size, 1) {
			for(int i = 0; i < size; i++){
				parents[i] = i; 
			}
		}
		int find(int x){
			return parents[x] == x ? x : (parents[x] = find(parents[x]));
		}
		bool unite(int x, int y){
			int x_root = find(x), y_root = find(y); 
			if(x_root == y_root) return false; 
			if(sizes[x_root] < sizes[y_root]) swap(x_root, y_root);
			parents[y_root] = x_root; 
			sizes[x_root] += sizes[y_root];
			return true; 
		}
		bool connected(int x, int y){
			return find(x) == find(y); 
		}
};
                                          
int main(){
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int N, M; cin>>N>>M;
    vector<int> cows;
    vector<pair<int, int>> unsorted; 
    vector<vector<int>> wormholes;
    bool done = true; 
    for(int i = 0; i < N; i++){
    	int x; cin>>x; x--;
    	cows.push_back(x);
    	if(x != i){ unsorted.emplace_back(x, i); done = false; }
    }
    if(done){cout<<-1<<'\n'; return 0;} 
    for(int i = 0; i < M; i++){
    	int a, b, w; cin>>a>>b>>w; a--; b--;
    	wormholes.push_back({w, a, b});
    }
    sort(wormholes.rbegin(), wormholes.rend());
    DSU ds = DSU(N);
    vector<pair<int, int>> cp;
    int wormhole_counter = 0;  
    for(int i = 0; i < N; i++){
    	while(!ds.connected(i, cows[i])){
    		ds.unite(wormholes[wormhole_counter][1],wormholes[wormhole_counter][2]);
    		wormhole_counter++;
    	}
    }
    cout<<wormholes[wormhole_counter - 1][0]<<'\n';	 
}     	
