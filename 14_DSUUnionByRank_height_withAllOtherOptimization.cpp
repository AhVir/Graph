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
    else return par[i] = findSet(par[i], par);  //findSet with path compression
  }

  void unionSet(int x, int y, int* par, int* rank){
    int p1 = findSet(x, par);
    int p2 = findSet(y, par);

    if(p1 != p2){
      // implementing union by rank based on set height
      if(rank[p1]>rank[p2]) par[p2] = p1;
      else if(rank[p2]>rank[p1]) par[p1] = p2;
      else if(rank[p1] == rank[p2]){
        par[p2] = p1;
        rank[p1]++;
      }
    }
  }


  //cycle check
  
  bool containsCycle(){
    int* par = new int[v];
    int* rank = new int[v];

    for(int i=0; i<v; i++) par[i] = i, rank[i] = 0;

    for(auto edge:edges){
      int node1 = edge.first;
      int node2 = edge.second;

      int p1 = findSet(node1, par);
      int p2 = findSet(node2, par);

      if(p1 == p2) return true;
      else unionSet(p1, p2, par, rank);
    }

    //deleting dynamic array
    delete []par; 
    delete []rank;

    return false;
  }
};

int main(){
  Graph g(7);
  
  g.addEdges(0, 1);
  g.addEdges(1, 2);
  g.addEdges(2, 3);
  g.addEdges(0, 4);
  g.addEdges(5, 6);
  g.addEdges(2, 5);
  //g.addEdges(2, 6);

  cout << "Contains cycle: " << g.containsCycle() << endl;

  return 0;
}
