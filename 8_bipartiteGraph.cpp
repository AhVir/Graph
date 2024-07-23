#include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  list<int>* edges;

public:
  Graph(int v){
    this->v = v;
    edges = new list<int>[v];
  }

  void addEdges(int x, int y, bool isDirec=true){
    edges[x].push_back(y);
    if(isDirec) edges[y].push_back(x);
  }


  //printing the graph
  void printGraph(){
    for(int i=0; i<v; i++){
      cout << i << " -> ";
      for(int X:edges[i]) cout << X << " -> ";
      cout << endl;
    }
  }


  bool isBipartite(){
    int source = 0;
    queue<int> que;
    vector<int> vis(v, 0);
    vector<int> color(v, -1);

    que.push(source);
    vis[source] = 1;
    color[source] = 0;

    while(!que.empty()){
      int parent = que.front();
      que.pop();

      for(int X:edges[parent]){
        if(!vis[X]){
          if(color[parent] == 1) color[X] = 0;
          else color[X] = 1;
          vis[X] = 1;
          que.push(X);
        }
        if(vis[X] && color[X] == color[parent]){
          return false;
        }
      }
    }

    return true;
  }
};

int main(){
  Graph g(6);

  g.addEdges(0, 1);
  g.addEdges(0, 2);
  g.addEdges(1, 3);
  g.addEdges(1, 4);
  g.addEdges(2, 5);
  g.addEdges(4, 5);

  g.printGraph();

  cout << "is Bipartite: " << g.isBipartite() << endl;

  return 0;
}
