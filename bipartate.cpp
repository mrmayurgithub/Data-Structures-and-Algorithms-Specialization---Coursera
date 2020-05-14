/*Task - Given an undirected graph with 𝑛 vertices and 𝑚 edges, check whether it is bipartite.
Input Format - A graph is given in the standard format.
Constraints - 1 ≤ 𝑛 ≤ 105, 0 ≤ 𝑚 ≤ 105.
Output Format - Output 1 if the graph is bipartite and 0 otherwise.*/

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  
  vector<int> color(adj.size(), -1);
  
 
  color[0] = 1;
  
  
  queue<int> queue;
  queue.push(0);
  
  
  while(!queue.empty()) {
	
    int u = queue.front();
	queue.pop();
	   
   
    for(int i=0; i < adj[u].size(); ++i) {
      int v = adj[u][i];
     
      if (color[v] == color[u])
        return 0;
        
	
      else if (color[v] == -1) {
       
        color[v] = 1- color[u];
		queue.push(v);
	  }
	}
  }
  
 
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}