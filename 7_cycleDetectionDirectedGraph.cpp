#include<bits/stdc++.h>
#include <csignal>
using namespace std;

class Graph{
  int v;
  list<int>* edges;

public:
  Graph(int v){
    this->v = v;
    edges = new list<int>[v];
  }

  //adding edges
  void addEdges(int x, int y, bool isDirec=true){
    edges[x].push_back(y);
    if(isDirec) edges[y].push_back(x);
  }


  //printing the Graph:
  void printGraph(){
    for(int i=0; i<v; i++){
      cout << i << " -> ";
      for(int x:edges[i]) cout << x << " -> ";
      cout << endl;
    }
  }

  //contains cycle
  bool dfsRecursive(vector<int>& vis, vector<int>& st, int src){
    vis[src] = 1;
    st[src] = 1;
    
    for(int X:edges[src]){
      if(!vis[X]){
        return dfsRecursive(vis, st, X);
      }
      else if(vis[X] && st[X]){
        return true;
      }
    }
    st[src] = 0;
    return false;
  } 


  bool containsCycle(){
    int src = 0;
    vector<int> vis(v, 0);
    vector<int> st(v, 0);

    //if the graph has multiple connected components
    for(int i=0; i<v; i++){
      if(!vis[i]){
        return dfsRecursive(vis, st, src);
      }
    }

    return false;
  }
};

int main(){
  Graph g(6);

  g.addEdges(0, 1, false);
  g.addEdges(1, 2, false);
  g.addEdges(2, 3, false);
  g.addEdges(3, 0, false);
  g.addEdges(0, 4, false);
  g.addEdges(0, 5, false);
  g.addEdges(5, 4, false);

  g.printGraph();

  cout << "contains cycle: " << g.containsCycle() << endl;

  return 0;
}
