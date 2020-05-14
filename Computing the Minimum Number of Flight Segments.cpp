/*Task - Given an undirected graph with 𝑛 vertices and 𝑚 edges and two vertices 𝑢 and 𝑣, compute the length
of a shortest path between 𝑢 and 𝑣 (that is, the minimum number of edges in a path from 𝑢 to 𝑣).
Input Format - A graph is given in the standard format. The next line contains two vertices 𝑢 and 𝑣.
Constraints - 2 ≤ 𝑛 ≤ 105, 0 ≤ 𝑚 ≤ 105, 𝑢 ̸= 𝑣, 1 ≤ 𝑢, 𝑣 ≤ 𝑛.
Output Format - Output the minimum number of edges in a path from 𝑢 to 𝑣, or −1 if there is no path.*/

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;


int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  if (s == t) {
	return 0;
  }
  
  vector<int> dist(adj.size(), -1);  
  dist[s] = 0;
  
  
  queue<int> queue;
  
  
  queue.push(s);
  
  while(!queue.empty()) {
	
    int u = queue.front();
	queue.pop();
	
    for(int i=0; i < adj[u].size(); ++i) {
      int v = adj[u][i];
	  if(dist[v] == -1) {
		queue.push(v);
		dist[v] = dist[u] + 1;
	  }
	}
  }
  return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}