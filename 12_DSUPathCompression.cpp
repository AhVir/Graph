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
  int findSet(int x, int* parent){
    if(parent[x] == x) return x;

    else return parent[x] = findSet(parent[x], parent);  //path compression added
  }

  void unionSet(int x, int y, int* parent){
    int p1 = findSet(x, parent);
    int p2 = findSet(y, parent);

    if(p1 != p2){
      parent[p1] = p2;
    }
  }


  //cycle check function
  bool containsCycle(){
    int *parent = new int[v];
    for(int i=0; i<v; i++) parent[i] = i;

    for(auto e:edges){
      int n1 = e.first;
      int n2 = e.second;

      int p1 = findSet(n1, parent);
      int p2 = findSet(n2, parent);

      if(p1 == p2) return true;
      else unionSet(p1, p2, parent);
    }

    delete []parent;
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
