#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  if(argc < 2){
    fprintf(2, "usage: trace...\n");
    exit(1);
  }
  char *args[20];
  for(int i=2; i<argc; i++) {
      args[i-2] = argv[i];
  }
  trace(atoi(argv[1]));
  exec(argv[2], args);
  exit(0);
}
