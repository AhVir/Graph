#include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  list<pair<int, int>> edgeList;

public:
  Graph(int v){
    this->v = v;
  }

  void addEdges(int x, int y){
    edgeList.push_back({x, y});
  }

  //implementing DSU functions
  //find set
  int findSet(int x, vector<int>& parents){
    if(parents[x] == x) return x;

    return findSet(parents[x], parents);
  }

  //union set
  void union_set(int x, int y, vector<int>& parents){
    int p1 = findSet(x, parents);
    int p2 = findSet(y, parents);

    if(p1 != p2) parents[p1] = p2;
  }


  bool containsCycle(){
    vector<int> par(v, -1);
    for(int i=0; i<v; i++) par[i] = i;
    
    for(auto X:edgeList){
      int n1 = X.first, n2 = X.second;
      int p1 = findSet(n1, par);
      int p2 = findSet(n2, par);

      if(p1 != p2) union_set(p1, p2, par);
      else{
        return true;
      }
    }

    return false;
  }
};

int main(){
  Graph g(4);

  g.addEdges(0, 1);
  g.addEdges(1, 2);
  g.addEdges(2, 3);
  //g.addEdges(3, 0);

  cout << "Contains cycle: " << g.containsCycle() << endl;

  return 0;
}
