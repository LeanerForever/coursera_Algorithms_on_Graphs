#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  priority_queue<pair<int,int>,vector<pair<int,int> >,std::greater<pair<int,int> > > pq;
  pq.push({0,s});
  vector<bool> used(adj.size(),false);
  while (!pq.empty()){
    auto v = pq.top();
    if (v.second==t) return v.first;
    pq.pop();
    used[v.second] = true;
    for(int i=0;i<adj[v.second].size();++i)
      if(!used[adj[v.second][i]])
        pq.push({v.first+cost[v.second][i],adj[v.second][i]});
  }
  return -1;
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
