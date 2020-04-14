#include <iostream>
#include <vector>
#include <functional>

using std::vector;
using std::pair;

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  int n = adj.size();
  vector<bool> pre_visited(n,false); 
  vector<bool> post_visited(n,false);

  std::function<int(int)> dfs = [&](int v){
    pre_visited[v] = true;
    for(int w: adj[v])
      if (pre_visited[w] && !post_visited[w])
        return 1;
      else if (dfs(w)==1) return 1;
    post_visited[v] = true;
    return 0;
  };

  for (int i=0;i<n;++i)
    if(pre_visited[i]==false){
      if (dfs(i)==1) return 1;
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
