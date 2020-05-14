/*Task - Given an undirected graph and two distinct vertices 𝑢 and 𝑣, check if there is a path between 𝑢 and 𝑣.
Input Format - An undirected graph with 𝑛 vertices and 𝑚 edges. The next line contains two vertices 𝑢
and 𝑣 of the graph.
Constraints - 2 ≤ 𝑛 ≤ 103; 1 ≤ 𝑚 ≤ 103; 1 ≤ 𝑢, 𝑣 ≤ 𝑛; 𝑢 ̸= 𝑣.
Output Format - Output 1 if there is a path between 𝑢 and 𝑣 and 0 otherwise.*/

#include <iostream>
#include <vector>

using namespace std;

int explore(vector<vector<int> > &adj, int x, int y, vector<int> &visited) {
	if (x == y) {
		return 1;
	}	
	visited[x] = 1;
	
	
	for(int i = 0; i < adj[x].size(); i++) {
	   
	    if (!visited[adj[x][i]]) {
			if(explore(adj, adj[x][i], y, visited)) {
				return 1;
			}
		}
	}
	return 0;
}


int reach(vector<vector<int> > &adj, int x, int y) {
  
  vector<int> visited(adj.size());
  return explore(adj, x, y, visited);
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
	// adjacency list
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
 std::cout << reach(adj, x - 1, y - 1);
}