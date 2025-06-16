#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
  int hash[9] = {0};

  // Check rows
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (board[i][j] != '.')
      {
        if (hash[board[i][j] - '0'] == 1)
        {
          return false;
        }
        else
        {
          hash[board[i][j] - '0'] = 1;
        }
      }
    }
    // Reset hash for next row
    fill(hash, hash + 9, 0);
  }

  // Check columns
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (board[j][i] != '.')
      {
        if (hash[board[j][i] - '0'] == 1)
        {
          return false;
        }
        else
        {
          hash[board[j][i] - '0'] = 1;
        }
      }
    }
    // Reset hash for next column
    fill(hash, hash + 9, 0);
  }

  // Check 3x3 subgrids
  for (int i = 0; i < 9; i += 3)
  {
    for (int j = 0; j < 9; j += 3)
    {
      for (int p = 0; p < 3; p++)
      {
        for (int q = 0; q < 3; q++)
        {
          if (board[i + p][j + q] != '.')
          {
            if (hash[board[i + p][j + q] - '0'] == 1)
            {
              return false;
            }
            else
            {
              hash[board[i + p][j + q] - '0'] = 1;
            }
          }
        }
      }
      // Reset hash for next subgrid
      fill(hash, hash + 9, 0);
    }
  }

  return true;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    vector<vector<char>> board(9, vector<char>(9, '.'));
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        cin >> board[i][j];
      }
    }

    if (isValidSudoku(board))
    {
      cout << "Valid" << endl;
    }
    else if (!isValidSudoku(board))
    {
      cout << "Invalid" << endl;
    }
  }
  return 0;
}