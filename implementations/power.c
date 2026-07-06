#include "../headers/power.h"

// where base is either the message we encrypt
// or the encrypted message we decrypt
// exp is the exponent
// m is the modulus
//
// exp can either be `d` or `e` from
// the methods encrypt & decrypt
int power(int base, int exp, int m) {

  int result = 1;
  base = base % m;
  while (exp > 0) {
    // if exp is odd
    if (exp % 2 != 0) {
      // calculate M^e * (mod m)
      result = (result * 1LL * base) % m;
    }
    base = (base * 1LL * base) % m;
    exp = exp / 2;
  }
  return result;
}
