#include <iostream>

using namespace std;

int main()
{
  int i = -1, j;

  while (++i < 4)
  {
    for (j = 0; j < i; ++j)
    {
      cout << " ";
    }

    for (j = 4; j > i; --j)
    {
      cout << "##";
    }

    for (j = 0; j < i; ++j)
    {
      cout << " ";
    }

    cout << "\n";
  }
}