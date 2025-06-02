#include <bits/stdc++.h>

using namespace std;

void insert(stack<int> &st, int temp)
{

  if (st.size() == 0 || st.top() <= temp)
  {
    st.push(temp);
    return;
  }

  int x = st.top();
  st.pop();
  insert(st, temp);
  st.push(x);
}

void sortAnStack(stack<int> &st)
{

  if (st.size() == 1)
  {
    return;
  }

  int temp = st.top();
  st.pop();
  sortAnStack(st);
  insert(st, temp);
}

int main()
{

  stack<int> s;
  s.push(5);
  s.push(1);
  s.push(3);
  s.push(2);
  s.push(4);

  sortAnStack(s);

  while (s.size())
  {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;

  return 0;
}