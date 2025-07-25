#include "types.h"
#include "defs.h"
#include "param.h"
#include "traps.h"
#include "spinlock.h"
#include "x86.h"

// Implementasi sederhana random number generator (Linear Congruential Generator)
static uint seed = 1;

static uint
rand(void)
{
  seed = seed * 1664525 + 1013904223;
  return seed;
}

int
randomread(struct inode *ip, char *dst, int n)
{
  int i;

  for(i = 0; i < n; i++) {
    // Ambil angka random antara 0 sampai 99
    dst[i] = rand() % 100;
  }

  return n;
}
