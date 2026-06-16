#include <stdio.h>

// Greatest Common Divisor

int gcd(int a, int b) {

  // when a becomes 0, it means the previous operation had a remainder of 0
  if (a == 0) {
    // it only be b=1
    // if they only had 1 as their common divisor
    return b;
  }
  // otherwise, it shrinks the numberset via Euclids algo
  // until one of them becomes 0.
  // and b becomes the answer
  // gcd(18,48) -> gcd(12,18) -> gcd(6,12) -> gcd(0,6) -> returns 6
  return gcd(b % a, a);
}

// Euler Totient Formula
int etf(int n) {

  int result = 1; // every number is divisible by 1, so we count it intially.
  // we start with 2, cuz we already know anything is divisible by 1.
  // this for loop is supposed to check every number that comes before `n`
  // which in this case is n = 11 
  // so this goes through all nums
  // 2,3,4,5,6,7,8,9,10..stop
  // just to check if they are not a factor of n = 11
  // meaning it does n % i
  // where i is 2,3,4..10
  for (int i = 2; i < n; i++) {

    // so after we go through gcd
    // if gcd returns 1. we know a became 0,
    // meaning the number we divided n with
    // only had the number `1` as their common divisor.
    if (gcd(i, n) == 1) {
      // and then we increase the count
      result++;
    }
  }
  return result;
}

int main() {

  int n = 11;
  // if n = 11, this would print 10, meaning there are 10 coprimes?
  // Co-Prime: when considering two nums, a and n, if their common divisor is only 1
  // that is a co-prime
  printf("%d\n", etf(n));

  return 0;
}
