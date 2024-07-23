#include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  vector<pair<int, pair<int, int>>> edgeslist;

public:
  Graph(int v){
    this->v = v;
  }

  void addEdge(int wt, pair<int, int> nodes){
    edgeslist.push_back({wt, nodes});
  }


  //Bellman Ford Algorithm
  void bellmanFord(int src){
    int* distance = new int[v];
    for(int i=0; i<v; i++) distance[i] = INT_MAX;

    distance[src] = 0;

    for(int i=1; i<=v; i++){
      for(auto X:edgeslist){
        int curWT = X.first;
        int fromNode = X.second.first;
        int toNode = X.second.second;

        if(distance[fromNode] != INT_MAX && distance[toNode] > curWT + distance[fromNode]){
          // negative cycle checking condition
          if(i==v){  // that means distance is still reducing at the Vth iteration
            cout << "ERROR: Graph contains negative cycle!!" << endl;
            cout << "Applying BellmanFord doesn't make any sense;" << endl;
            return;
          }
          distance[toNode] = curWT + distance[fromNode];
        }
      }
    }

    cout << "Distance array: " << endl;
    for(int i=0; i<v; i++){
      cout << i << ": " << distance[i] << endl;
    }

    delete []distance;
  }
};

int main(){
  Graph g(3);

  g.addEdge(3, {0, 1});
  g.addEdge(4, {1, 2});
  g.addEdge(-10, {0, 2});

  g.bellmanFord(0);

  return 0;
}
