/*Problem Description
Task - Given an directed graph with positive edge weights and with 𝑛 vertices and 𝑚 edges as well as two
vertices 𝑢 and 𝑣, compute the weight of a shortest path between 𝑢 and 𝑣 (that is, the minimum total
weight of a path from 𝑢 to 𝑣).
Input Format - A graph is given in the standard format. The next line contains two vertices 𝑢 and 𝑣.
Constraints - 1 ≤ 𝑛 ≤ 104, 0 ≤ 𝑚 ≤ 105, 𝑢 ̸= 𝑣, 1 ≤ 𝑢, 𝑣 ≤ 𝑛, edge weights are non-negative integers not
exceeding 103.
Output Format - Output the minimum weight of a path from 𝑢 to 𝑣, or −1 if there is no path.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::numeric_limits;

const int inf = numeric_limits<int>::max();

struct Node {
  int index, distance;
  Node(int a = 0, int b = 0): index(a), distance(b) {}
};

struct cmp {
	bool operator()(Node a, Node b){
		return a.distance > b.distance;
	}
};

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  
  vector<int> dist(adj.size(), inf);
  dist[s] = 0;
  priority_queue<Node, vector<Node>, cmp> pq;
  pq.push(Node(s, dist[s]));
  while(!pq.empty()) {
	Node u = pq.top();
	pq.pop();
	int u_index = u.index;
    for (int i = 0; i < adj[u_index].size(); i++) {
	  int v = adj[u_index][i];
	  if(dist[v] > dist[u_index] + cost[u_index][i]) {
	    dist[v] = dist[u_index] + cost[u_index][i];
        pq.push(Node(v, dist[v])); 
	  }
	}	
  }
  if(dist[t] == inf)
    return -1;
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}