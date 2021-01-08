#include <iostream>

using namespace std;

enum class Mode
{
  UPPER = 0,
  LOWER = 1,
  PUNCTUATION = 3
};

int main()
{
  char encoded, decoded;
  string accumulated = "";
  Mode mode = Mode::UPPER;

  while (cin >> encoded)
  {
    switch (mode)
    {
    case Mode::UPPER:
      if (encoded % 27 == 0)
      {
        mode = Mode::LOWER;
        continue;
      }
      else
      {
        decoded = encoded % 27 + 'A' - 1;
        break;
      }
    case Mode::LOWER:
      if (encoded % 27 == 0)
      {
        mode = Mode::PUNCTUATION;
        continue;
      }
      else
      {
        decoded = encoded % 27 + 'a' - 1;
        break;
      }
    case Mode::PUNCTUATION:
      if (encoded % 9 == 0)
      {
        mode = Mode::UPPER;
        continue;
      }
      else
      {
        switch (encoded % 9)
        {
        case 1:
          decoded = '!';
          break;
        case 2:
          decoded = '?';
          break;
        case 3:
          decoded = '\'';
          break;
        case 4:
          decoded = '.';
          break;
        case 5:
          decoded = ' ';
          break;
        case 6:
          decoded = ';';
          break;
        case 7:
          decoded = '\"';
          break;
        case 8:
          decoded = '\'';
          break;
        }
      }
      accumulated.push_back(decoded);
    }
  }

  cout << accumulated;
}