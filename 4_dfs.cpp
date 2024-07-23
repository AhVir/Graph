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

  //Printing the Graph
  void printGraph(){
    cout << "Printing the Graph: " << endl;
    for(int i=0; i<v; i++){
      cout << i << " -> ";

      for(int x:edges[i]) cout << x << " -> ";
      cout << endl;
    }
  }

  //DFS
  void dfs(int source){
    cout << "DFS: ";
    vector<int> visited(v, 0);
    stack<int> st;

    //dfs starts from here
    st.push(source);
    visited[source] = 1;

    while(!st.empty()){
      int topNode = st.top();
      st.pop();

      cout << topNode << " -> ";

      for(int X:edges[topNode]){
        if(!visited[X]){
          visited[X] = 1;
          st.push(X);
        }
      }
    }
    cout << "END!" << endl;
  }


  //DFS Recurive 
private:
  void dfsRecursion(int node, vector<int>& visited){
    visited[node] = 1;
    cout << node << " -> ";

    for(int x:edges[node]){
      if(!visited[x]) dfsRecursion(x, visited);
    }
  }

public:
  void dfsRecursive(int source){
    cout << "DFS: ";
    vector<int> visited(v, 0);

    dfsRecursion(source, visited);
    cout << "END!!(DFS Recursion)" << endl;
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

  g.dfs(1);
  g.dfsRecursive(1);

  g.printGraph();

  return 0;
}
