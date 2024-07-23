#include<bits/stdc++.h>
using namespace std;

class Graph{
  int v;
  vector<pair<int, pair<int, int>>> edgelist;

public:
  Graph(int v){
    this->v = v;
  }

  void addEdges(int x, int y, int wt){
    edgelist.push_back({wt, {x, y}});
  }

  // implementing DSU
  int findSet(int i, int* par){
    if(par[i] == i) return i;
    else return par[i] = findSet(par[i], par);
  }

  void unionSet(int x, int y, int* par, int* rank){
    int p1 = findSet(x, par);
    int p2 = findSet(y, par);

    if(p1 != p2){
      if(rank[p1] > rank[p2]) par[p2] = p1;
      else if(rank[p2] > rank[p1]) par[p1] = p2;
      else{
        par[p1] = p2;
        rank[p2]++;
      }
    }
  }


  // kruskal Algo starts from here
  int MST_Krushkal(){
    int cost = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pQue;
    int* par = new int[v]{-1};
    int* rank = new int[v]{0};

    vector<pair<int, pair<int, int>>> selectedEdges;

    for(int i=0; i<v; i++){
      par[i] = i;
    }

    for(auto X:edgelist){
      int wt = X.first;
      int fromNode = X.second.first;
      int toNode = X.second.second;

      pQue.push({wt, {fromNode, toNode}});
    }

    while(!pQue.empty()){
      auto minCost = pQue.top();
      int minCostX = minCost.second.first;
      int minCostY = minCost.second.second;
      int minCostWT = minCost.first;

      pQue.pop();

      int p1 = findSet(minCostX, par);
      int p2 = findSet(minCostY, par);

      if(p1 != p2){
        cost += minCostWT;
        selectedEdges.push_back({minCostWT, {minCostX, minCostY}});
        unionSet(p1, p2, par, rank);
      }
    }
    cout << "the edges: " << endl;
    for(auto X:selectedEdges){
      cout << "(" << X.second.first << " -> " << X.second.second << ", " << X.first << ")" << endl;
    }

    delete [] par;
    delete [] rank;
    return cost;
  }  

};

int main(){
  Graph g(5);

  g.addEdges(0, 1, 1);
  g.addEdges(0, 2, 2);
  g.addEdges(1, 3, 2);
  g.addEdges(1, 2, 2);
  g.addEdges(2, 3, 3);
  g.addEdges(0, 3, 2);
  g.addEdges(3, 4, 6);

  cout << "MST COST: " << endl << g.MST_Krushkal() << endl;

  return 0;
}
