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

  void bfs(int source, int target){
    vector<int> visited(v, 0);
    queue<int> que;
    vector<int> dist(v, 0);
    vector<int> parents(v, -1);


    //bfs's starting:
    cout << "BFS: "; 
    que.push(source);
    visited[source] = 1;
    parents[source] = source;

    while(!que.empty()){
      int nodeFront = que.front();
      cout << nodeFront << " -> ";
      que.pop();

      for(int X:edges[nodeFront]){
        if(!visited[X]) visited[X] = 1, que.push(X), dist[X] = dist[nodeFront] + 1,
        parents[X] = nodeFront;
      }
    }
    cout << endl;



    //shortest path
    cout << "Shortest Path: " << endl;
    for(int i=0; i<dist.size(); i++){
      cout << "Shortest Path to " << i << " is " << dist[i] << endl;
    }
    


    //finding the path
    int temp = target;
    vector<int> paths;
    while(parents[temp] != temp){
      paths.push_back(temp);
      temp = parents[temp];
    }
    paths.push_back(temp);
    
    //reversing the backtracked path
    reverse(paths.begin(), paths.end());
    cout << "PATH to (" << target << "): ";
    for(int p:paths) cout << p << " => ";
    cout << "END!!" << endl;
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

  g.bfs(1, 6);

  return 0;
}
