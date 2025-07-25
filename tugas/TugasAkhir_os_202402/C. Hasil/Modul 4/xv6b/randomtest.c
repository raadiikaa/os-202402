#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(void)
{
  char buf[8]; // atau lebih besar jika perlu
  int fd = open("/dev/random", 0);
  if(fd < 0){
    printf(1, "randomtest: cannot open /dev/random\n");
    exit();
  }

  int n = read(fd, buf, sizeof(buf));
  if(n < 0){
    printf(1, "randomtest: read failed\n");
    close(fd);
    exit();
  }

  for(int i = 0; i < n; i++)
    printf(1, "%d ", ((unsigned char)buf[i]) % 100); // atau cukup (unsigned char)buf[i]
  printf(1, "\n");

  close(fd);
  exit();
}
