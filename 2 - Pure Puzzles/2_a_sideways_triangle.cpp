#include <iostream>

using namespace std;

int main()
{
  int i = 0, j = 0;

  while (i++ < 4)
  {
    while (j++ < i)
    {
      cout << '#';
    }
    cout << '\n';
    j = 0;
  }

  i = 3, j = 3;

  while (i-- > 0)
  {
    while (j-- > 0)
    {
      cout << '#';
    }
    cout << '\n';
    j = i;
  }
}