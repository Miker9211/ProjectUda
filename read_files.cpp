#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle, kClose};

vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if(n == 0){
        row.push_back(State::kEmpty);
      }
      else{
        row.push_back(State::kObstacle);
      }    
    }
    return row;
}


vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}

bool Compare(const vector<int> a, vector<int> b)
{
  int f1 = a[2] + a[3]; //f1 = g1 + h1
  int f2 = b[2] + b[3]; // f2 = g2 + h2
  return f1 > f2; 
}

int heuristic(int x1, int x2, int y2, int y1)
{
  return abs(x2 - x1) + abs(y2 - y1);

}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &nodes, vector<vector<State>> &grid)
{
    
    nodes.push_back(vector<int>{x, y, g, h});
    grid[x][y] = State::kClose;
}

vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2])
{
    vector<vector<int>> open {};

    int x = 0;
    int y = 1;
    int g = 0;
    int h = heuristic(x, y, init[0], goal[1]);
    AddToOpen(x, y, g, h, open, grid);

    cout << "No Path Found" << "\n";
    return vector<vector<State>> {};
}

string CellString(State cell) {
  switch(cell) {
    case State::kObstacle: return "⛰️   ";
    default: return "0   "; 
  }
}

void PrintBoard (const vector<vector<State>> board)
{
    for (int i = 0; i < board.size(); i++){
      for (int j = 0; j < board[i].size(); j++){
        cout << CellString(board[i][j]);
      }
      cout << "\n";
    }
}

int main() {
    
    int init[2]{0,0};
    int goal[2]{4,5};
  auto board = ReadBoardFile("1.board");
  auto solution = Search(board, init, goal);
  PrintBoard(board);
}