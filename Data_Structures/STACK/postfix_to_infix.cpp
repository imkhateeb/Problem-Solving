#include <iostream>
#include <stack>
#include <string>

using namespace std;

string postfixToInfix(string s)
{
  stack<string> st;

  for (int i = 0; i < s.size(); i++)
  {

    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
    {
      st.push(string(1, s[i]));
    }
    else
    {
      string op1 = st.top();
      st.pop();
      string op2 = st.top();
      st.pop();

      string temp = "(" + op2 + s[i] + op1 + ")";
      st.push(temp);
    }
  }

  return st.top();
}

int main()
{

  string s;
  cout << "Enter postfix expression: ";
  cin >> s;

  string infix = postfixToInfix(s);

  cout << "Infix expression: " << infix << endl;

  return 0;
}