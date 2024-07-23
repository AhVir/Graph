#include<bits/stdc++.h>
using namespace std;
int vis[100][100] = {0};

bool inRange(int x, int y, int row, int col){
  if(x >= 0 && x < row && y >=0 && y < col){
    return true;
  }
  else return false;
}

bool bfs(int srcX, int srcY, string target, int targetWordSize, vector<vector<char>>& board, int row, int col, vector<pair<int, int>>& tempVis){
  int mvX[] = {0, 0, -1, 1, 1, -1, 1, -1};
  int mvY[] = {1, -1, 0, 0, 1, -1, -1, 1};

  vis[srcX][srcY] = 1;
  tempVis.push_back({srcX, srcY});

  queue<pair<int, int>> que;
  que.push({srcX, srcY});
  int currentTarget = 1;

  while(!que.empty()){
    if(currentTarget == targetWordSize){
      cout << "Word found! -> ";
      cout << target << endl;

      //clearing the visited array input
      vis[srcX][srcY] = 0;
      for(auto e:tempVis){
      vis[e.first][e.second] = 0;
      }
      return true;
    }
    char targetChar = target[currentTarget];
    auto topPair = que.front();
    int x = topPair.first;
    int y = topPair.second;
    que.pop();

    for(int i=0; i<8; i++){
      int newX = x + mvX[i];
      int newY = y + mvY[i];
      

      if(inRange(newX, newY, row, col) && vis[newX][newY] == 0 && board[newX][newY] == targetChar){ 
        currentTarget++;
        vis[newX][newY] = 1;
        tempVis.push_back({newX, newY});
        que.push({newX, newY});
      }
    }
  }
  vis[srcX][srcY] = 0;
  for(auto e:tempVis){
    vis[e.first][e.second] = 0;
  }
  return false;
}

int findingWords(vector<vector<char>>& board, int row, int col, vector<string>& words, int wordCnt){
  int foundWords = 0;
  vector<pair<int, int>> tempVis;

  for(int i=0; i<wordCnt; i++){
    string currentWord = words[i];
    int wordSize = currentWord.size();

    for(int j=0; j<row; j++){
      for(int k=0; k<col; k++){
        if(board[j][k] == currentWord[0]){
          //if the first character matches
          if(bfs(j, k, currentWord, wordSize, board, row, col, tempVis)){
            foundWords++;
            j = row;
            k = col;
          }
        }
      }
    }
  }
  
  return foundWords;
}

int main(){
  freopen("boardGame.txt", "r", stdin);
  int row, col; cin >> row >> col;

  vector<vector<char>> board;
  for(int i=0; i<row; i++){
    vector<char> temp;
    for(int j=0; j<col; j++){
      char x; cin >> x;
      temp.push_back(x);
    }
    board.push_back(temp);
  }
  
  int wordCnt; cin >> wordCnt;
  vector<string> words;
  for(int i=0; i<wordCnt; i++){
    string temp; cin >> temp;
    words.push_back(temp);
  } 

  /*
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  cout << "WORDS: ";
  for(string x:words) cout << x << " ";
  cout << endl;
  */


  cout << "Found words: " << endl << findingWords(board, row, col, words, wordCnt) << endl;

  return 0;
}
