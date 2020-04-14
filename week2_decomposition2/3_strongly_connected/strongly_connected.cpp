#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

using std::vector;
using std::pair;


int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  int n = adj.size();
  vector<vector<int> > adj_r(n,vector<int>());
  vector<bool> used(n,false);
  vector<int> order(n);
  auto reverse_graph = [&](){
    for(int i=0;i<n;++i)
      for(int j: adj[i]) adj_r[j].push_back(i);
  };
  reverse_graph();

  std::function<void(int,bool,vector<vector<int> >&)> dfs=[&](int v,bool sort,vector<vector<int> >& G){
    used[v] = true;
    for(int w: G[v])
      if (used[w]==false) dfs(w,sort,G);
    if (sort) order.push_back(v);
  };
// toposort in reversed graph
  for(int i=0;i<n;++i)
    if(used[i]==false) dfs(i,true,adj_r);
  std::reverse(order.begin(),order.end());
// count ssc
  used.assign(n,false);
  for(int i:order)
    if(used[i]==false){
      dfs(i,false,adj);
      ++result;
    }

  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
