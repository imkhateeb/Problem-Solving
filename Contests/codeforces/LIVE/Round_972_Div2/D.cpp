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

let calculate_score(const string &combined_string)
{
  let narek_score = 0, chatgpt_score = 0;
  unordered_set<let> used;
  let i = 0;
  const string target = "narek";

  while (i < combined_string.length())
  {
    bool found = true;
    for (char letter : target)
    {
      while (i < combined_string.length() && combined_string[i] != letter)
      {
        if (target.find(combined_string[i]) != string::npos && used.find(i) == used.end())
        {
          chatgpt_score++;
          used.insert(i);
        }
        i++;
      }
      if (i == combined_string.length())
      {
        found = false;
        break;
      }
      used.insert(i);
      i++;
    }
    if (found)
    {
      narek_score += 5;
    }
    else
    {
      for (let j = i - used.size(); j < i; j++)
      {
        if (used.find(j) == used.end() && target.find(combined_string[j]) != string::npos)
        {
          chatgpt_score++;
        }
      }
      break;
    }
  }

  for (let j = i; j < combined_string.length(); j++)
  {
    if (target.find(combined_string[j]) != string::npos && used.find(j) == used.end())
    {
      chatgpt_score++;
    }
  }

  return narek_score - chatgpt_score;
}

let generate_combinations(const vs &strings, let index, const string &current)
{
  if (index == strings.size())
  {
    return calculate_score(current);
  }

  let score_without = generate_combinations(strings, index + 1, current);
  let score_with = generate_combinations(strings, index + 1, current + strings[index]);

  return max(score_without, score_with);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  let T;
  cin >> T;
  while (T--)
  {
    let n, m;
    cin >> n >> m;
    vs strings(n);
    for (let i = 0; i < n; i++)
    {
      cin >> strings[i];
    }

    cout << generate_combinations(strings, 0, "") << endl;
  }

  return 0;
}