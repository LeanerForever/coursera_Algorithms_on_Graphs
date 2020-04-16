#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) {
  //write your code here
  queue<int> q;
  q.push(0);
  vector<int> colored(adj.size(),-1);
  colored[0]=0;
  while(!q.empty()){
    int v = q.front(); q.pop();
    for(int w: adj[v]){
      if(colored[w]==-1) {colored[w]=1-colored[v];q.push(w);}
      else if(colored[w]==colored[v]) return 0;
    }
  }
  return 1;
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
  std::cout << bipartite(adj);
}
