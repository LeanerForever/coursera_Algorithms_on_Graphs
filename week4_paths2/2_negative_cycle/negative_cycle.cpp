#include <iostream>
#include <vector>

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  //write your code here
  int n=adj.size();
  vector<int> dists(n,10000000);
  dists[0] = 0;
  int cycle=0;
  for(int k=0;k<n+1;++k){
    cycle = 0;
    for(int i=0;i<n;++i)
      for(int j=0;j<adj[i].size();++j)
        if(dists[adj[i][j]] > dists[i]+cost[i][j]) { dists[adj[i][j]] = dists[i]+cost[i][j]; cycle=1;}
    if(cycle==0) return 0;
  }
  return cycle;
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
  std::cout << negative_cycle(adj, cost);
}
