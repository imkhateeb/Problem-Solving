#include <bits/stdc++.h>
#define let long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define endl "\n"
#define vi vector<let>
#define vvi vector<vector<let>>
#define vs vector<string>
#define vpii vector<pair<let, let>>
using namespace std;

// Helper function to generate all possible strings
void generateStrings(int n, int current_length, vector<string> &ones, vector<string> &zeroes,
                     string current_string, vector<string> &results)
{
  // If current string length is close to n - (last ones + last zeroes), stop recursion
  if (current_length >= n - (ones.back().length() + zeroes.back().length()))
  {
    current_string += ones.back();
    current_string += zeroes.back();

    // Truncate if necessary
    if (current_string.length() > n)
    {
      current_string = current_string.substr(0, n);
    }

    results.push_back(current_string);

    // Interact with the system to check if the string is correct
    cout << "? " << current_string << endl;
    cout.flush();

    int response;
    cin >> response;

    // If the response is correct (1), output and terminate
    if (response == 1)
    {
      cout << "! " << current_string << endl;
      return;
    }
  }

  // Recur by adding elements from both 'ones' and 'zeroes', reusing them multiple times
  for (const string &one : ones)
  {
    generateStrings(n, current_length + one.length(), ones, zeroes, current_string + one, results);
  }
  for (const string &zero : zeroes)
  {
    generateStrings(n, current_length + zero.length(), ones, zeroes, current_string + zero, results);
  }
}

// Function to generate all possible strings
void generateAllPossibleStrings(int n, vector<string> &ones, vector<string> &zeroes)
{
  vector<string> results;
  generateStrings(n, 0, ones, zeroes, "", results);
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let n;
    cin >> n;

    vector<string> ones;
    vector<string> zeroes;

    // Collecting strings for 'ones'
    string str = string(1, '1');
    for (let i = 0; i < n; ++i)
    {
      cout << "? " << str << endl;
      cout.flush();

      int response;
      cin >> response;

      if (response == 1)
      {
        ones.push_back(str);
        str.push_back('1');
      }
      else
      {
        break;
      }
    }

    // Collecting strings for 'zeroes'
    str = string(1, '0');
    for (let i = 0; i < n; ++i)
    {
      cout << "? " << str << endl;
      cout.flush();

      int response;
      cin >> response;

      if (response == 1)
      {
        zeroes.push_back(str);
        str.push_back('0');
      }
      else
      {
        break;
      }
    }

    // Generate all possible strings using collected 'ones' and 'zeroes'
    generateAllPossibleStrings(n, ones, zeroes);
  }

  return 0;
}
