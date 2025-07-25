#include "types.h"
#include "stat.h"
#include "user.h"

int main() {
  printf(1, "shmtest starting...\n");   // <--- DEBUG 1

  char *shm = (char*) shmget(42);
  if (shm == (char*)-1) {
    printf(1, "Parent shmget failed\n");
    exit();
  }

  shm[0] = 'A';

  if (fork() == 0) {
    printf(1, "Child forked\n");        // <--- DEBUG 2

    char *shm2 = (char*) shmget(42);
    if (shm2 == (char*)-1) {
      printf(1, "Child shmget failed\n");
      exit();
    }

    printf(1, "Child reads: %c\n", shm2[0]);
    shm2[1] = 'B';
    shmrelease(42);
    exit();
  } else {
    wait();
    printf(1, "Parent reads: %c\n", shm[1]);
    shmrelease(42);
  }

  exit();
}
