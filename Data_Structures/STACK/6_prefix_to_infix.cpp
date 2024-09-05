#include <iostream>
#include <stack>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert prefix expression to infix expression
string prefixToInfix(string prefix)
{
  stack<string> st;

  // Traverse the prefix expression from right to left
  for (int i = prefix.length() - 1; i >= 0; i--)
  {
    char ch = prefix[i];

    // If the character is an operand, push it to the stack
    if (!isOperator(ch))
    {
      st.push(string(1, ch));
    }
    // If the character is an operator
    else
    {
      // Pop two operands from the stack
      string op1 = st.top();
      st.pop();
      string op2 = st.top();
      st.pop();

      // Combine them into an infix expression with the operator in between
      string infix = "(" + op1 + ch + op2 + ")";

      // Push the resulting infix expression back to the stack
      st.push(infix);
    }
  }

  // The final infix expression will be the only element left in the stack
  return st.top();
}

int main()
{
  string prefix;
  cout << "Enter prefix expression: ";
  cin >> prefix;

  string infix = prefixToInfix(prefix);
  cout << "Infix expression: " << infix << endl;

  return 0;
}
