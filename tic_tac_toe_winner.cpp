#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  string checkRowsAndCols(vector<vector<char>> &board)
  {
    int size = board.size(); // 3

    int countXrow, countYrow;
    int countXcol, countYcol;

    for (int i = 0; i < size; i++)
    {
      countXrow = countYrow = 0;
      countXcol = countYcol = 0;

      for (int j = 0; j < size; j++)
      {
        // Check rows
        if (board[i][j] == 'X')
        {
          countXrow++;
        }
        else if (board[i][j] == 'O')
        {
          countYrow++;
        }

        // Check columns
        if (board[j][i] == 'X')
        {
          countXcol++;
        }
        else if (board[j][i] == 'O')
        {
          countYcol++;
        }
      }

      if (countXrow == size)
      {
        return "A";
      }
      else if (countYrow == size)
      {
        return "B";
      }

      if (countXcol == size)
      {
        return "A";
      }
      else if (countYcol == size)
      {
        return "B";
      }
    }

    return " ";
  }

  string checkDiagonals(vector<vector<char>> &board)
  {
    if (board[1][1] == ' ')
      return " ";
    char xOrO = board[1][1];

    if (board[2][2] == xOrO && board[0][0] == xOrO)
    {
      return (xOrO == 'X') ? "A" : "B";
    }
    else if (board[0][2] == xOrO && board[2][0] == xOrO)
    {
      return (xOrO == 'X') ? "A" : "B";
    }
    return " ";
  }

public:
  string tictactoe(vector<vector<int>> &moves)
  {
    vector<vector<char>> board = {{' ', ' ', ' '},
                                  {' ', ' ', ' '},
                                  {' ', ' ', ' '}};
    char turn = 'X';

    for (int i = 0; i < moves.size(); i++)
    {
      board[moves[i][0]][moves[i][1]] = turn;
      turn = (turn == 'O') ? 'X' : 'O';
    }

    // END GAME
    string rows_cols, diag;
    rows_cols = checkRowsAndCols(board);
    diag = checkDiagonals(board);
    if (rows_cols != " ")
      return rows_cols;
    if (diag != " ")
      return diag;
    return (moves.size() == 9) ? "Draw" : "Pending";
  }
};

int main()
{
  vector<vector<int>> moves = {
      {0, 2},
      {2, 0},
      {1, 2},
      {0, 0},
      {1, 0},
      {2, 2}};
  Solution sol;
  string result = sol.tictactoe(moves);
  cout << result << endl;
}

/*
WAYYYYY BETTER SOLUTION

           0    1    2  cols
      0   [ ]  [ ]  [ ]
      1   [ ]  [ ]  [ ]
      2   [ ]  [ ]  [ ]
    rows

  0. row 0  --> player[r]
  1. row 1  --> player[r]
  2. row 2  --> player[r]
  3. col 0  --> player[c+3] (+3 to shift to 'cols' area)
  4. col 1  --> player[c+3]
  5. col 2  --> player[c+3]
  6. diagonal top left - bottom right  --> player[6]     r==c:   {0,0}, {1,1}, {2,2}
  7. diagonal top right - bottom left  --> player[7]     r==2-c: {2,0}, {1,1}, {0,2}


   string tictactoe(vector<vector<int>>& moves) {
      vector<int> A(8,0), B(8,0); // 3 rows, 3 cols, 2 diagonals
      for(int i=0; i<moves.size(); i++) {
          int r=moves[i][0], c=moves[i][1];
          vector<int>& player = (i%2==0)?A:B;
          player[r]++;
          player[c+3]++;
          if(r==c) player[6]++;
          if(r==2-c) player[7]++;
      }
      for(int i=0; i<8; i++) {
          if(A[i]==3) return "A";
          if(B[i]==3) return "B";
      }
      return moves.size()==9 ? "Draw":"Pending";
  }
*/