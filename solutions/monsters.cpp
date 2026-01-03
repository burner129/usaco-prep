#include <bits/stdc++.h>
using namespace std;
            
int dy[4] = {-1, 1, 0, 0}, dx[4] = {0, 0, -1, 1}; 
string dir = "LRUD";         
int main(){             
	int N, M; cin>>N>>M;
 	vector<pair<int, int>> monsters; 
	pair<int, int> player, out = {-1, -1}; 
	vector<vector<char>> grid(N, vector<char>(M)); 
	queue<vector<int>> q;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			char c; cin>>c; 
			grid[i][j] = c; 
			if(c == 'A'){
				player = make_pair(i, j);
		    }
			else if(c == 'M'){
				monsters.emplace_back(i, j);
			}  
		}	
	}
	for(auto m : monsters)
		q.push({m.first, m.second, 2}); 
		// 2 for monster 1 for player 
	q.push({player.first, player.second, 1}); 
	while(!q.empty()){
		vector<int> top = q.front(); 
		q.pop();
		int x = top[0], y = top[1]; 
		if(top[2] == 1){
		    for(int i = 0; i < 4; i++){
 
				int newx = x + dx[i], newy = y + dy[i]; 
				if(0 <= newx && newx < N && 0 <= newy && newy < M && grid[newx][newy] == '.'){
					grid[newx][newy] = dir[i];
					q.push({newx, newy, 1}); 
				}
				else if(newx < 0 || newx >= N || newy < 0 || newy >= M){
					out = make_pair(x, y);
 
					break; 
				}	
			}
		}
		else{
			for(int i = 0; i < 4; i++){
				int newx = x + dx[i], newy = y + dy[i]; 
				if(0 <= newx && newx < N && 0 <= newy && newy < M && grid[newx][newy] == '.'){
					grid[newx][newy] = 'M';
					q.push({newx, newy, 2}); 
				}	
			}
		}
	}
	if(out == make_pair(-1, -1)){
		cout<<"NO\n"; 
		return 0; 
	}
	 /*
	 for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(!grid[i][j]) cout<<'.'; 
			else cout<<grid[i][j];
		}
		cout<<'\n';
	}
	*/         	
	cout<<"YES\n";
 
	int x = out.first, y = out.second; 
	vector<char> ans; 
	while(grid[x][y] != 'A'){
		ans.push_back(grid[x][y]);
		if(grid[x][y] == 'U'){
			x++;
		}
		else if(grid[x][y] == 'D'){
			x--;
		}
		else if(grid[x][y] == 'L'){
			y++;
			 
		}
		else if(grid[x][y] == 'R'){
			y--;
		}
 
 
	}
	cout<<ans.size()<<'\n';
	for(int i = ans.size() - 1; i >= 0; i--){
		cout<<ans[i];
	}	                   
}
