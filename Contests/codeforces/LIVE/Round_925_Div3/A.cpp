#include <iostream>
using namespace std;

string smallestWord(int encoded)
{
  for (int i = 1; i <= 26; ++i)
  {
    for (int j = 1; j <= 26; ++j)
    {
      for (int k = 1; k <= 26; ++k)
      {
        int total = i + j + k;
        if (total == encoded)
        {
          string word = "";
          word += char(96 + i);
          word += char(96 + j);
          word += char(96 + k);
          return word;
        }
      }
    }
  }
  return "";
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int encoded;
    cin >> encoded;
    cout << smallestWord(encoded) << endl;
  }

  return 0;
}
