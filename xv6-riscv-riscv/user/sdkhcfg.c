#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  printf("Enter input: ");
  char *inp = (char *) malloc(100*sizeof(char));
  read(1, inp, 10);
  for(int i=0; i<10000; i++) {
    printf("%d\r", inp);
  }
  // /sleep(200);
  exit(0);
}
