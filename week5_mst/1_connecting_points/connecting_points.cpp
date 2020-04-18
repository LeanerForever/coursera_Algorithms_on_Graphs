#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;
using std::sort;

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  int n = x.size();
  vector<int> disjoint_set(n,-1);
  vector<int> rank(n,0);
  vector<pair<double,pair<int,int>>> adj;

  auto distance = [&](int i, int j){
    return sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
  };

  auto edges = [&](){
    for(int i=0;i<n;++i){
      for(int j=i+1;j<n;++j)
        adj.push_back({distance(i,j),{i,j}});
    }
  };

  auto ds_find = [&](int x){
    while(disjoint_set[x]!=-1){
      x = disjoint_set[x];
    }
    return x;
  };

  auto ds_union = [&](int x,int y){
    int px = ds_find(x);
    int py = ds_find(y);
    if(px<py){
      disjoint_set[px] = py;
      rank[py] += rank[px];
    }
    else{
      disjoint_set[py] = px;
      rank[px] += rank[py];
    }
  };

  edges();
  sort(adj.begin(),adj.end());
  for(auto seg : adj){
    double d = seg.first; int i = seg.second.first; int j = seg.second.second;
    if(ds_find(i)!=ds_find(j)){
      result += d;
      ds_union(i,j);
    }
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
