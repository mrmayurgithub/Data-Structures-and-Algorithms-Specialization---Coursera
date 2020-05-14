/*Task - Check whether a given directed graph with 𝑛 vertices and 𝑚 edges contains a cycle.
Input Format - A graph is given in the standard format.
Constraints - 1 ≤ 𝑛 ≤ 103, 0 ≤ 𝑚 ≤ 103.
Output Format - Output 1 if the graph contains a cycle and 0 otherwise.*/

#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int dfs(vector<vector<int> > &adj, int x, vector<int> &visited, vector<int> &recStack) {
  
  visited[x] = 1;
  recStack[x] = 1;
  
  for (int i = 0; i < adj[x].size(); i++) {
    if (!visited[adj[x][i]] && dfs(adj, adj[x][i], visited, recStack))
	  return 1;
	else if(recStack[adj[x][i]])
	  return 1;
  }
  recStack[x] = 0; 
  return 0;
}

int acyclic(vector<vector<int> > &adj) {
 
  vector<int> visited(adj.size());
  vector<int> recStack(adj.size());
  for (int i = 0; i < adj.size(); i++)
  {
    if (!visited[i]) {
      if (dfs(adj, i, visited, recStack)) 
        return 1;
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}