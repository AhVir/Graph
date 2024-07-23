#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

bool isInGrid(int x, int y, int row, int col){
  if(x >= 0 && x <col && y >= 0 && y < row) return true;
  else return false;
}

int bfs(vector<vector<int>>& grid, int x, int y, int row, int col){
  int mvX[] = {0, 0, -1, 1};
  int mvY[] = {-1, +1, 0, 0};

  int tempCnt = 1;
  grid[x][y] = 0;
  queue<pair<int, int>> que;

  que.push({x, y});
  
  while(!que.empty()){
    auto frontPair = que.front();
    int X = frontPair.first;
    int Y = frontPair.second;
    que.pop();

    for(int i=0; i<4; i++){
      int newX = X+mvX[i];
      int newY = Y+mvY[i];
      if(isInGrid(newX, newY, row, col) && (grid[newX][newY] == 1)){
        tempCnt++;
        grid[newX][newY] = 0;
        que.push({newX, newY});
      }
    }
  }

  return tempCnt;
}

int largestIsland(vector<vector<int>>& grid){
  int cnt = 0;
  int row = grid.size();
  int col = grid[0].size();

  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(grid[i][j] == 1){
        int tempCnt = bfs(grid, i, j, row, col);
        cnt = max(cnt, tempCnt);
      }
    }
  }

  return cnt;
}

int main(){
  freopen("5_largestIsland.txt", "r", stdin);
  int r, c; cin >> r >> c;
  vector<vector<int>> grid;

  for(int i=0; i<r; i++){
    vector<int> temp;
    for(int j=0; j<c; j++){
      int x; cin >> x;
      temp.push_back(x);
    }
    grid.push_back(temp);
  }

  cout << "Largest Island: " << largestIsland(grid) << endl;

  return 0;
}
