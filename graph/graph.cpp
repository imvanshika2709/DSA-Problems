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
void dfsutil(int node, vector<int> adj[], int vis[], vector<int>& ls){
	vis[node]=1;
	ls.push_back(node);

	for(auto it: adj[node])
	{
		if(!vis[it]){
			dfsutil(it,adj,vis, ls);
		}
	}
}
vector<int> dfs(int V, vector<int> adj[]){

	int vis[V]={0};
	vector<int> ls;
	
	int start=0;

	dfsutil(start, adj, vis, ls);
	return ls;	
}
void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
// Bellman ford--> negative cycle detect
// Flyod- warshall multi-source shortest path algorithm
// kruskal --> MST

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int PrimsAlgoMST(int V, vector<vector<int>> adj[]){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	int Vis[V]={0};
	pq.push({0,0});
	int sum=0;

	while(!pq.empty()){
		auto it=pq.top();
		int node=it.second;
		int wt=it.first;

		pq.pop();

		if(Vis[node]==1) continue;
		Vis[node]=1;

		sum+=wt;

		for(auto it: adj[node]){
			int adjnode=it[0];
			int edwt=it[1];

			pq.push({edwt, adjnode});

		}
	}
	return sum;

}
bool DetectCycleinDirected(int V,vector<int> adj[]){
	queue<int> q;
	vector<int> indegree(V, 0);
	vector<int> topo;

	for(int i=0; i<V; i++){
		for(auto it: adj[i]){
			indegree[it]++;
		}

	}

	for(int i=0; i<V; i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int node=q.front();
		q.pop();

		topo.push_back(node);
		for(auto it: adj[node]){
			indegree[it]--;
			if(indegree[it]==0){
				q.push(it);
			}
		}
	}
	if(topo.size()!=V) return true;
	return false;
}

bool CourseSchedule_util(vector<vector<int>>& adj) {
    int V = adj.size();
    queue<int> q;
    vector<int> indegree(V, 0);
    vector<int> topo;

    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    return topo.size() != V;  // true if cycle
}

bool CourseSchedule(int n, vector<vector<int>> &prerequisites) {
	vector<vector<int>> adj(n);
    
    for (auto& pre : prerequisites) {
        int a = pre[0], b = pre[1];
        adj[b].push_back(a);
    }

    return !CourseSchedule_util(adj);
}
bool BipartiteGraph_util(int start, vector<int> adj[], int color[]){
	
	queue<int> q;
	q.push(start);

	while(!q.empty()){
		int node=q.front();
		q.pop();

		for(auto it: adj[node]){
			if(color[it]==-1){
				color[it]=!color[node];
				q.push(it);
			}

			else if(color[it]==color[node]) return false;

		}
	}
	return true;
}

bool BipartiteGraph(int V,vector<int> adj[]){
	int color[V];
	for(int i=0; i<V; i++){
		color[i]=-1;
	}

	for(int i=0; i<V; i++){
		if(color[i]==-1){
			if(BipartiteGraph_util(i,adj, color)==false){
				return false;
			}
		}
	}
	return true;
}
// 1-2-3-4
// 1-2-3-4-5-6-7

int main() 
{
	vector<int>adj[5];
	
	addEdge(adj, 0, 1);
   	addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

	bool ans = BipartiteGraph(5, adj); 
	cout<<ans;

    return 0;
}