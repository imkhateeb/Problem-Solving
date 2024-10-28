#include <iostream>
#include <vector>
using namespace std;

void generateAll(int k, vector<string> &ans)
{

  if (k == 1)
  {
    string str1 = "0";
    string str2 = "1";

    ans.push_back(str1);
    ans.push_back(str2);

    return;
  }

  generateAll(k - 1, ans);
  vector<string> temp;

  for (int i = 0; i < ans.size(); i++)
  {
    if (ans[i][ans[i].size() - 1] == '1')
    {
      ans[i].push_back('0');
    }
    else
    {
      string str = ans[i];
      ans[i].push_back('0');
      str.push_back('1');
      temp.push_back(str);
    }
  }

  for (int i = 0; i < temp.size(); i++)
  {
    ans.push_back(temp[i]);
  }
}

int main()
{

  int k;
  cout << "Enter value of K: ";
  cin >> k;
  vector<string> ans;

  generateAll(k, ans);

  for (auto x : ans)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}