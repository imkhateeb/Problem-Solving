#include <iostream>
using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    int x = 0;
    int move = 1;

    bool sakurakoTurn = true;

    while (true)
    {
      if (sakurakoTurn)
      {
        x -= move;
      }
      else
      {
        x += move;
      }

      if (abs(x) > n)
      {
        if (sakurakoTurn)
        {
          cout << "Sakurako" << endl;
        }
        else
        {
          cout << "Kosuke" << endl;
        }
        break;
      }

      sakurakoTurn = !sakurakoTurn;
      move += 2;
    }
  }

  return 0;
}
