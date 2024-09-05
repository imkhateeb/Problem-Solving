#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op)
{
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  if (op == '^')
    return 3;
  return 0;
}

// Function to check if a character is an operand (i.e., an alphabet or digit)
bool isOperand(char ch)
{
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix)
{
  stack<char> st;
  string postfix = "";

  for (int i = 0; i < infix.length(); i++)
  {
    char ch = infix[i];

    // If the character is an operand, add it to the output
    if (isOperand(ch))
    {
      postfix += ch;
    }
    // If the character is '(', push it to the stack
    else if (ch == '(')
    {
      st.push(ch);
    }
    // If the character is ')', pop and output from the stack until '(' is found
    else if (ch == ')')
    {
      while (!st.empty() && st.top() != '(')
      {
        postfix += st.top();
        st.pop();
      }
      st.pop(); // Pop '('
    }
    // If an operator is found
    else
    {
      while (!st.empty() && precedence(st.top()) >= precedence(ch))
      {
        postfix += st.top();
        st.pop();
      }
      st.push(ch);
    }
  }

  // Pop all the remaining operators from the stack
  while (!st.empty())
  {
    postfix += st.top();
    st.pop();
  }

  return postfix;
}

int main()
{
  string infix;
  cout << "Enter infix expression: ";
  cin >> infix;

  string postfix = infixToPostfix(infix);
  cout << "Postfix expression: " << postfix << endl;

  return 0;
}
