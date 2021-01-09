#include <iostream>

using namespace std;

void makeWedge(bool reverse)
{
  int j, i = reverse ? 4 : 0;

  auto makeSpace = [&i, &j]() {
    for (j = 0; j < i; ++j)
    {
      cout << " ";
    }
  };

  while (0 <= i && i <= 4)
  {
    makeSpace();

    for (j = 4; j > i; --j)
    {
      cout << "##";
    }

    makeSpace();

    cout << "\n";
    reverse ? --i : ++i;
  }
}

int main()
{
  makeWedge(true);
  makeWedge(false);
}