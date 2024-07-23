#include<bits/stdc++.h>
#include <iterator>
using namespace std;
#define INF 1e5+5;

int dist[100][100];

class Graph{
  int v;
  vector<pair<int, pair<int, int>>> edges;

public:
  Graph(int v){
    this->v = v;
  }

  void addEdge(int x, int y, int wt){
    edges.push_back({wt, {x, y}});
  }


  //floyd Warshall algo starts from here
  void floydWarshall(){
    //applying initial appropriate values to distance array
    for(int i=0; i<v; i++){
      for(int j=0; j<v; j++){
        if(i == j) dist[i][j] = 0;
        else dist[i][j] = INF;
      }
    }
    
    //adding edge weight to the graph:
    for(auto I:edges){
      int wt = I.first;
      int fromNode = I.second.first;
      int toNode = I.second.second;

      dist[fromNode][toNode] = wt;
    }


    //now, going through all the phases
    for(int x=0; x<v; x++){

      for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
          /*
           my problem is, 
           there is no code to confirm that
           for the xNode, we are not going to
           the xTh row and colm.
          */
          //now, check if distance can be shorten
          if(dist[i][j] > (dist[i][x] + dist[x][j])){
            dist[i][j] = dist[i][x] + dist[x][j];
          }
        } } }

    cout << "printing the distance array: " << endl;
    for(int i=0; i<v; i++){
      for(int j=0; j<v; j++){
        cout << dist[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main(){
  Graph g(4);

  g.addEdge(0, 2, -2);
  g.addEdge(1, 0, 4);
  g.addEdge(1, 2, 3);
  g.addEdge(2, 3, 2);
  g.addEdge(3, 1, -1);

  g.floydWarshall();

  return 0;
}
