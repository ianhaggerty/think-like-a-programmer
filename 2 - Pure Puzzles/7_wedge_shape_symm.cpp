#include <iostream>

using namespace std;

void makeWedge(bool reverse)
{
  int i = -1, j;

  auto makeSpace = [&i, &j]() {
    for (j = 0; j < i; ++j)
    {
      cout << " ";
    }
  };

  while (++i < 4)
  {
    makeSpace();

    for (j = 4; j > i; --j)
    {
      cout << "##";
    }

    makeSpace();

    cout << "\n";
  }
}

int main()
{
  makeWedge(true);
  makeWedge(false);
}