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


  void printGraph(){
    cout << "Printing the graph: " << endl;
    for(int i=0; i<v; i++){
      cout << i << " -> ";
      for(int X:edges[i]) cout << X << " -> ";
      cout << endl;
    }
  }

  void dfs(vector<int>& vis, int source, vector<int>& ans){
    vis[source] = 1;

    for(int X:edges[source]){
      if(!vis[X]) dfs(vis, X, ans);
    }

    ans.push_back(source);
  }

  void topoSortDFS(){
    vector<int> vis(v, 0);
    vector<int> ans;
    
    //there can be multiple connected components
    for(int i=0; i<v; i++) if(!vis[i]) dfs(vis, i, ans);

    //printing the answer
    reverse(ans.begin(), ans.end()); //reversing the vector
  
    cout << "Topo Sort: ";
    for(int e:ans) cout << e << " -> ";
    cout << "END!!" << endl;
  }
};

int main(){
  Graph g(6);

  g.addEdges(0, 2, false);
  g.addEdges(2, 3, false);
  g.addEdges(3, 5, false);
  g.addEdges(4, 5, false);
  g.addEdges(1, 4, false);
  g.addEdges(1, 2, false);

  g.printGraph();

  g.topoSortDFS();

  return 0;
}
