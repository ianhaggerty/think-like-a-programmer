#include <iostream>

using namespace std;

void printSpaceLeftRight(int row)
{
  for (int i = 0; i < row; ++i)
  {
    cout << " ";
  }
}

void printSpaceMiddle(int row)
{
  if (row == 3)
  {
    return;
  }

  for (int i = 0; i < 12 - row * 4; ++i)
  {
    cout << " ";
  }
}

void printXLeftRight(int row)
{
  for (int i = 0; i <= row; ++i)
  {
    cout << "X";
  }
}

int main()
{
  int row = 0;

  while (row < 4)
  {
    printSpaceLeftRight(row);
    printXLeftRight(row);
    printSpaceMiddle(row);
    printXLeftRight(row);
    printSpaceLeftRight(row);
    cout << '\n';
    ++row;
  }
}
