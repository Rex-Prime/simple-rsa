#include "../headers/generatekey.h"

void generateKey(int *e, int *d, int *n) {
  // where p & q are two random prime numbers
  // preferably should be really big
  int p = 61;
  int q = 53;
  // n is their product
  *n = p * q;
  // afterwards we calculate
  // how many numbers before n
  // are a coprime with n, phi(n)
  // meaning, if they share 1
  // as their only common factor
  // works specifically and only because
  // n is the product of two distinct prime numbers
  // If n were a random composite number (like 12),
  // the formula would fail
  int phi = (p - 1) * (q - 1);
  // Choose e, where 1 < e <= phi(n) and gcd(e, phi(n)) == 1
  // we need this check, because otherwise,
  // calculating d would become impossible
  // as d is: e * d = 1 mod(phi)
  // d being co-prime, means that a modInverse can exist
  for (*e = 2; *e <= phi; (*e)++) {
    // we can use the defined standard gcd function
    if (gcd(*e, phi) == 1) {
      break;
    }
  }
  // Compute d such that e * d = 1 (mod phi(n))
  *d = modInverse(*e, phi);
}
