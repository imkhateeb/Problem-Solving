#include <bits/stdc++.h>
#define let long long
using namespace std;

int main()
{
  let t;
  cin >> t;

  while (t--)
  {

    let n, m;
    cin >> n >> m;

    string path;
    cin >> path;

    vector<vector<let>> matrix(n, vector<let>(m, 0));

    for (let i = 0; i < n; i++)
    {
      for (let j = 0; j < m; j++)
      {
        cin >> matrix[i][j];
      }
    }

    vector<pair<char, pair<let, let>>> ops;

    int row = 1;
    int col = 1;

    let pathSize = path.size();

    for (let i = 0; i < pathSize; i++)
    {
      if (path[i] == 'D')
      {
        ops.push_back({'R', {row, col}});
        row++;
      }
      else
      {
        ops.push_back({'C', {row, col}});
        col++;
      }
    }

    for (auto op : ops)
    {

      char option = op.first;
      int r = op.second.first - 1;
      int c = op.second.second - 1;

      let tempSum = 0;

      if (option == 'R')
      {
        for (int i = 0; i < m; i++)
        {
          tempSum += matrix[r][i];
        }
      }
      else
      {
        for (int i = 0; i < n; i++)
        {
          tempSum += matrix[i][c];
        }
      }

      matrix[r][c] = (-1) * tempSum;
    }

    let tempSum = 0;
    for (let i = 0; i < m; i++)
    {
      tempSum += matrix[n - 1][i];
    }

    matrix[n - 1][m - 1] = (-1) * tempSum;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}