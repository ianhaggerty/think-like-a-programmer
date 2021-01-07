#include <iostream>

using namespace std;

int main()
{
  int i = 5, j = 5;

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