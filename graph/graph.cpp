#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
	dist[S] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (auto it : edges) {
            int u = it[0];
    		int v = it[1];
            int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
    }    
		// Nth relaxation to check negative cycle
	for (auto it : edges) {
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
			return { -1};
		}
	}
    return dist;
}




bool isValid(int x, int y, vector<vector<int>>& surface){
	int n=surface.size();
	int m=surface[0].size();
	
	return (x>=0 && x<n && y>=0 && y<m);
}
void dfs(int x, int y, vector<vector<int>>& surface, vector<vector<bool>>& visited) {
	visited[x][y] = true;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	
	for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
		
		if (isValid(nx, ny, surface) && !visited[nx][ny] && surface[nx][ny] == 1){
            dfs(nx, ny, surface, visited);
		}
	}
}

int getNumberOfIslands(vector<vector<int>> &surface) {
	
	int n=surface.size();
	int m=surface[0].size();
	vector<vector<bool>> visited(n, vector<bool>(m, false));

	
	int count=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!visited[i][j] && surface[i][j]==1){
				dfs(i, j, surface, visited);
				count++;
			}
		}
	}
	return count;
	
}
// Bellman ford--> negative cycle detect
// Flyod- warshall multi-source shortest path algorithm
// kruskal --> MST

int main() {
    
    return 0;
}