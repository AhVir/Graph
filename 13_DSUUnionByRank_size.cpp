#include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  list<pair<int, int>> edges;

public:
  Graph(int v){
    this->v = v;
  }

  void addEdges(int x, int y){
    edges.push_back({x, y});
  }


  //DSU
  int findSet(int i, int* par){
    if(par[i] == i) return i;
    else return par[i] = findSet(par[i], par);
  }

  void unionSet(int i, int j, int* par, int* rank){
    int p1 = findSet(i, par);
    int p2 = findSet(j, par);

    if(p1 != p2){   //union by rank implemented
      if(rank[p1] > rank[p2]) par[p2] = p1, rank[p1] += rank[p2];
      else par[p1] = p2, rank[p2] += rank[p1];
    } 
  }


  bool containsCycle(){
    int* par = new int[v];
    int* rank = new int[v];

    for(int i=0; i<v; i++) par[i] = i, rank[i] = 1;

    for(auto e:edges){
      int e1 = e.first;
      int e2 = e.second;

      int p1 = findSet(e1, par);
      int p2 = findSet(e2, par);

      if(p1 == p2) return true;
      else unionSet(p1, p2, par, rank);
    }

    delete []par;
    delete []rank;
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
