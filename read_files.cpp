#include <iostream>
#include <fstream> 
#include <string>
#include <vector>
using std::cout;
using std::ifstream;
using std::string;
using std::vector;

void ReadBoardFile(const vector<vector<int>> board)
{
    ifstream myfile("Udacity/1.board");
    if (myfile){
        string line;
        while (getline(myfile, line))
        {
            cout << line << "\n";
        }
        
    }
}
void PrintBoard(const vector<vector<int>> board)
{
    for (auto v : board){
        for (int i : v)
        cout << i << " ";
    }
    cout << "\n";
}
vector<vector<int>> board {{0,1,0,0,0,0},
{0,1,0,0,0,0},
{0,1,0,0,0,0},
{0,1,0,0,0,0},
{0,0,0,0,1,0}};

int main ()
{
    
    PrintBoard(board);
} 