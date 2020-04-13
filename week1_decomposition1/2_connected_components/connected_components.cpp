#include <iostream>
#include <vector>
#include <functional>

using std::vector;
using std::pair;

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  vector<bool> visited(adj.size(),false);

  std::function<void(int)> dfs = [&](int i){
    for(int w: adj[i]){
      if (visited[w]==false){
        visited[w] = true;
        dfs(w);
      }
    }
  };
  for (int i=0;i<adj.size();++i){
    if(visited[i]==false){
      visited[i] = true;
      dfs(i);
      res += 1;
    }
  }
  return res;
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
  std::cout << number_of_components(adj);
}
