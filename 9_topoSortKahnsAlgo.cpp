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
    cout << "Printing the graph:" << endl;

    for(int i=0; i<v; i++){
      cout << i << " -> ";
      for(int x:edges[i]) cout << x << " -> ";
      cout << endl;
    }
  }


  void topoSortKahnAlgo(){
    // finding the inDegrees
    vector<int> indegrees(v, 0);
    for(int i=0; i<v; i++){
      for(int X:edges[i]){
        indegrees[X]++;
      }
    }


    // kind of BFS alike approach starts
    queue<int> que;
    vector<int> vis(v, 0);
    
    //pushing all the nodes with 0 indegree
    for(int i=0; i<v; i++) if(indegrees[i] == 0) que.push(i), vis[i] = 1;

    vector<int> ans; //will store the answers in this vector

    while(!que.empty()){
      int frontNode = que.front();
      que.pop();
      ans.emplace_back(frontNode); //saving the answers

      //will explore all the edges of frontNode
      for(int X:edges[frontNode]){
        if(!vis[X]){
          indegrees[X]--;
          if(!indegrees[X]) que.push(X), vis[X] = 1;
        }
      }
    }


    //printing the answers:
    cout << "Topo Sort: ";
    for(int e:ans) cout << e << " -> ";
    cout << "END!!" << endl;

    cout << "indegress: " << endl;
    for(int i=0; i<v; i++) cout << i << ": " << indegrees[i] << endl;
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

  g.topoSortKahnAlgo();

  return 0;
}
