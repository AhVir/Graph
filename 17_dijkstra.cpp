#include<bits/stdc++.h>
#include <queue>
using namespace std;

class Graph{
  int v;
  vector<pair<int, int>>* edges;

public:
  Graph(int v){
    this->v = v;
    edges = new vector<pair<int, int>>[v];
  }

  void addEdge(int x, int y, int wt){
    edges[x].push_back({y, wt});
    edges[y].push_back({x, wt});
  }

  void dijkstra(int src, int destination){
    int* distance = new int[v];
    for(int i=0; i<v; i++) distance[i] = INT_MAX;
    set<pair<int, int>> st;
    
    st.insert({0, src});
    distance[src] = 0;

    while(!st.empty()){
      auto it = st.begin();
      int node = it->second;
      int wt = it->first;
      st.erase(it);

      for(auto X:edges[node]){
        int newNode = X.first;
        int newNodeWT = X.second;
        if(wt + newNodeWT < distance[newNode]){
          //if this node already exists in the set
          auto temp = st.find({distance[newNode], newNode});
          if(temp != st.end()){
            st.erase(temp);
          }
          
          //updating the wt & inserting it into the set
          distance[newNode] = wt + newNodeWT;
          st.insert({wt+newNodeWT, newNode});
        }
      }
    }

    cout << "Shortest Dist from " << src << " to " << destination << " is: " << distance[destination] << endl;

    cout << "Distance array: " << endl;
    for(int i=0; i<v; i++){
      cout << i << ": " << distance[i] << endl;
    }
  }
};

int main(){
  Graph g(5);

  g.addEdge(0, 1, 1);
  g.addEdge(1, 2, 1);
  g.addEdge(0, 2, 4);
  g.addEdge(0, 3, 7);
  g.addEdge(3, 2, 2);
  g.addEdge(3, 4, 3);

  g.dijkstra(0, 4);

  return 0;
}
