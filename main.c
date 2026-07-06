#include "implementations/gcd.c"
#include "implementations/modinverse.c"
#include "implementations/power.c"

#include "implementations/decrypt.c"
#include "implementations/encrypt.c"
#include "implementations/generatekey.c"

#include <stdio.h>

int main() {
  // where e is exponent
  // d is the value we generate
  // n is a multiple of two primes
  int e, d, n;

  generateKey(&e, &d, &n);

  printf("Public Key(e, n): (%d, %d)\n", e, n);
  printf("Private Key(d, n): (%d, %d)\n", d, n);

  int M = 123;
  printf("\nOriginal Message: %d\n", M);

  int C = encrypt(M, e, n);
  printf("\nEncrypted Message: %d\n", C);

  int D = decrypt(C, d, n);
  printf("Decrypted Message: %d\n", D);
}
