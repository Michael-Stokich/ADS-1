// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1) return false;
  if (value == 2) return true;
  if (value % 2 == 0) return false;
  for (uint64_t i = 3; i < value; i += 2) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t c = 0;
  uint64_t a = 2;
  while (c < n) {
    if (checkPrime(a)) {
      c++;
    }
    a++;
  }
  return a - 1;
}

uint64_t nextPrime(uint64_t value) {
  value++;
  while (!checkPrime(value)) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t sum = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checkPrime(i)) {
      sum += i;
    }
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t c = 0;
  for (uint64_t i = lbound; i < hbound - 1; i++) {
    if (checkPrime(i) && checkPrime(i + 2)) {
      c++;
    }
  }
  return c;
}
