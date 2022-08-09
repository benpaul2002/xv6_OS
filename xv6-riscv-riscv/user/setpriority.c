#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  if(argc < 2){
    fprintf(2, "usage: setpriority...\n");
    exit(1);
  }
  int arg1 = atoi(argv[1]);
  int arg2 = atoi(argv[2]);
  set_priority(arg1, arg2);
  exit(0);
}
