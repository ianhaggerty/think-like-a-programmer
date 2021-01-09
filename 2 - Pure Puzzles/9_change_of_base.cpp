#include <iostream>
#include <math.h>

using namespace std;

/**
 * Tests whether a string consists entirely of digits.
 * e.g. "123" -> true, "12a" -> false, etc.
 */
bool isNumber(const string &s)
{
  string::const_iterator it = s.begin();

  do
  {
    if (!isdigit(*it))
    {
      return false;
    }
  } while (++it != s.end());

  return true;
}

/**
 * Tests whether a given string represents a number in
 * a given base.
 * e.g. ("23A", base 12) -> true, ("23A", base 8) -> false
 */
bool isNumber(const string &s, const int base)
{
  string::const_iterator it = s.begin();

  do
  {
    if (isdigit(*it))
    {
      // is digit
      if (base <= *it - '0')
      {
        return false;
      }
      else
      {
        return true;
      }
    }
    else if (isalpha(*it))
    {
      // is alpha
      if (base <= 10)
      {
        return false;
      }
      if (toupper(*it) < 'A')
      {
        return false;
      }
      if ('A' + base - 10 <= toupper(*it))
      {
        return false;
      }
    }
    else
    {
      // not alpha nor digit -> false
      return false;
    }
  } while (++it != s.end());

  return true;
}

/**
 * Converts a character to it's representational integer.
 * e.g. 'A' -> 10, 'B' -> 11, etc.
 */
int charToInt(char c)
{
  if (isdigit(c))
  {
    return (int)c;
  }

  c = toupper(c);

  if ('A' <= c && c <= 'Z')
  {
    return c - 'A' + 10;
  }

  throw invalid_argument("Only the letters 'A' through 'Z' are supported.");
}

/**
 * Converts an integer to it's representational character.
 * e.g. 10 -> 'A', 11 -> 'B', etc.
 */
char intToChar(int i)
{
  if (0 <= i && i <= 9)
  {
    return i + '0';
  }

  if (10 <= i && i < 36)
  {
    // 10 == A, 11 = B, ... , 35 == Z
    return i + 'A' - 10;
  }

  throw invalid_argument("Only the integers 0 through 35 are supported.");
}

/**
 * Get a base from the user and return as an integer.
 */
int getBase(string prompt)
{
  string baseStr;
  int base;

  while (true)
  {
    cout << prompt;
    cin >> baseStr;

    //  Is it a number?
    if (!isNumber(baseStr))
    {
      cout << baseStr << " is not a positive integer.";
      continue;
    }
    base = stoi(baseStr);

    // Bounds check.
    if (base < 2 || 35 < base)
    {
      cout << "Input base must be an integer from 0 to 35 inclusive.\n";
      continue;
    }

    // All ok, break.
    break;
  }

  return base;
}

/**
 * Get a number from the user subject to the specified base.
 */
string getNumber(int base)
{
  string numberStr;

  while (true)
  {
    // Prompt the user for the number (in the base specified)
    cout << "\nUsing the characters ";
    cout << "(0 - " << min(base, 10) - 1;

    if (base == 11)
    {
      cout << ", A";
    }
    if (base > 11)
    {
      cout << ", A - " << (char)('A' + base - 11);
    }
    cout << "), ";
    cout << "please a number in base " << base << ": ";
    cin >> numberStr;

    // Check characters for validity.
    if (!isNumber(numberStr, base))
    {
      cout << '\"' << numberStr << '\"';
      cout << " is not a valid representation of a base ";
      cout << base << " number.\n";
      continue;
    }

    break;
  }

  return numberStr;
}

/**
 * Calculate the numerical weight of a number in a given base.
 * e.g. "FF" -> 255
 */
int baseToInt(int inputBase, string inputNumber)
{
  // calculate numeric weight of inputNumber
  int input = 0,
      inputLength = inputNumber.length();

  for (int i = 0; i < inputLength; ++i)
  {
    input += charToInt(inputNumber[inputLength - 1 - i]) * pow(inputBase, i);
  }

  return input;
}

/**
 * Convert a numerical weight to a string representation in the
 * given base.
 * e.g. (16, 255) -> "FF"
 */
string intToBase(int outputBase, int inputNumber)
{
  string output = "";

  do
  {
    output.insert(0, 1, intToChar(inputNumber % outputBase));
    // output = intToChar(inputNumber % outputBase) + output;
    // output = (char)('0' + inputNumber % outputBase) + output;
    // cout << inputNumber;
    inputNumber /= outputBase;
  } while (inputNumber > 0);

  return output;
}

int main()
{
  string
      inputNumber,
      outputNumber;
  int inputBase,
      outputBase,
      weight;
  char prompt;

  while (true)
  {
    // Prompt the user for an input base.
    inputBase = getBase("\nPlease enter an input base (in base-10): ");

    // Prompt the user for a number.
    inputNumber = getNumber(inputBase);

    // Prompt the user for an output base.
    outputBase = getBase("\nPlease enter an output base (in base-10): ");

    // Convert base -> weight -> base
    weight = baseToInt(inputBase, inputNumber);
    outputNumber = intToBase(outputBase, weight);

    cout << "Your number is " << weight << '\n';
    cout << "Your number in base " << outputBase << " is " << outputNumber << '\n';

    cout << "Another go? ";
    cin >> prompt;

    if (toupper(prompt) == 'Y')
    {
      cout << '\n'
           << "----------" << '\n';
      continue;
    }
    else
    {
      break;
    }
  }
}
