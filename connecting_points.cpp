/*Task - Given 𝑛 points on a plane, connect them with segments of minimum total length such that there is a
path between any two points. Recall that the length of a segment with endpoints (𝑥1, 𝑦1) and (𝑥2, 𝑦2)
is equal to √︀(𝑥1 − 𝑥2)2 + (𝑦1 − 𝑦2)2.
Input Format - The first line contains the number 𝑛 of points. Each of the following 𝑛 lines defines a point
(𝑥𝑖, 𝑦𝑖).
Constraints - 1 ≤ 𝑛 ≤ 200; −103 ≤ 𝑥𝑖, 𝑦𝑖 ≤ 103 are integers. All points are pairwise different, no three
points lie on the same line.
Output Format - Output the minimum total length of segments. The absolute value of the difference
between the answer of your program and the optimal value should be at most 10−6. To ensure this,
output your answer with at least seven digits after the decimal point (otherwise your answer, while
being computed correctly, can turn out to be wrong because of rounding issues).*/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

struct node {
  int parent;
  int rank;
  int x;
  int y;
	
  node(int a, int b, int c = -1, int d = 0) {
    x = a;
    y = b;
    parent = c;
    rank = d;
  }
};

struct edge {
  int u;
  int v;
  double weight;
  
  edge(int a, int b, double c) {
    u = a;
    v = b;
    weight = c;
  }
};

bool cmp(edge a, edge b) {
  return a.weight < b.weight;
}

void make_set(int i, vector<node> &nodes, vector<int> &x, vector<int> &y) {
  nodes.push_back(node(x[i], y[i], i));
}

double weight(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int Find(int i, vector<node> &nodes) {
  if (i != nodes[i].parent) {
    nodes[i].parent = Find(nodes[i].parent, nodes);
  }
  return nodes[i].parent;
}

void Union(int u, int v, vector<node> &nodes) {
  int r1 = Find(u, nodes);
  int r2 = Find(v, nodes);
  if (r1 != r2) {
    if (nodes[r1].rank > nodes[r2].rank) {
      nodes[r2].parent = r1;
    } else {
      nodes[r1].parent = r2;
      if (nodes[r1].rank == nodes[r2].rank) {
        nodes[r2].rank++;
      }
    }
  }
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
 
  int n = x.size();
  vector<node> nodes;
  for (int i = 0; i < n; i++) {
	make_set(i, nodes, x, y);
  }
  vector<edge> edges;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      edges.push_back(edge(i, j, weight(x[i], y[i], x[j], y[j])));
    }
  }
  std::sort(edges.begin(), edges.end(), cmp);
  for (int i = 0; i < edges.size(); i++) {
    edge current_edge = edges[i];
    int u = current_edge.u;
    int v = current_edge.v;
    if (Find(u, nodes) != Find(v, nodes)) {
      result += current_edge.weight;
      Union(u, v, nodes);
    }
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}