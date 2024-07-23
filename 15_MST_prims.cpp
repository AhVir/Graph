#include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  vector<pair<int, int>>* edges;

public:
  Graph(int v){
    this->v = v;
    edges = new vector<pair<int, int>>[v];
  }


  void addEdges(int x, int y, int wt){
    edges[x].push_back({y, wt});
    edges[y].push_back({x, wt});
  }


  //implementing mst
  int MST_Prims(){
    int cost = 0;
    int* vis = new int[v]{0};
    vector<pair<int, int>> MSTEdges;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQue;

    pair<int, int> src = {0, 0};  //wt, node
    
    pQue.push(src);

    while(!pQue.empty()){
      auto minEdge = pQue.top();
      int minEdgeWT = minEdge.first;
      int minEdgeNode = minEdge.second;
      pQue.pop();

      if(!vis[minEdgeNode]){
        cost += minEdgeWT;
        MSTEdges.push_back({minEdgeNode, minEdgeWT});
        vis[minEdgeNode] = 1;

        for(auto X:edges[minEdgeNode]){
          if(!vis[X.first]){
            pQue.push({X.second, X.first});
          }
        }
      }
    }

    cout << "Printing the MST Edges: " << endl;
    for(auto x:MSTEdges){
      cout << x.first << ", " << x.second << endl;
    }

    delete []vis;
    return cost;
  }
};

int main(){
  Graph g(4);

  g.addEdges(0, 1, 1);
  g.addEdges(0, 2, 2);
  g.addEdges(1, 3, 2);
  g.addEdges(1, 2, 2);
  g.addEdges(2, 3, 3);
  g.addEdges(0, 3, 2);

  cout << "MST Cost: " << endl << g.MST_Prims() << endl;

  return 0;
}
