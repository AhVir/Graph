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


  void addEdge(int x, int y, bool isDirec=true){
    edges[x].push_back(y);

    if(isDirec) edges[y].push_back(x);
  }

  void printGraph(){
    for(int i=0; i<v; i++){
      cout << i << " -> ";
      
      for(int X:edges[i]) cout << X << " -> ";
      cout << endl;
    }
  }


  void bfs(int src){
    vector<int> visited(v, 0);
    queue<int> que;

    //bfs starts from here
    cout << "BFS: ";

    que.push(src);
    visited[src] = 1;

    while(!que.empty()){
      int node = que.front();
      que.pop();

      //printing the node
      cout << node << " -> ";

      for(int X:edges[node]){
        if(!visited[X]) que.push(X), visited[X] = 1;
      }
    }
    cout << endl;
  }
};

int main(){
  Graph g(7);

  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.addEdge(3, 5);
  g.addEdge(5, 6);
  g.addEdge(4, 5);
  g.addEdge(0, 4);
  g.addEdge(3, 4);

  g.printGraph();
  g.bfs(1);

  return 0;
}
