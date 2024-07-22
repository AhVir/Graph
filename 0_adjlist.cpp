#include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  //using doubly linkedList for edges
  list<int>* edges;
  
public:
  Graph(int v){
    this->v = v;
    edges = new list<int>[v];
  }

  void addEdge(int x, int y, bool direc=false){
    edges[x].push_back(y);

    if(direc) edges[y].push_back(x);
  }


  void printGraph(){
    for(int i=0; i<v; i++){
      cout << i << " -> ";
      for(auto e:edges[i]) cout << e << " -> ";
      cout << endl;
    }
  }
};

int main(){
  Graph graph(6);

  //adding edges
  graph.addEdge(0, 1, true);
  graph.addEdge(0, 4, true);
  graph.addEdge(2, 1, true);
  graph.addEdge(3, 4, true);
  graph.addEdge(4, 5, true);
  graph.addEdge(2, 3, true);
  graph.addEdge(3, 5, true);

  graph.printGraph();

  return 0;
}
