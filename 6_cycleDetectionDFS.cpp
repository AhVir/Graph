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
      for(int x:edges[i]) cout << x << " -> ";
      cout << endl;
    }
  }


  bool checkCycle(){
    int source = 0;
    stack<int> st;
    vector<int> visited(v, 0);
    vector<int> parents(v, -1);
    
    //dfs starts from here
    st.push(source);
    visited[source] = 1;
    parents[source] = 0;

    while(!st.empty()){
      int topNode = st.top();
      st.pop();
      
      for(int X:edges[topNode]){
        if(visited[X] && (X != parents[topNode])){
          return true;
        }
        else if(!visited[X]) visited[X] = 1, st.push(X), parents[X] = topNode;
      }
    }
    return false;
  }
};

int main(){
  Graph g(5);

  //adding edges
  g.addEdges(0, 1);
  g.addEdges(1, 2);
  g.addEdges(2, 3);
  g.addEdges(3, 4);
  g.addEdges(0, 2);

  g.printGraph();

  cout << "Cycle exists: " << g.checkCycle() << endl;

  return 0;
}
