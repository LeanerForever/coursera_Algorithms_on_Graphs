#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
  //write your code here
  // reachable nodes from s
  int n = 1 ;
  reachable[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()){
    int v = q.front(); q.pop();
    for(int w : adj[v]) 
      if(reachable[w]==0) {reachable[w]=1; ++n; q.push(w);}
  }
  distance[s] = 0;
  queue<int> cycle;
  for (int k=0;k<n;++k){
    for(int i=0;i<adj.size();++i){     
      if (reachable[i]==1)
        for (int j=0;j<adj[i].size();++j)
           distance[adj[i][j]] = std::min(distance[adj[i][j]],distance[i]+cost[i][j]);
    }
  }
  
  for (int i=0;i<adj.size();++i){
    if (reachable[i]==1)
      for(int j=0;j<adj[i].size();++j)
        if(distance[adj[i][j]]>distance[i]+cost[i][j]) {cycle.push(adj[i][j]); shortest[adj[i][j]]=0;};
  }

  while(!cycle.empty()){
    int w=cycle.front(); cycle.pop();
    for(int x:adj[w])  
      if(shortest[x]==1) {shortest[x]=0; cycle.push(x);}
  }

}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  vector<long long> distance(n, std::numeric_limits<int>::max());
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
