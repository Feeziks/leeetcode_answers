#include <vector>
#include <iostream>
#include <cmath>


class Solution
{
private:
  static constexpr int mod = 1e9+7;
  long long myPow(long long base, long long exp)
  {
    long long result = 1;
    base = base % mod;
    while( exp > 0)
    {
      if(1 == exp % 2)
      {
        result = (result * base) % mod;
      }
      base = (base * base) % mod;
      exp /= 2;
    }
    return result;
  }
public:
  int countGoodNumbers(long long n)
  {
    // How many even locations are there in N?
    long long countEvenIdx = (n + 1) / 2; // Add the +1 for the '0' index
    // How many odd locations are there in N?
    long long countOddIdx = n / 2; // no need to add for the '0' index in odd count

    // 5 total even values per digit, 4 total primte values per digit
    long long totalPermutations = myPow(5, countEvenIdx) * myPow(4, countOddIdx);
    totalPermutations = totalPermutations % mod;
    return static_cast<int>(totalPermutations);
  }
};