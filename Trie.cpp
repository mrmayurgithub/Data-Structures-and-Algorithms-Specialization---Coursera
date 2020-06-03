/*Problem Description
Task - Construct a trie from a collection of patterns.
Input Format - An integer 𝑛 and a collection of strings Patterns = {𝑝1, . . . , 𝑝𝑛} (each string is given on aseparate line).
Constraints - 1 ≤ 𝑛 ≤ 100; 1 ≤ |𝑝𝑖| ≤ 100 for all 1 ≤ 𝑖 ≤ 𝑛; 𝑝𝑖’s contain only symbols A, C, G, T; no 𝑝𝑖 is a prefix of 𝑝𝑗 for all 1 ≤ 𝑖 ̸= 𝑗 ≤ 𝑛.3
Output Format - The adjacency list corresponding to Trie(Patterns), in the following format. If 
Trie(Patterns) has 𝑛 nodes, first label the root with 0 and then label the remaining nodes with the
integers 1 through 𝑛−1 in any order you like. Each edge of the adjacency list of Trie(Patterns) will be
encoded by a triple: the first two members of the triple must be the integers 𝑖, 𝑗 labeling the initial and
terminal nodes of the edge, respectively; the third member of the triple must be the symbol 𝑐 labeling
the edge; output each such triple in the format u->v:c (with no spaces) on a separate line.*/


#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;
typedef map<char, int> edges;
typedef vector<edges> trie;

trie build_trie(vector<string> & patterns) {
  trie t;

  for (int i = 0; i < patterns.size(); i++) {
    int x = 0;
    for (int j = 0; j < patterns[i].size(); j++) {
      bool match_found = false;
      if (x < t.size()) {
        for (const auto & k : t[x]) {
          if (k.first == patterns[i][j]) {
            x = k.second;
            match_found = true;
            break;
          }
        }
        if (!match_found) {
          t[x].insert(pair<char, int> (patterns[i][j], t.size()));
          x = t.size();
        }
      } else {
        map<char, int> m;
        m.insert(pair<char, int> (patterns[i][j], t.size() + 1));
        t.push_back(m);
        x = t.size();
      }
    }
    map<char, int> m;
    m.insert(pair<char, int> ('$', -1));
    t.push_back(m);
  }
  return t;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      if (j.first != '$') {
        std::cout << i << "->" << j.second << ":" << j.first << "\n";
      }
    }
  }

  return 0;
}