#include <iostream>
#include <vector>
#include <functional>
using std::vector;
using std::pair;

int reach(vector<vector<int> > &adj, int x, int y) {
  //write your code here
  vector<bool> visited(adj.size(),false);
  std::function<int(int)> dfs=[&](int i){
    if (i==y) return 1;
    for (int w: adj[i]){
      if (visited[w]==false){
        visited[w]=true;
        if(dfs(w)==1) return 1;
      }
    }
    return 0;
  };
  return dfs(x);
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
