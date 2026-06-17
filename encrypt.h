#include "power.h"
// Encrypt message using public key (e, n)
// m is modulo
int encrypt(int m, int e, int n) {
    return power(m, e, n);
}
