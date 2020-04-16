#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  queue<int> q;
  q.push(s);
  vector<int> dists(adj.size(),-1);
  dists[s]=0;
  while(!q.empty()){
    int v = q.front(); q.pop();
    for (int w: adj[v]){
      if(dists[w]==-1) {dists[w]=dists[v]+1;q.push(w);} 
      if(w==t) return dists[w];  
    }
  }
  return dists[t];
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
