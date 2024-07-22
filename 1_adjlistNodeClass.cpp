#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Node{
public:
  string name;
  vector<string> neighbours;

  Node(string name){
    this->name = name;
  }
};

class Graph{
  int v;
  unordered_map<string, Node*> map;
public:
  Graph(vector<string> cities){
    this->v = cities.size();

    for(string city:cities){
      map[city] = new Node(city);
    }
  }

  void addEdges(string x, string y, bool direc=false){
    map[x]->neighbours.push_back(y);

    if(direc) map[y]->neighbours.push_back(x);
  }


  void printGraph(){
    for(auto x:map){
      cout << x.first << " -> ";
      for(auto y:x.second->neighbours) cout << y << " -> ";
      cout << endl;
    }
  }
};

int main(){
  vector<string> cities = {"Delhi", "London", "Paris", "New York"};
  Graph g(cities);

  g.addEdges("Delhi", "London");
  g.addEdges("New York", "London");
  g.addEdges("Delhi", "Paris");
  g.addEdges("Paris", "New York");


  g.printGraph();

  return 0;
}
