#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
  char c;
  bool odd = false;
  int num, oddSum = 0, evenSum = 0, count = 0;

  while (cin >> c)
  {
    ++count;

    if (isdigit(c))
    {
      num = c - '0';
      odd = !odd;

      if (odd)
      {
        evenSum += num;

        num *= 2;
        oddSum += num % 10;
        num /= 10;
        oddSum += num;
      }
      else
      {
        oddSum += num;

        num *= 2;
        evenSum += num % 10;
        num /= 10;
        evenSum += num;
      }
    }
    else
    {
      int sum;
      if (odd)
      {
        sum = oddSum;
      }
      else
      {
        sum = evenSum;
      }

      if (sum % 10 == 0)
      {
        cout << "VALID";
      }
      else
      {
        cout << "INVALID";
      }

      cout << " Sum: " << sum << '\n';
    }
  }
}