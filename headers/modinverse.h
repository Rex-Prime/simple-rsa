// this function is supposed to return d
// by brute force
int modInverse(int e, int phi) {
  for (int d = 2; d < phi; d++) {
    // this is the same representation as:
    // e * d = 1 mod(phi)
    if (((e * d) % phi) == 1) {
      return d;
    }
  }
  // if the loop finishes and cant find a value `d`
  // it returns an error
  return -1;
}
