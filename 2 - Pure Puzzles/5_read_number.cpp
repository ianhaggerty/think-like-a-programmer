#include <iostream>

using namespace std;

int main()
{
  char c;
  int num = 0;

  while (cin >> c)
  {
    if (isdigit(c))
    {
      num *= 10;
      num += c - '0';
    }
    else
    {
      break;
    }
  }

  cout << num << '\n';
}
